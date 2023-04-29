//1.结构体空指针检查
//2.初始化顺序表
//3.重置顺序表
//4.打印顺序表
//5.结构体动态数组扩容
//6.检查顺序表容量
//7.位置合法性检查
//---遍历、增删改查---
//*涉及数据传递，可重载为内部和外部*
//8.在指定位置插入元素
//9.尾插
//10.头插
//11.在指定位置删除元素
//12.尾删
//13.头删
//14.修改指定位置元素
//15.查找指定元素位置


//#include<iostream>
#include<stdio.h>  /*perror, printf*/
#include<assert.h>  /*assert*/
#include<stdlib.h>  /*realloc*/

typedef int SeqListDataType, dt;
typedef struct SequenceList
{
	int* data;
	int length;
	int capacity;
}SeqList, * Seqlist;

//1.结构体空指针检查
int ListIsNull(SeqList*& L)
{
	if (L == NULL)
	{
		printf("空指针\n");
		return 1;
	}
	return 0;
}

//2.初始化顺序表
void InitSeqList(SeqList*& L)
{
	L = (SeqList*)malloc(sizeof(SeqList));
	if (ListIsNull(L))
	{
		return;
	}
	L->data = NULL;
	L->capacity = 0;
	L->length = 0;
}

//3.重置顺序表
void DestroySeqList(SeqList*& L)
{
	if (ListIsNull(L))
	{
		return;
	}
	free(L->data);
	InitSeqList(L);
}

//4.打印顺序表
void PrintSeqList(SeqList*& L)
{
	if (L == NULL || L->data == NULL)
	{
		printf("空指针\n");
		return;
	}
	if (L->length == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		for (int i = 0; i < L->length; i++)
		{
			printf("%d ", L->data[i]);
		}
	}
	printf("\n");
}

//5.结构体中动态数组扩容
void ResizeSeqList(SeqList*& L, int new_capacity)
{
	SeqListDataType* new_data = NULL;
	if (ListIsNull(L))//顺序表空指针检查
	{
		return;
	}

	if (new_capacity <= L->capacity) {
		return;  // 新的容量小于或等于当前容量，不进行任何操作
	}
	if (L->data == NULL)
	{
		new_data = (SeqListDataType*)malloc(new_capacity * sizeof(int));
	}
	else
	{
		new_data = (SeqListDataType*)realloc(L->data, new_capacity * sizeof(SeqListDataType));
		free(L->data);
	}
	// 内存分配失败，抛出异常
	if (new_data == NULL)
	{
		//throw std::bad_alloc();  
		printf("分配失败\n");
		return;
	}
	//扩容成功
	printf("扩容成功\n");
	L->data = new_data;
	L->capacity = new_capacity;
}

//6.检查顺序表容量
void CheckCapacity(SeqList*& L) {
	if (ListIsNull(L))
	{
		return;
	}
	if (L->capacity <= 0) {
		ResizeSeqList(L, 4);  // 当前容量小于等于0，扩容到4
	}
	else if (L->capacity <= L->length) {
		L->capacity = 2 * L->capacity;
		ResizeSeqList(L, L->capacity);  // 当前容量不足，扩容到原来的2倍
	}
}

//7.位置合法性检查
int IndexCheck(SeqList*& L, int index)
{
	int capacity = 0;
	if (ListIsNull(L))
	{
		return -1;
	}
	capacity = L->capacity;
	if (L->data == NULL)
	{
		printf("数组未初始化,将进行初始化\n");
	}


	if (L->length >= L->capacity)
	{
		if (capacity == 0)
		{
			printf("容量(%d)不足,将容量扩容为%d\n", L->capacity, 4);
		}
		else
		{
			printf("容量(%d)不足,将容量扩容为%d\n", L->capacity, 2 * L->capacity);
		}
		CheckCapacity(L);
	}
	if (index<0 || index>L->length)
	{
		printf("超出顺序表长度\n");
		return -2;
	}
	return 0;//通过，返回0
}


//---遍历、增删改查---
//8.指定位置插入元素
void InsertSeqList(SeqList*& L, int index, SeqListDataType val)//外部
{
	if (IndexCheck(L, index) != 0)
	{
		printf("插入失败\n");
		return;
	}
	IndexCheck(L, index);
	for (int i = L->length - 1; i >= index; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->length++;
	L->data[index] = val;

}
void InsertSeqList(SeqList*& L)//内部
{
	int position = 0;
	SeqListDataType val = 0;
	printf("输入插入位置(position):");
	scanf_s("%d", &position);
	if (IndexCheck(L, position - 1) != 0)
	{
		return;
	}

	printf("输入插入值(val):");
	scanf_s("%d", &val);
	InsertSeqList(L, position - 1, val);
}
//9.尾插
void InsertSeqList_Tail(SeqList*& L, SeqListDataType val)
{
	if (IndexCheck(L, L->length) != 0)
	{
		return;
	}
	InsertSeqList(L, L->length, val);
}
//10.头插
void InsertSeqList_Head(SeqList*& L, SeqListDataType val)
{
	if (IndexCheck(L, 0) != 0)
	{
		return;
	}
	InsertSeqList(L, 0, val);
}

//11.指定位置删除元素
void DeleteSeqList(SeqList*& L, int index)
{
	if (IndexCheck(L, index) != 0)
	{
		return;
	}
	for (int i = index; i < L->length; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--;
}
void DeleteSeqList(SeqList*& L)
{
	int position = 0;
	if (ListIsNull(L))
	{
		return;
	}

	printf("输入要删除的Position:");
	scanf_s("%d", &position);
	if (IndexCheck(L, position - 1) != 0)
	{
		return;
	}
	DeleteSeqList(L, position - 1);
}
//12.尾删
void DeleteSeqList_Tail(SeqList*& L)
{
	if (IndexCheck(L, L->length) != 0)
	{
		return;
	}
	L->length--;
}
//13.头删
void DeleteSeqList_Head(SeqList*& L)
{
	if (IndexCheck(L, 0) != 0)
	{
		return;
	}
	DeleteSeqList(L, 0);
}
//14.修改指定位置元素
void SetSeqList(SeqList*& L, int index, SeqListDataType val)
{
	if (IndexCheck(L, index) != 0)
	{
		return;
	}
	L->data[index] = val;
}
//15.查找指定元素位置
void FindSeqList(SeqList*& L, int index)
{
	if (IndexCheck(L, index) != 0)
	{
		return;
	}
	printf("data[%d]=%d\n", index, L->data[index]);
}

int main()
{
	SeqList* L1 /*= (SeqList*)malloc(sizeof(SeqList))*/;
	int a[5] = { 1,2,3,4,5 };
	int position = 3;
	InitSeqList(L1);

	//增Test
	printf("用数组模拟输入元素,插入位置为（尾部L1->length）a[5] = { 1,2,3,4,5 }\n");
	for (int i = 0; i < 5; i++)
	{
		InsertSeqList(L1, L1->length, a[i]);
	}
	PrintSeqList(L1);
	printf("\n");

	printf("在第3个(position=3)(Index=2)位置插入元素222\n");
	InsertSeqList(L1, position - 1, 222);
	PrintSeqList(L1);
	printf("\n");

	printf("尾插666\n");
	InsertSeqList_Tail(L1, 666);
	PrintSeqList(L1);
	printf("\n");

	printf("头插111\n");
	InsertSeqList_Head(L1, 111);
	PrintSeqList(L1);
	printf("\n");

	PrintSeqList(L1);
	printf("内部输入插入位置和元素\n");
	InsertSeqList(L1);
	PrintSeqList(L1);
	printf("\n");
	//删	Test
	printf("内部在指定位置删除元素\n");
	printf("%d-%d\n", 1, L1->length);
	DeleteSeqList(L1);
	PrintSeqList(L1);
	printf("\n");

	printf("在第3个(Index=2)位置删除元素\n");
	DeleteSeqList(L1, position - 1);
	PrintSeqList(L1);
	printf("\n");

	printf("头删\n");
	DeleteSeqList_Head(L1);
	PrintSeqList(L1);
	printf("\n");

	printf("尾删\n");
	DeleteSeqList_Tail(L1);
	PrintSeqList(L1);
	printf("\n");

	//改Test
	PrintSeqList(L1);
	printf("在第3个(position=3)(Index=2)位置修改元素为999\n");
	SetSeqList(L1, position - 1, 999);
	PrintSeqList(L1);
	printf("\n");

	//查Test
	PrintSeqList(L1);
	printf("在第3个(Index=2)位置查元素\n");
	FindSeqList(L1, position - 1);
	PrintSeqList(L1);
	printf("\n");

	return 0;
}


