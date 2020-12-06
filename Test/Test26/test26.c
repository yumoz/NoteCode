//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<windows.h>

int removeDuplicates(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int i = 0, j = i + 1;
	while (j < numsSize){
		if (nums[i] == nums[j]){
			j++;
		}
		else{
			i++;
			nums[i] = nums[j];
			j++;
		}
	}
	return i + 1;
}

int main()
{
	int array[] = { 1, 2, 2, 3, 3, 4, 5 };//注意此题要求此数组为排序数组
	int len = sizeof(array) / sizeof(array[0]);
	int ret = removeDuplicates(array, len);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//提高：
//如果不是排序数组的话，应该怎么做？