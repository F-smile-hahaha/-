using namespace std;
#include<fstream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList//建立结构体
{
	SLDateType* a;//动态开辟malloc指针
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps)//初始化
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)//增容
{
	if (ps->size == ps->capacity)
	{
		//确定新容量
		size_t newCapacity = ps->size == 0 ? 5 : 2 * ps->capacity;
		//开辟新空间，拷贝原有空间，释放原有空间
		SLDateType* b = (SLDateType*)malloc(newCapacity*sizeof(SLDateType));
		(SLDateType*) memcpy(b, ps->a, ps->size*sizeof(SLDateType));
		free(ps->a);
		ps->a = b;
		ps->capacity = newCapacity;
	}
}

void SeqListPrint(SeqList* ps)//打印
{
	for (size_t i = 0; i < ps->size; ++i)//遍历
	{
		printf(" %d ", ps->a[i]);
	}
	printf(" \n ");
}

void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	SeqListDestory(ps);//检查容量
	ps->a[ps->size] = x ;
	ps->size++;//更新顺序表中元素个数
}

void SeqListPushFront(SeqList* ps, SLDateType x)//头插
{
	SeqListDestory(ps);//检查容量
	//所有元素向后移动一个元素  遍历  从后往前
	for (size_t i = ps->size; i > 0; --i)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[0] = x;
	++ps->size;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)//删除  
{
	if (pos >= ps->size)//保证删除位置合法
		return;
	for (size_t i = pos + 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	--ps->size;
}


void SeqListPopFront(SeqList* ps)//头删
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)//尾删
{
	SeqListErase(ps, ps->size);
}

// 顺序表查找  遍历
size_t SeqListFind(SeqList* ps, SLDateType x)
{
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)//任意位置插入
{
	if (pos >= ps->size)//保障插入位置合法
		return;
	SeqListDestory(ps);//检查容量
	for (size_t i = ps->size; i > pos; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;//插入
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
	printf("头插100 ：\n");
	SeqListPushFront(&ps, 100);
	SeqListPrint(&ps);
	printf("位置3处插9 ：\n");
	SeqListInsert(&ps, 3, 9);
	SeqListPrint(&ps);
	printf("头删：\n");
	SeqListErase(&ps, 0);
	SeqListPrint(&ps);
	printf("查找100的位置：");
	printf(" %u \n", SeqListFind(&ps, 100));
}

int main( )
{
	test1( );
	system("pause");
	return 0;
}