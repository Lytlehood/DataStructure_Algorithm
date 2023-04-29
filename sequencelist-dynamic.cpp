//1.�ṹ���ָ����
//2.��ʼ��˳���
//3.����˳���
//4.��ӡ˳���
//5.�ṹ�嶯̬��������
//6.���˳�������
//7.λ�úϷ��Լ��
//---��������ɾ�Ĳ�---
//*�漰���ݴ��ݣ�������Ϊ�ڲ����ⲿ*
//8.��ָ��λ�ò���Ԫ��
//9.β��
//10.ͷ��
//11.��ָ��λ��ɾ��Ԫ��
//12.βɾ
//13.ͷɾ
//14.�޸�ָ��λ��Ԫ��
//15.����ָ��Ԫ��λ��


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

//1.�ṹ���ָ����
int ListIsNull(SeqList*& L)
{
	if (L == NULL)
	{
		printf("��ָ��\n");
		return 1;
	}
	return 0;
}

//2.��ʼ��˳���
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

//3.����˳���
void DestroySeqList(SeqList*& L)
{
	if (ListIsNull(L))
	{
		return;
	}
	free(L->data);
	InitSeqList(L);
}

//4.��ӡ˳���
void PrintSeqList(SeqList*& L)
{
	if (L == NULL || L->data == NULL)
	{
		printf("��ָ��\n");
		return;
	}
	if (L->length == 0)
	{
		printf("˳���Ϊ��\n");
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

//5.�ṹ���ж�̬��������
void ResizeSeqList(SeqList*& L, int new_capacity)
{
	SeqListDataType* new_data = NULL;
	if (ListIsNull(L))//˳����ָ����
	{
		return;
	}

	if (new_capacity <= L->capacity) {
		return;  // �µ�����С�ڻ���ڵ�ǰ�������������κβ���
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
	// �ڴ����ʧ�ܣ��׳��쳣
	if (new_data == NULL)
	{
		//throw std::bad_alloc();  
		printf("����ʧ��\n");
		return;
	}
	//���ݳɹ�
	printf("���ݳɹ�\n");
	L->data = new_data;
	L->capacity = new_capacity;
}

//6.���˳�������
void CheckCapacity(SeqList*& L) {
	if (ListIsNull(L))
	{
		return;
	}
	if (L->capacity <= 0) {
		ResizeSeqList(L, 4);  // ��ǰ����С�ڵ���0�����ݵ�4
	}
	else if (L->capacity <= L->length) {
		L->capacity = 2 * L->capacity;
		ResizeSeqList(L, L->capacity);  // ��ǰ�������㣬���ݵ�ԭ����2��
	}
}

//7.λ�úϷ��Լ��
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
		printf("����δ��ʼ��,�����г�ʼ��\n");
	}


	if (L->length >= L->capacity)
	{
		if (capacity == 0)
		{
			printf("����(%d)����,����������Ϊ%d\n", L->capacity, 4);
		}
		else
		{
			printf("����(%d)����,����������Ϊ%d\n", L->capacity, 2 * L->capacity);
		}
		CheckCapacity(L);
	}
	if (index<0 || index>L->length)
	{
		printf("����˳�����\n");
		return -2;
	}
	return 0;//ͨ��������0
}


//---��������ɾ�Ĳ�---
//8.ָ��λ�ò���Ԫ��
void InsertSeqList(SeqList*& L, int index, SeqListDataType val)//�ⲿ
{
	if (IndexCheck(L, index) != 0)
	{
		printf("����ʧ��\n");
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
void InsertSeqList(SeqList*& L)//�ڲ�
{
	int position = 0;
	SeqListDataType val = 0;
	printf("�������λ��(position):");
	scanf_s("%d", &position);
	if (IndexCheck(L, position - 1) != 0)
	{
		return;
	}

	printf("�������ֵ(val):");
	scanf_s("%d", &val);
	InsertSeqList(L, position - 1, val);
}
//9.β��
void InsertSeqList_Tail(SeqList*& L, SeqListDataType val)
{
	if (IndexCheck(L, L->length) != 0)
	{
		return;
	}
	InsertSeqList(L, L->length, val);
}
//10.ͷ��
void InsertSeqList_Head(SeqList*& L, SeqListDataType val)
{
	if (IndexCheck(L, 0) != 0)
	{
		return;
	}
	InsertSeqList(L, 0, val);
}

//11.ָ��λ��ɾ��Ԫ��
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

	printf("����Ҫɾ����Position:");
	scanf_s("%d", &position);
	if (IndexCheck(L, position - 1) != 0)
	{
		return;
	}
	DeleteSeqList(L, position - 1);
}
//12.βɾ
void DeleteSeqList_Tail(SeqList*& L)
{
	if (IndexCheck(L, L->length) != 0)
	{
		return;
	}
	L->length--;
}
//13.ͷɾ
void DeleteSeqList_Head(SeqList*& L)
{
	if (IndexCheck(L, 0) != 0)
	{
		return;
	}
	DeleteSeqList(L, 0);
}
//14.�޸�ָ��λ��Ԫ��
void SetSeqList(SeqList*& L, int index, SeqListDataType val)
{
	if (IndexCheck(L, index) != 0)
	{
		return;
	}
	L->data[index] = val;
}
//15.����ָ��Ԫ��λ��
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

	//��Test
	printf("������ģ������Ԫ��,����λ��Ϊ��β��L1->length��a[5] = { 1,2,3,4,5 }\n");
	for (int i = 0; i < 5; i++)
	{
		InsertSeqList(L1, L1->length, a[i]);
	}
	PrintSeqList(L1);
	printf("\n");

	printf("�ڵ�3��(position=3)(Index=2)λ�ò���Ԫ��222\n");
	InsertSeqList(L1, position - 1, 222);
	PrintSeqList(L1);
	printf("\n");

	printf("β��666\n");
	InsertSeqList_Tail(L1, 666);
	PrintSeqList(L1);
	printf("\n");

	printf("ͷ��111\n");
	InsertSeqList_Head(L1, 111);
	PrintSeqList(L1);
	printf("\n");

	PrintSeqList(L1);
	printf("�ڲ��������λ�ú�Ԫ��\n");
	InsertSeqList(L1);
	PrintSeqList(L1);
	printf("\n");
	//ɾ	Test
	printf("�ڲ���ָ��λ��ɾ��Ԫ��\n");
	printf("%d-%d\n", 1, L1->length);
	DeleteSeqList(L1);
	PrintSeqList(L1);
	printf("\n");

	printf("�ڵ�3��(Index=2)λ��ɾ��Ԫ��\n");
	DeleteSeqList(L1, position - 1);
	PrintSeqList(L1);
	printf("\n");

	printf("ͷɾ\n");
	DeleteSeqList_Head(L1);
	PrintSeqList(L1);
	printf("\n");

	printf("βɾ\n");
	DeleteSeqList_Tail(L1);
	PrintSeqList(L1);
	printf("\n");

	//��Test
	PrintSeqList(L1);
	printf("�ڵ�3��(position=3)(Index=2)λ���޸�Ԫ��Ϊ999\n");
	SetSeqList(L1, position - 1, 999);
	PrintSeqList(L1);
	printf("\n");

	//��Test
	PrintSeqList(L1);
	printf("�ڵ�3��(Index=2)λ�ò�Ԫ��\n");
	FindSeqList(L1, position - 1);
	PrintSeqList(L1);
	printf("\n");

	return 0;
}


