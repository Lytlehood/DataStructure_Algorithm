//顺序表（Sequence List）数据结构
// 初始化顺序表
// 在指定位置插入元素
// 删除指定位置的元素
// 修改指定位置的元素
// 获取指定位置的元素
// 输出顺序表
#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX_SIZE 6//constexpr auto MAX_SIZE = 20;

typedef int SqldataType, type;
typedef struct SequenceList
{
	SqldataType data[MAX_SIZE];
	int length;//当前长度
}SeqList, * seqList;


// 初始化顺序表
void initSeqList(seqList& List)
{
	List = (seqList)malloc(sizeof(SeqList));
	if (List == NULL)
	{
		printf("初始化失败");
		return;

	}
	else
	{
		List->length = 0;
	}
}


// 在指定位置插入元素
int insertSeqListData(seqList& List, int index, int val)
{

	//插入失败
	if (index<0 || index >= MAX_SIZE || index>List->length || List->length >= MAX_SIZE)//0<index<Length<MAX_SIZE
	{
		//printf("插入失败\n");
		return 0;
	}
	for (int i = List->length - 1; i >= index; i--)
	{
		printf("Cover ");
		List->data[i + 1] = List->data[i];
	}
	List->length++;
	List->data[index] = val;
	//printf("插入成功\n");
	return 1;
}


// 删除指定位置的元素
int deleteSeqListData(seqList& List, int index)
{

	//删除失败
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("删除失败\n");
		return 0;
	}
	for (int i = index; i < List->length; i++)
	{
		List->data[i] = List->data[i + 1];
	}
	List->length--;
	//printf("删除成功\n");
	return 1;
}


// 修改指定位置的元素
int setSeqListData(seqList& List, int index, int val)
{

	//修改失败
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("修改失败,顺序表中不存在这个位置\n");
		return 0;
	}
	List->data[index] = val;
	return 1;
}


// 获取指定位置的元素
int getSeqListData(seqList& List, int index)
{

	//获取失败
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("获取失败,顺序表中不存在这个位置\n");
		return 0;
	}
	printf("第%d个元素：%d\n", index + 1, List->data[index]);
	//printf("获取成功\n");
	return 1;
}


//输出顺序表元素
void printSeqList(seqList& List)
{
	if (List->length == 0)
	{
		printf("空顺序表\n");
	}
	else
	{
		printf("共%d个元素\n", List->length);
		for (int i = 0; i < List->length; i++)
		{
			printf("第%d个数据的值为：%d\n", i + 1, List->data[i]);
		}
	}
}

int main()
{
	int val = 0;
	int nums = 0, index = 0;
	//创建顺序表
	seqList L1 = NULL;
	initSeqList(L1);
	printf("输入要插入元素数量：");
	scanf_s("%d", &nums);
	for (int i = 0; i < nums; i++)
	{

		scanf_s("%d", &val);
		insertSeqListData(L1, L1->length, val);//尾部插入:L1->length（index恒大于length没执行if更好）--正序,头部插入:0--倒序
	}
	printSeqList(L1);
	return 0;
}