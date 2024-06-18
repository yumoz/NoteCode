
/*
leetcode：160，参考链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
题目：相交链表
题目描述：找出两个链表相交的起始节点
*/



//参考链接：https://github.com/Shruthi15/codingground/blob/fd7be34850b5bd95bcf5df313c10daaaa0c5d11c/Intersection%20Point/main.c
#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct node SListNode;
struct node
{
	int val;
	struct node *next;
};

int getcount(struct node *head)
{
	struct node *current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int getIntersectionNode(int d, struct node *head1, struct node *head2)
{
	struct node *current1 = head1;
	struct node *current2 = head2;
	int i;
	for (i = 0; i < d; i++)
	{
		if (current1 == NULL)
		{
			return -1;

		}
		current1 = current1->next;
	}
	while (current1 != NULL && current2 != NULL)
	{
		if (current1 == current2)
		{
			return current1->val;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return -1;
}



void SListPrint(struct node *head)

{
	while (head != NULL)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL");
}



int getIntersection(struct node *head1, struct node *head2)
{
	int c1 = getcount(head1);
	int c2 = getcount(head2);

	int d;
	printf("\n %d", c1);
	printf(" \n %d", c2);
	if (c1 > c2)
	{
		d = c1 - c2;
		return getIntersectionNode(d, head1, head2);
	}
	else
	{
		d = c2 - c1;
		return getIntersectionNode(d, head2, head1);
	}

}


int main()
{

	struct node *newnode;
	struct node *head1 = (struct node*)malloc(sizeof(struct node));
	head1->val = 5;

	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	head2->val = 12;

	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = 9;

	head1->next = newnode;//5 9
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = 8;//5 9 8
	head1->next->next = newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = 10;
	head1->next->next->next = newnode;
	head2->next = newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = 20;
	head2->next->next = newnode;
	head2->next->next->next = NULL;
	printf("链表一：");
	SListPrint(head1);
	printf("\n链表二：");
	SListPrint(head2);

	printf("\nIntersection point is %d : ", getIntersection(head1, head2));

	/*SListNode*n1 = (SListNode*)malloc(sizeof(SListNode));
	n1->val = 1;
	SListNode*n2 = (SListNode*)malloc(sizeof(SListNode));
	n2->val = 2;
	SListNode*n3 = (SListNode*)malloc(sizeof(SListNode));
	n3->val = 3;
	SListNode*n4 = (SListNode*)malloc(sizeof(SListNode));
	n4->val = 4;


	SListNode*L5 = (SListNode*)malloc(sizeof(SListNode));
	L5->val = 1;
	SListNode*L6 = (SListNode*)malloc(sizeof(SListNode));
	L6->val = 3;
	SListNode*L7 = (SListNode*)malloc(sizeof(SListNode));
	L7->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;


	L5->next = L6;
	L6->next = L7;
	L7->next = NULL;
	printf("链表一：");
	SListPrint(n1);
	printf("\n链表二：");
	SListPrint(L5);*/

	//printf("\nIntersection point is %d : ", getIntersection(n1, L5));
	system("pause");
	return 0;

}


////此代码参考：https://github.com/thkuan/LeetCode/blob/0dae4eab02c72a91321c6ff77d43b4368ac144d9/160.%20Intersection%20of%20Two%20Linked%20Lists/intersection_of_two_linked_list.c
//#include <stdio.h>
//#include <stdlib.h>
//#include<windows.h>
//
//typedef struct list_node_s {
//	int val;
//	struct list_node_s *next;
//} SListNode;
//
//void insert_node(SListNode **root, int val) 
//{
//	SListNode *cur = *root;
//	SListNode *new = (SListNode *)malloc(sizeof(SListNode));
//	if (new != NULL) {
//		new->val = val;
//		new->next = NULL;
//		if (cur == NULL) {
//			*root = new;
//		}
//		else {
//			if (val < cur->val) {
//				new->next = *root;
//				*root = new;
//			}
//			else {
//				while (cur->next != NULL && val > cur->next->val) {
//					cur = cur->next;
//				}
//				new->next = cur->next;
//				cur->next = new;
//			}
//		}
//	}
//
//	return;
//}
//
//void traversal(SListNode *root) {
//	while (root != NULL) {
//		printf("%d->", root->val);
//		root = root->next;
//	}
//	printf("NULL\n");
//
//	return;
//}
//
//SListNode *getIntersectionNode(SListNode *headA, SListNode *headB) {
//	/* No intersection between two lists if either one is NULL */
//	if (headA == NULL || headB == NULL) return NULL;
//
//	SListNode *fast = NULL;
//	SListNode *slow = NULL;
//	SListNode *headA_end = headA;
//
//	/* Scan one list to reach its end to concatenate headB */
//	while (headA_end->next != NULL) {
//		headA_end = headA_end->next;
//	}
//	headA_end->next = headB;
//
//	fast = headA;
//	slow = headA;
//	while (fast != NULL && fast->next != NULL) {
//		slow = slow->next;
//		fast = fast->next->next;
//		/* There must be a cycle if an intersection exists */
//		if (fast == slow) {
//			slow = headA;
//			/* Find the intersection */
//			while (slow != fast) {
//				slow = slow->next;
//				fast = fast->next;
//			}
//			/* Recover headA list */
//			headA_end->next = NULL;
//			return slow;
//		}
//	}
//
//	/* Recover headA list */
//	headA_end->next = NULL;
//
//	return NULL;
//}
//
//int main()
//{
//	SListNode *root = NULL;
//	SListNode *root2 = NULL;
//	SListNode *cur = NULL;
//	SListNode *intersect = NULL;
//	insert_node(&root, 100);
//	insert_node(&root, 2);
//	insert_node(&root, 1);
//	insert_node(&root, 5);
//	insert_node(&root, 101);
//	insert_node(&root, 9);
//	traversal(root);
//	insert_node(&root2, 4);
//	insert_node(&root2, 3);
//	insert_node(&root2, 6);
//	traversal(root2);
//	intersect = getIntersectionNode(root, root2);
//	printf("getIntersectionNode(root, root2)? %s, intersect node has val = %d\n", \
//		(intersect != NULL) ? "TRUE" : "FALSE", \
//		(intersect != NULL) ? intersect->val : -1);
//
//	/* Create scenario */
//	cur = root2;
//	while (cur->next != NULL) {
//		cur = cur->next;
//	}
//	cur->next = root->next;
//	traversal(root);
//	traversal(root2);
//	intersect = getIntersectionNode(root, root2);
//	printf("getIntersectionNode(root, root2)? %s, intersect node has val = %d\n", \
//		(intersect != NULL) ? "TRUE" : "FALSE", \
//		(intersect != NULL) ? intersect->val : -1);
//	system("pause");
//	return 0;
//}



//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//typedef struct ListNode
//{
//	int val;
//	struct ListNode *next;
//}SListNode;
//
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	struct ListNode *l1 = headA;
//	struct ListNode *l2 = headB;
//
//	while (l1 != l2) {
//		if (l1) {
//			l1 = l1->next;
//		}
//		else {
//			l1 = headB;//headB:135
//		}
//		if (l2) {
//			l2 = l2->next;
//		}
//		else {
//			l2 = headA;//headA:1234
//		}
//	}
//	return l2;
//}
//
////打印这个链表
//void SListPrint(SListNode*phead)
//{
//	SListNode* cur = phead;
//	while (cur != NULL){
//		printf("%d-> ", cur->val);
//		cur = cur->next;//前一个结构体成员next存放下一个结构体指针
//	}
//	printf("NULL\n");
//}
//
//
//void test()
//{
//	struct ListNode*n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->val = 1;
//	struct ListNode*n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n2->val = 2;
//	struct ListNode*n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n3->val = 3;
//	struct ListNode*n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n4->val = 4;
//
//
//	struct ListNode*L5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	L5->val = 1;
//	struct ListNode*L6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	L6->val = 3;
//	struct ListNode*L7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	L7->val = 5;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//
//
//	L5->next = L6;
//	L6->next = L7;
//	L7->next = NULL;
//	printf("链表一：\n");
//	SListPrint(n1);
//	printf("链表二：\n");
//	SListPrint(L5);
//
//	SListNode * ret = getIntersectionNode(n1, L5);
//	printf("合并后：%d\n",ret);
//	
//
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}