/*

Leetcode:203
题目：移除链表元素

题目描述：删除链表中等于给定值得所有节点

*/

#include<stdio.h>
#include<windows.h>
#include <assert.h>

//定义一个单链表
struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while ((fast) && (fast->next)){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


void ListPrint(struct ListNode *phead)
{
	assert(phead);
	struct ListNode *cur = phead;
	while (cur != NULL){
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");

}

void testList()
{
	struct ListNode*n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode*n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode*n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode*n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;
	struct ListNode*n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 5;
	struct ListNode*n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 6;
	struct ListNode*n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	struct ListNode *Find = middleNode(n1);
	ListPrint(Find);
}
int main()
{
	testList();
	system("pause");
	return 0;
}