/*
题目：989数组形式的整数加法
对于非负整数x而言，x的数组形式是每位数字按从左到右的顺序形成的数组。
例如，if X=1231 那么其数组形式为[1,2,3,1]
给定非负整数X的数组形式A，返回整数X+K的数组形式

*/

#include<stdio.h>
#include<windows.h>

// malloc
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int kSize = 0;
	int kNum = K;
	//判断数字的位数和溢出与否
	while (kNum){
		++kSize;
		kNum /= 10;
	}

	//从数组和数字中比较大找出来开辟内存
	int len = ASize > kSize ? ASize : kSize;
	int *retArr = (int*)malloc(sizeof(int)*(len+1));//开辟内存加一 防止进位溢出
	//数组位数
	int Ai = ASize - 1;
	int reti = 0;//返回值位数
	int nextNum = 0;//进位
	while (len--){

		//判断数组是否越界
		int a = 0;
		if (Ai >= 0){
			a = A[Ai];
			Ai--;
		}

		//加每一位
		int ret = a + K % 10 + nextNum;
		K /= 10;//求数字下一位

		//判断是否有进位
		//顺着放,之后倒置
		if (ret > 9){
			ret -= 10;
			nextNum = 1;
		}
		else{
			nextNum = 0;
		}

		retArr[reti] = ret;//将相加的值赋值给数组中存储
		++reti;//数组下标加一
	}
	
	//最后判断是否有相加等10的比如：
	// 
	if (nextNum == 1){
		retArr[reti] = 1;
		//++reti;
	}
	
	//逆置
	int left = 0;
	int right = reti - 1;
	while (left < right){
		int temp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = temp;
		left++;
		right--;
	}

	//输出型参数
	*returnSize = reti;
	return retArr;
}


//另外解法  
///**
//* Note: The returned array must be malloced, assume caller calls free().
//*/
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//	int sum, len_K, len, pa, pk;
//	int * res;
//
//	if (K == 0)
//	{
//		*returnSize = ASize;
//		return A;
//	}
//
//	len_K = log10(K) + 1;
//	*returnSize = (ASize > len_K) ? ASize + 1 : len_K + 1;
//	res = (int *)malloc(*returnSize * sizeof(int));
//	len = *returnSize;
//	while (len - 1 >= 1 || K > 0)
//	{
//		if (ASize > 0) K += A[--ASize];
//		res[--len] = K % 10;
//		K /= 10;
//	}
//
//	*returnSize -= len;
//	return res + len;
//}

int main()
{
	int array[] = { 1, 2, 0, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	int key = 34;
	int returnSize = 0;
	int *p = addToArrayForm(array, len, key, &returnSize);
	int *arr = (int *)malloc(sizeof(int)*(returnSize));//开辟returnSize大小的数组 用来存储返回的数组
	arr = p;//将返回值给数组中存储

	printf("%d\n", returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}

//思考：大数相加 大数相乘（变成加法） 



//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,0};
//	int(*p)[4] = (int(*)[4])a;
//
//	system("pause");
//	return 0;
//}