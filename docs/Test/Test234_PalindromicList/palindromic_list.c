//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}SListNode;

struct ListNode *ReverseList(struct ListNode *a)           //反转链表，后面需要用到。具体掌握可练习#206题
{
	struct ListNode *p, *r;
	p = a, r = NULL;
	while (a)
	{
		a = a->next;
		p->next = r;
		r = p;
		p = a;
	}
	return r;
}

bool isPalindrome(struct ListNode* head)
{
	struct ListNode *fast = head, *slow = head;              //申请快慢指针指向head
	if (head == NULL || head->next == NULL)    return true;    //空或只有1个结点为true

	if (fast->next->next == NULL)                          //由于后面用到fast->next->next回引起溢出索性直接判断是否为两个结点并判定
	{
		if (slow->next->val != slow->val)
			return false;
		else 
			return true;
	}

	while (fast->next != NULL&&fast->next->next != NULL)     //若链表有偶数个结点则fast->next==NULL
	{                                               //若链表有奇数个结点则fast->next->next==NULL
		slow = slow->next;
		fast = fast->next->next;
	}

	slow = ReverseList(slow->next);                          //上面判定结束后slow的下一个结点一定指向最中间（长度为奇数时）
	while (slow != NULL)                                   //或者指向len/2处（长度为偶数时）
	{                                                   //所以从slow的下一个结点开始反转并和头结点head一一比较
		if (slow->val != head->val)
			return false;
		slow = slow->next;
		head = head->next;
	}
	return true;
}

//另一种解法
//bool isPalindrome(struct ListNode* head){
//	if (head == NULL || head->next == NULL){//判断是否为空，或者只有一个值，如果是那么仍然是回文
//		return true;
//	}
//	struct ListNode* mid1 = head;
//	struct ListNode* tmp = head->next;
//	while (tmp && tmp->next != NULL){
//		mid1 = mid1->next;
//		tmp = tmp->next->next;
//	}
//	struct ListNode* mid2 = mid1->next;
//	struct ListNode* cur = mid2->next;
//	while (cur != NULL){
//		mid2->next = cur->next;
//		cur->next = mid1->next;
//		mid1->next = cur;
//		cur = mid2->next;
//	}
//	mid2 = mid1->next;
//	cur = head;
//	while (mid2 != NULL){
//		if (cur->val != mid2->val){
//			return false;
//		}
//		cur = cur->next;
//		mid2 = mid2->next;
//	}
//	return true;
//}

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
	struct ListNode*n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 3;
	struct ListNode*n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 2;
	struct ListNode*n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	printf("是否为回文数：\n");
	//isPalindrome(n1)
	if (isPalindrome(n1) == true)
		printf("是\n");
	else
		printf("不是回文\n");

}

int main()
{
	test();
	system("pause");
	return 0;
}