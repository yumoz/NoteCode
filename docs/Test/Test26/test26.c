//��Ŀ��ɾ�������������ظ���Ԫ��
//����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

#include<stdio.h>
#include<windows.h>

//û�н��������飬ԭ����ֱ��ת��
//int removeDuplicates(int* nums, int numsSize){
//	if (nums == NULL || numsSize == 0){
//		return 0;
//	}
//	int prev = 0, cur = prev + 1; //�������飬����Ԫ�رȽ�
//	while (cur < numsSize){
//		if (nums[prev] == nums[cur]){
//			cur++;
//		}
//		else{//�����ʱ����prev��dst
//			prev++;
//			nums[prev] = nums[cur];
//			cur++;
//		}
//	}
//	//nums[dst++] = nums[prev];//��ʱ�ȼӼӣ���ֵ
//	//nums[dst]=nums[prev]
//	//dst++;
//	//prev++;
//	return prev + 1;
//}

int removeDuplicates(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int prev = 0, cur = 1, dst = 0; //�������飬����Ԫ�رȽ�
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
	//nums[dst++] = nums[prev];//��ʱ�ȼӼӣ���ֵ
	nums[dst] = nums[prev];
	dst++;
	prev++;
	return dst;
}

int main()
{
	int array[] = { 1, 2, 2, 3, 3, 4, 5 };//ע�����Ҫ�������Ϊ��������
	int len = sizeof(array) / sizeof(array[0]);
	int ret = removeDuplicates(array, len);
	printf("�Ƴ��ظ�Ԫ�غ󣬻���%d��Ԫ��\n", ret);
	system("pause");
	return 0;
}

//��ߣ�
//���������������Ļ���Ӧ����ô����