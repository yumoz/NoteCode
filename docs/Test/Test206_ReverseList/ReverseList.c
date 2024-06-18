#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
}SListNode;

SListNode* ReverseList(SListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	SListNode *n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2){
		//反转
		n2->next = n1;
		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;
}

SListNode * BuySListNode(SListDataType x)
{
	//插入节点
	SListNode * newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
//打印这个链表
void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur != NULL){
		printf("%d-> ", cur->data);
		cur = cur->next;//前一个结构体成员next存放下一个结构体指针
	}
	printf("NULL\n");
}



//尾部插入数据
void SListPushBack(SListNode** pphead, SListDataType x)//尾插
{
	SListNode* newNode = BuySListNode(x);//动态申请一个新节点
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//遍历找尾巴
		SListNode* tail = *pphead;
		while (tail->next != NULL)//访问空指针，出问题  已经修改
		{
			tail = tail->next;//形象理解tail在移动，尾部节点tail为空
			// 切勿tail ++；
		}
		tail->next = newNode;
	}
}
void testSList()
{
	//SListNode* phead = NULL;
	SListNode * pList = NULL;
	printf("原始链表：\n");
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPrint(pList);

	printf("逆置后的链表：\n");
	SListNode* ret = ReverseList(pList);//逆置链表
	SListPrint(ret);//打印链表

}
int main()
{
	testSList();//测试程序
	system("pause");
	return 0;
}