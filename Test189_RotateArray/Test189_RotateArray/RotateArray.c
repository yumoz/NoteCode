/* 
题目描述：给定一个数组，将数组中的猿猴向后移动k个位置，其中k不是负数

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
	k %= numsSize;//计算移动后nums[0]的位置
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	rotate(array, len, 3);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	
	system("pause");
	return 0;
}