//题目：删除排序数组中重复的元素
//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<windows.h>

//没有借助新数组，原数组直接转化
//int removeDuplicates(int* nums, int numsSize){
//	if (nums == NULL || numsSize == 0){
//		return 0;
//	}
//	int prev = 0, cur = prev + 1; //排序数组，相邻元素比较
//	while (cur < numsSize){
//		if (nums[prev] == nums[cur]){
//			cur++;
//		}
//		else{//不相等时，将prev给dst
//			prev++;
//			nums[prev] = nums[cur];
//			cur++;
//		}
//	}
//	//nums[dst++] = nums[prev];//此时先加加，后赋值
//	//nums[dst]=nums[prev]
//	//dst++;
//	//prev++;
//	return prev + 1;
//}

int removeDuplicates(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int prev = 0, cur = 1, dst = 0; //排序数组，相邻元素比较
	while (cur < numsSize){
		if (nums[prev] != nums[cur]){
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;
		}
		else{
			prev++;
			cur++;
		}
	}
	//nums[dst++] = nums[prev];//此时先加加，后赋值
	nums[dst] = nums[prev];
	dst++;
	prev++;
	return dst;
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