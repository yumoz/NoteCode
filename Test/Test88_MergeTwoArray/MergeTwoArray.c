#include<stdio.h>
#include<windows.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//end1:nums1的末尾
	//end2:nums2的末尾
	//end:合并之后整个数组的末尾
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{   //选出尾最大的元素，存放到整个数组的末尾
		//每存放一个元素，尾向前移动一个位置
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//剩余元素依次向末尾存放
	while (end1 >= 0)
	{
		nums1[end--] = nums1[end1--];
	}

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
int main()
{
	int array1[] = { 7, 8, 9 };
	int len1 = sizeof(array1) / sizeof(array1[0]);
	int array2[] = { 1, 5, 6,7,8,9 };
	int len2 = sizeof(array2) / sizeof(array2[0]);

	merge(array1, len1, 3, array2, len2, 6);

	for (int i = 0; i < len1 + len2; i++){
		printf("%d ", array1[i]);
	}
	system("pause");
	return 0;
}