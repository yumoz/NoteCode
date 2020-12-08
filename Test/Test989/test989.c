/*
题目：989数组形式的整数加法
	对于非负整数x而言，x的数组形式是每位数字按从左到右的顺序形成的数组。
	例如，if X=1231 那么其数组形式为[1,2,3,1]
	给定非负整数X的数组形式A，返回整数X+K的数组形式

*/

#include<stdio.h>
#include<windows.h>

/*
解题思路：此题是用一个数的数组形式 + 一个整数， 返回和的数组形式。
模拟加法进行逐位相加， 从低位向高位相加，最后整体逆置，得到最终结果
1. 每一位的值 = 对应位值的和 + 前一位的进位
2. 每一位的值计算出来之后，需要检查是否需要进位
3. 最高位计算之后，需要考虑是否还需要向上进位
*/
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		++begin;
		--end;
	}
}

// malloc
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	
	int* addRet = (int*)malloc(10001 * sizeof(int));
	//reti: 第i位的结果
	int reti = 0;
	//从低位开始相加
	int ai = ASize - 1;
	int next = 0; // 进位值
	while (ai >= 0 || K > 0)
	{

		int x1 = 0;
		//如果ai没有越界，还有未相加的位，取出一位存入x1
		if (ai >= 0)
		{
			x1 = A[ai];
			--ai;
		}

		int x2 = 0;
		//如果k大于0，获取k的第i位
		if (K > 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		//第i位的结果：每一位的值 + 进位
		int ret = x1 + x2 + next;
		//如果结果大于9，需要进位
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		//存入第i位的结果到数组中
		addRet[reti++] = ret;
	}
	//如果最高位有进位，需要在存入1
	if (next == 1)
	{
		addRet[reti++] = 1;
	}
	//逆置结果
	reverse(addRet, 0, reti - 1);
	*returnSize = reti;

	return addRet;
}

// malloc
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	int kSize = 0;
//	int kNum = K;
//	while (kNum){
//		++kSize;
//		kNum /= 10;
//	}
//	int len = ASize > kSize ? ASize : kSize;
//	int *retArr = (int*)malloc(sizeof(int)*(len+1));
//	//
//	int Ai = ASize - 1;
//	int reti = 0;
//	int nextNum = 0;//进位
//	while (len--){
//
//		//判断是否越界
//		int a = 0;
//		if (Ai >= 0){
//			a = A[Ai];
//			Ai--;
//		}
//
//		int ret = a + K % 10 + nextNum;
//		K /= 10;
//
//		//判断是否有进位
//		//顺着放,之后倒置
//		if (ret > 9){
//			ret -= 10;
//			nextNum = 1;
//		}
//		else{
//			nextNum = 0;
//		}
//
//		retArr[reti] = ret;
//		++ret;
//	}
//	
//	//最后判断是否有相加等10的比如：
//	// 
//	if (nextNum == 1){
//		retArr[reti] = 1;
//		++reti;
//	}
//	
//	//逆置
//	int left = 0;
//	int right = reti - 1;
//	while (left < right){
//		int temp = retArr[left];
//		retArr[left] = retArr[right];
//		retArr[right] = temp;
//		left++;
//		right++;
//	}
//
//	//输出型参数
//	*returnSize = reti-1;
//	return retArr;
//}



int main()
{
	int array[] = { 1, 2, 0, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	int key = 34;
	int returnSize=0;
	int *p = addToArrayForm(array, len, key, &returnSize);
	int *arr = (int *)malloc(sizeof(int)*(returnSize));//开辟returnSize大小的数组 用来存储返回的数组
	arr = p;//将返回值给数组中存储

	for (int i = 0; i < returnSize;i++)
	{
		printf("%d ", arr[i]);
	}
		
	system("pause");
	return 0;
}

//思考：大数相加 大数相乘（变成加法） 