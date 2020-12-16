/*
LeetCode:21
题目：合并两个有序链表
题目描述：将两个升序链表合并成一个升序链表并返回。

例子：
链表一：1234
链表二：135
合并后：1123345
*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}SListNode;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


//struct ListNode* mergeTwoLists(struct ListNode* List1, struct ListNode* List2){
//	struct ListNode *pa = List1;
//	struct ListNode *pb = List2;
//	if (!pa)
//		return List2;
//	else if (!pb)
//		return List1;
//	else
//	{
//		if (pa->val <= pb->val)//如果List1首元素小于或等于List2，那么返回的是List1，否则返回List2
//		{
//			struct ListNode *pc = List1;
//			pa = pa->next;
//			while (pa && pb)
//			{
//				if (pa->val <= pb->val)
//				{
//					pc->next = pa;
//					pc = pa;
//					pa = pa->next;
//				}
//				else
//				{
//					pc->next = pb;
//					pc = pb;
//					pb = pb->next;
//				}
//			}
//			pc->next = pa ? pa : pb;//如果pa为空，则返回pb
//			return List1;
//		}
//		else
//		{
//			struct ListNode *pc = List2;
//			pb = pb->next;
//			while (pa && pb)
//			{
//				if (pa->val <= pb->val)
//				{
//					pc->next = pa;
//					pc = pa;
//					pa = pa->next;
//				}
//				else
//				{
//					pc->next = pb;
//					pc = pb;
//					pb = pb->next;
//				}
//			}
//			pc->next = pa ? pa : pb;
//			return List2;
//		}
//	}
//
//}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	SListNode* head = NULL, *tail = NULL;
	//创建空链表
	head = tail = (SListNode*)malloc(sizeof(SListNode));
	tail->next = NULL;
	while (l1 && l2)
	{
		// 取小的进行尾插
		if (l1->val < l2->val)
		{
			tail->next = l1;
			tail = tail->next;

			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = tail->next;

			l2 = l2->next;
		}
	}
	//剩余元素直接拼接
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;

	SListNode* list = head->next;
	free(head);
	return list;
}
//打印这个链表
void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur != NULL){
		printf("%d-> ", cur->val);
		cur = cur->next;//前一个结构体成员next存放下一个结构体指针
	}
	printf("NULL\n");
}


void test()
{
	struct ListNode*n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode*n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode*n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode*n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;


	struct ListNode*L5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	L5->val = 1;
	struct ListNode*L6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	L6->val = 3;
	struct ListNode*L7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	L7->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;


	L5->next = L6;
	L6->next = L7;
	L7->next = NULL;
	printf("链表一：\n");
	SListPrint(n1);
	printf("链表二：\n");
	SListPrint(L5);

	SListNode * ret = mergeTwoLists(n1, L5);
	printf("合并后：\n");
	SListPrint(ret);

}

int main()
{
	test();
	system("pause");
	return 0;
}