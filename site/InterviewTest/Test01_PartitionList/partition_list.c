#include <stdio.h>
#include<windows.h>

typedef struct ListNode
{
	int val;
	struct ListNode*next;
}SListNode;

//struct ListNode*partition(struct ListNode* head, int x)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode *lessHead, *lessTail, *greaterHead, *greaterTail;
//	//���������ͷ
//	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		//С��x��β�嵽lessTail
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = lessTail->next;
//		}
//		//���ڵ���x��β�嵽greaterTail
//		else
//		{
//			greaterTail->next = cur;
//			greaterTail = greaterTail->next;
//		}
//		cur = cur->next;
//	}
//	//������������
//	lessTail->next = greaterHead->next;
//	greaterTail->next = NULL;
//	//��ȡ��ͷ
//	head = lessHead->next;
//	free(lessHead);//�ͷŵ����õ�����
//	free(greaterHead);
//
//	return head;
//}

struct ListNode* partition(struct ListNode* head, int x){
	if (!head || !head->next)  return head;
	struct ListNode* h1 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t1 = h1;
	struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t2 = h2;
	t1->next = NULL; t2->next = NULL;
	while (head){
		if (head->val < x){
			t1->next = head;
			t1 = t1->next;
		}
		else{
			t2->next = head;
			t2 = t2->next;
		}
		head = head->next;
	}
	t1->next = h2->next;
	t2->next = NULL;
	return h1->next;
}
//��ӡ����
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

	//�Խ���������
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 5;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 3;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 2;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	printf("ԭʼ����");
	ListPrint(n1);
	printf("\n");

	//���Ժ���
	int Key = 3;
	int ret = 0;
	struct ListNode  * res = partition(n1, Key);
	//��ӡ�����������
	printf("�ָ�����");
	ListPrint(res);

	printf("\n");

}
int main()
{
	test();
	printf("hello Interview test\n");
	system("pause");
	return 0;
}