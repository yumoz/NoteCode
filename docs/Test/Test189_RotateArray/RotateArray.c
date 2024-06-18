/*
Leetcode:189
����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����K�ǷǸ���

*/
#include<stdio.h>
#include<windows.h>

void reverse(int *nums, int start, int end)
{
	int temp;
	while (start < end){
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}


void  rotate(int *nums, int numsSize, int k)
{
	k %= numsSize;//�����ƶ���nums[0]��λ��
	reverse(nums, 0, numsSize - 1);//ȫ����������
	reverse(nums, 0, k - 1);//����ǰk-1λ����Ԫ��
	reverse(nums, k, numsSize - 1);//����ʣ��Ԫ��
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	rotate(array, len, 3);//��������ƶ�ĳЩλ
	for (int i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}

	system("pause");
	return 0;
}