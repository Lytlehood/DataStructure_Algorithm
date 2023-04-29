//˳���Sequence List�����ݽṹ
// ��ʼ��˳���
// ��ָ��λ�ò���Ԫ��
// ɾ��ָ��λ�õ�Ԫ��
// �޸�ָ��λ�õ�Ԫ��
// ��ȡָ��λ�õ�Ԫ��
// ���˳���
#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX_SIZE 6//constexpr auto MAX_SIZE = 20;

typedef int SqldataType, type;
typedef struct SequenceList
{
	SqldataType data[MAX_SIZE];
	int length;//��ǰ����
}SeqList, * seqList;


// ��ʼ��˳���
void initSeqList(seqList& List)
{
	List = (seqList)malloc(sizeof(SeqList));
	if (List == NULL)
	{
		printf("��ʼ��ʧ��");
		return;

	}
	else
	{
		List->length = 0;
	}
}


// ��ָ��λ�ò���Ԫ��
int insertSeqListData(seqList& List, int index, int val)
{

	//����ʧ��
	if (index<0 || index >= MAX_SIZE || index>List->length || List->length >= MAX_SIZE)//0<index<Length<MAX_SIZE
	{
		//printf("����ʧ��\n");
		return 0;
	}
	for (int i = List->length - 1; i >= index; i--)
	{
		printf("Cover ");
		List->data[i + 1] = List->data[i];
	}
	List->length++;
	List->data[index] = val;
	//printf("����ɹ�\n");
	return 1;
}


// ɾ��ָ��λ�õ�Ԫ��
int deleteSeqListData(seqList& List, int index)
{

	//ɾ��ʧ��
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("ɾ��ʧ��\n");
		return 0;
	}
	for (int i = index; i < List->length; i++)
	{
		List->data[i] = List->data[i + 1];
	}
	List->length--;
	//printf("ɾ���ɹ�\n");
	return 1;
}


// �޸�ָ��λ�õ�Ԫ��
int setSeqListData(seqList& List, int index, int val)
{

	//�޸�ʧ��
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("�޸�ʧ��,˳����в��������λ��\n");
		return 0;
	}
	List->data[index] = val;
	return 1;
}


// ��ȡָ��λ�õ�Ԫ��
int getSeqListData(seqList& List, int index)
{

	//��ȡʧ��
	if (index < 0 || index >= List->length)//0<index<Length
	{
		//printf("��ȡʧ��,˳����в��������λ��\n");
		return 0;
	}
	printf("��%d��Ԫ�أ�%d\n", index + 1, List->data[index]);
	//printf("��ȡ�ɹ�\n");
	return 1;
}


//���˳���Ԫ��
void printSeqList(seqList& List)
{
	if (List->length == 0)
	{
		printf("��˳���\n");
	}
	else
	{
		printf("��%d��Ԫ��\n", List->length);
		for (int i = 0; i < List->length; i++)
		{
			printf("��%d�����ݵ�ֵΪ��%d\n", i + 1, List->data[i]);
		}
	}
}

int main()
{
	int val = 0;
	int nums = 0, index = 0;
	//����˳���
	seqList L1 = NULL;
	initSeqList(L1);
	printf("����Ҫ����Ԫ��������");
	scanf_s("%d", &nums);
	for (int i = 0; i < nums; i++)
	{

		scanf_s("%d", &val);
		insertSeqListData(L1, L1->length, val);//β������:L1->length��index�����lengthûִ��if���ã�--����,ͷ������:0--����
	}
	printSeqList(L1);
	return 0;
}