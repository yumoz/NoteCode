/*
LeetCode:21
��Ŀ���ϲ�������������
��Ŀ��������������������ϲ���һ�������������ء�

���ӣ�
����һ��1234
�������135
�ϲ���1123345
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
//		if (pa->val <= pb->val)//���List1��Ԫ��С�ڻ����List2����ô���ص���List1�����򷵻�List2
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
//			pc->next = pa ? pa : pb;//���paΪ�գ��򷵻�pb
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
	//����������
	head = tail = (SListNode*)malloc(sizeof(SListNode));
	tail->next = NULL;
	while (l1 && l2)
	{
		// ȡС�Ľ���β��
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
	//ʣ��Ԫ��ֱ��ƴ��
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;

	SListNode* list = head->next;
	free(head);
	return list;
}
//��ӡ�������
void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur != NULL){
		printf("%d-> ", cur->val);
		cur = cur->next;//ǰһ���ṹ���Աnext�����һ���ṹ��ָ��
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
	printf("����һ��\n");
	SListPrint(n1);
	printf("�������\n");
	SListPrint(L5);

	SListNode * ret = mergeTwoLists(n1, L5);
	printf("�ϲ���\n");
	SListPrint(ret);

}

int main()
{
	test();
	system("pause");
	return 0;
}