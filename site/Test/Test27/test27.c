/*
	题目描述：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

	不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

	元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/remove-element
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
#include<stdio.h>
#include<windows.h>

//int removeElement(int* nums, int numsSize, int val){
//	//assert(nums);
//	// if(numsSize==0 || nums==NULL){
//	//     return -1;
//	// }
//	int j = 0;
//	for (int i = 0; i < numsSize; i++){
//		if (nums[i] != val){
//			nums[j] = nums[i];
//			j++;
//		}
//	}
//	return j;
//}
int removeElement(int* nums, int numsSize, int val){
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		//如果数组元素不是val
		if (nums[src] != val){
			nums[dst++] = nums[src++];
		}
		else{
			//数组元素是val的话
			src++;
		}
	}
	return dst;
}
int main()
{
	int array[] = {0,1,2,1,0};
	int len = sizeof(array) / sizeof(array[0]);
	printf("数组中还有%d个元素\n", removeElement(array, len, 2));// 移除 2 所剩的数组中还有几个元素
	system("pause");
	return 0;
}