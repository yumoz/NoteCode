
/*
��ָoffer��22
��Ŀ�����������е�����K���ڵ�
��Ŀ����������һ����������������е�����K���ڵ㡣

���磺 123456   ���ص�����3���ڵ� ��Ϊ4 5 6
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
	if (head == NULL || k == 0){//�ж������Ƿ�Ϊ�գ������ڵ��Ƿ�Ϊ��
		return 0;
	}

	struct ListNode* pNode = head;//����һ��ָ������ͷ��ָ��
	//����
	for (int i = 0; i < k - 1; ++i){
		if (pNode->next != NULL)//�ж�ָ��ָ���Ƿ�Ϊ��
		{
			pNode = pNode->next;//ָ����һλ
		}
		else{//������ֻ��һ��ֵ����һλָ��Ϊ��ʱ
			return NULL;
		}
	}

	while (pNode->next != NULL){
		pNode = pNode->next;
		head = head->next;
	}
	return head;
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

	printf("ԭʼ����");
	ListPrint(n1);
	printf("\n");

	//���Ժ���
	int Key = 1;
	printf("������%d����",Key);
	int ret = 0;
	struct ListNode  * res = getKthFromEnd(n1, Key);
	//��ӡ���ú������
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