#include <stdio.h>
#include<windows.h>

//此代码来自
int singleNumber(int* nums, int numsSize){
	int result = 0;
	for (int i = 0; i < 32; i++){//遍历32位
		int temp = 0;//记录所有数字第i位的和
		for (int j = 0; j < numsSize; j++){
			temp += (nums[j] >> i) & 1;//求第i位之和
		}
		if (temp % 3){
			result += 1 << i;//置1
		}
	}
	return result;
}

int main()
{
	int Array[] = {  2, 3, 2, 2 };
	int len = sizeof(Array) / sizeof(Array[0]);

	int ret = singleNumber(Array, len);
	printf("只出现一次的数是：%d\n", ret);
	system("pause");
	return 0;
}