#include <stdio.h>

#include<windows.h>



// Definition for singly-linked list.*/
struct ListNode 
{
     int val;
    struct ListNode *next;
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* reversePrint(struct ListNode* head, int* returnSize)
{
	if (head == NULL){
		*returnSize = 0;
		return malloc(sizeof(int) * 10000);
	}
	int *ans = reversePrint(head->next, returnSize);
	ans[(*returnSize)++] = head->val;
	return ans;
}

//打印链表
void ListPrint(struct ListNode *head)
{
	struct ListNode *cur = head;
	while (cur != NULL){
		printf("%3d", cur->val);
		cur = cur->next;
	}
}


void test()
{

	//自建简易链表
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 6;

	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 5;

	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 4;

	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 3;

	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 2;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	printf("原始链表：");
	ListPrint(n1);
	printf("\n");

	//测试函数
	printf("逆置链表：");
	int ret = 0;
	int  * res = reversePrint(n1,&ret);
	//打印逆置后的链表
	for (int i = 0; i < ret; ++i){
		printf("%3d ", res[i]);
	}
	
	printf("\n");

}
int main()
{
	test();
	printf("hello Sword to offer\n");
	system("pause");
	return 0;
}