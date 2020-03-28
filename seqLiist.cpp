using namespace std;
#include<fstream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList//�����ṹ��
{
	SLDateType* a;//��̬����mallocָ��
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps)//��ʼ��
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)//����
{
	if (ps->size == ps->capacity)
	{
		//ȷ��������
		size_t newCapacity = ps->size == 0 ? 5 : 2 * ps->capacity;
		//�����¿ռ䣬����ԭ�пռ䣬�ͷ�ԭ�пռ�
		SLDateType* b = (SLDateType*)malloc(newCapacity*sizeof(SLDateType));
		(SLDateType*) memcpy(b, ps->a, ps->size*sizeof(SLDateType));
		free(ps->a);
		ps->a = b;
		ps->capacity = newCapacity;
	}
}

void SeqListPrint(SeqList* ps)//��ӡ
{
	for (size_t i = 0; i < ps->size; ++i)//����
	{
		printf(" %d ", ps->a[i]);
	}
	printf(" \n ");
}

void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	SeqListDestory(ps);//�������
	ps->a[ps->size] = x ;
	ps->size++;//����˳�����Ԫ�ظ���
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ��
{
	SeqListDestory(ps);//�������
	//����Ԫ������ƶ�һ��Ԫ��  ����  �Ӻ���ǰ
	for (size_t i = ps->size; i > 0; --i)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[0] = x;
	++ps->size;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)//ɾ��  
{
	if (pos >= ps->size)//��֤ɾ��λ�úϷ�
		return;
	for (size_t i = pos + 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	--ps->size;
}


void SeqListPopFront(SeqList* ps)//ͷɾ
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)//βɾ
{
	SeqListErase(ps, ps->size);
}

// ˳������  ����
size_t SeqListFind(SeqList* ps, SLDateType x)
{
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)//����λ�ò���
{
	if (pos >= ps->size)//���ϲ���λ�úϷ�
		return;
	SeqListDestory(ps);//�������
	for (size_t i = ps->size; i > pos; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;//����
	++ps->size;
}

void test1()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPushBack(&ps, 6);
	SeqListPrint(&ps);
	printf("ͷ��100 ��\n");
	SeqListPushFront(&ps, 100);
	SeqListPrint(&ps);
	printf("λ��3����9 ��\n");
	SeqListInsert(&ps, 3, 9);
	SeqListPrint(&ps);
	printf("ͷɾ��\n");
	SeqListErase(&ps, 0);
	SeqListPrint(&ps);
	printf("����100��λ�ã�");
	printf(" %u \n", SeqListFind(&ps, 100));
}

int main( )
{
	test1( );
	system("pause");
	return 0;
}