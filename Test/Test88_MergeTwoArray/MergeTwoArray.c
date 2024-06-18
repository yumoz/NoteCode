/*
LeetCode：88
题目：合并两个有序数组
题目描述：给两个有序数组nums1和nums2，请将nums2合并到nums1中，使nums1成为一个有序数组。

说明：

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

 示例：

 输入：
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 输出：[1,2,2,3,5,6]
  
  提示：

  -10^9 <= nums1[i], nums2[i] <= 10^9
  nums1.length == m + n
  nums2.length == n

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/merge-sorted-array
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
说明：因为合并的是两个排序数组，所以只需要对两个数组中最后一个元素进行比较，选取较大的元素放在行的数组（nums1中）
存放，之后再次进行比较，依次选取次大的数，存放在nums1中，因为nums1中存放是从后向前的，所以不会存在覆盖的问题
*/
#include<stdio.h>
#include<windows.h>
//合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;//nums1数组末尾元素
	int end2 = n - 1;//nums2数组末尾元素
	int end = m + n - 1;//合并后大小

	while (end1 >= 0 && end2 >= 0)//判断两个数组是否有元素
	{   
		if (nums1[end1] > nums2[end2])//判断两个数组中，末尾元素哪个大,将大的数放在后面（end位置）
		{
			nums1[end] = nums1[end1];//如果nums1末尾元素大，那么将nums1末尾的数放在合并后末尾的位置
			--end;
			--end1;;
		}
		else
		{
			nums1[end] = nums2[end2];//否则，同理执行上述步骤
			--end;
			--end2;
		}
	}
	//剩余元素依次向末尾存放
	while (end1 >= 0)
	{
		nums1[end] = nums1[end1];
		--end;
		--end1;
	}

	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		--end;
		--end2;
	}
}
int main()
{
	int array1[] = { 0, 8, 9 };
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