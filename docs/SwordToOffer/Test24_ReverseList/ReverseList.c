#include<stdio.h>
#include<windows.h>

//typedef struct ListNode Node;

struct ListNode
{
	int val;
	struct ListNode *next;
};

//����һ
struct ListNode* ReverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *cur = head;
	struct ListNode *nexthead = cur->next;
	cur->next = NULL;
	//nexthead = NULL;
	struct ListNode*temp;
	while (nexthead != NULL){
		temp = nexthead->next;
		nexthead->next = cur->next;
		cur->next = nexthead;
		nexthead = temp;
	}
	return cur;
}


////������
// struct ListNode* ReverseList(struct ListNode* head)
// {
//     if (head == NULL || head->next == NULL)//�ж�ͷָ���Ƿ�Ϊ�գ���ֻ��һ��Ԫ��
// 		return head;
// 	struct ListNode *n1 = NULL, *n2 = head, *n3 = head->next;
// 	while (n2){
// 		//��ת
// 		n2->next = n1;
// 		//����
// 		n1 = n2;
// 		n2 = n3;
// 		if (n3)
// 		{
// 			n3 = n3->next;
// 		}
// 	}
// 	return n1;
// }

//��ӡ����
void ListPrint(struct ListNode *head)
{
	struct ListNode *cur = head;
	while (cur != NULL){
		printf("%3d", cur->val);
		cur = cur->next;
	}
}

//���Գ���
void test()
{

	//�Խ���������
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

	printf("ԭʼ����\n");
	ListPrint(n1);
	printf("\n");

	//���Ժ���
	struct ListNode * ret = ReverseList(n1);
	ListPrint(ret);
	printf("\n");
}

int main()
{
	test();
	system("pause");
	return 0;
}