#include <stdio.h>
#include<windows.h>

//�˴�������
int singleNumber(int* nums, int numsSize){
	int result = 0;
	for (int i = 0; i < 32; i++){//����32λ
		int temp = 0;//��¼�������ֵ�iλ�ĺ�
		for (int j = 0; j < numsSize; j++){
			temp += (nums[j] >> i) & 1;//���iλ֮��
		}
		if (temp % 3){
			result += 1 << i;//��1
		}
	}
	return result;
}

int main()
{
	int Array[] = {  2, 3, 2, 2 };
	int len = sizeof(Array) / sizeof(Array[0]);

	int ret = singleNumber(Array, len);
	printf("ֻ����һ�ε����ǣ�%d\n", ret);
	system("pause");
	return 0;
}