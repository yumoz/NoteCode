
/*
剑指offer：22
题目：返回链表中倒数第K个节点
题目描述：输入一个链表，输出该链表中倒数第K个节点。

例如： 123456   返回倒数第3个节点 答案为4 5 6
*/
#include <stdio.h>
#include<windows.h>

// Definition for singly-linked list.*/
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode*getKthFromEnd(struct ListNode*head, int k)
{
	if (head == NULL || k == 0){//判断链表是否为空，倒数节点是否为空
		return 0;
	}

	struct ListNode* pNode = head;//定义一个指向链表头的指针
	//遍历
	for (int i = 0; i < k - 1; ++i){
		if (pNode->next != NULL)//判断指针指向是否为空
		{
			pNode = pNode->next;//指向下一位
		}
		else{//链表中只有一个值，下一位指向为空时
			return NULL;
		}
	}

	while (pNode->next != NULL){
		pNode = pNode->next;
		head = head->next;
	}
	return head;
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
	int Key = 1;
	printf("倒数第%d链表：",Key);
	int ret = 0;
	struct ListNode  * res = getKthFromEnd(n1, Key);
	//打印逆置后的链表
	ListPrint(res);

	printf("\n");

}
int main()
{
	test();
	printf("hello Sword to offer 22\n");
	system("pause");
	return 0;
}