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
//边界问题 0 末尾
//全部删除之后返回NULL 这个是重难点

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode * p = head, *prev = head;
//	if (head == NULL)//头指针为空，即链表为空
//		return head;
//	while (p->next)//当链表不空，即链表指向的下一个节点不空时
//	{		
//		if (p->val == val)
//		{//找到了
//			struct ListNode * q = p->next;//将下一个元素给上一个元素
//			p->val = q->val;
//			p->next = q->next;
//			free(q);
//		}
//		else
//		{
//			prev = p;
//			p = p->next;
//		}
//	} 
//	
//	if (p->val == val)
//	{
//		if (p == head){
//			free(p);
//			return NULL;
//		}//链表所有元素全部相等
//		prev->next = NULL;
//		free(p);//末尾
//	}
//	return head;
//}


struct ListNode*removeElements(struct ListNode*head, int val)
{
	struct ListNode*prev = NULL, *cur = head;
	while (cur){
		if (cur->val == val)
		{
			if (cur == head){
				head = cur->next;
				free(cur);
				cur = head;
			}
			else{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else{
			prev = cur;
			cur = cur->next;
		}		
	}
	return head;
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

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	struct ListNode *head = removeElements(n1, 3);
	ListPrint(n1);
}
int main()
{
	testList();	
	system("pause");
	return 0;
}