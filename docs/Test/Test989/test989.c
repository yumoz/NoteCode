/*
��Ŀ��989������ʽ�������ӷ�
	���ڷǸ�����x���ԣ�x��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
	���磬if X=1231 ��ô��������ʽΪ[1,2,3,1]
	�����Ǹ�����X��������ʽA����������X+K��������ʽ

*/

#include<stdio.h>
#include<windows.h>
#include<math.h>
/*
����˼·����������һ������������ʽ + һ�������� ���غ͵�������ʽ��
ģ��ӷ�������λ��ӣ� �ӵ�λ���λ��ӣ�����������ã��õ����ս��
1. ÿһλ��ֵ = ��Ӧλֵ�ĺ� + ǰһλ�Ľ�λ
2. ÿһλ��ֵ�������֮����Ҫ����Ƿ���Ҫ��λ
3. ���λ����֮����Ҫ�����Ƿ���Ҫ���Ͻ�λ
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
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//	
//	int* addRet = (int*)malloc(10001 * sizeof(int));
//	//reti: ��iλ�Ľ��
//	int reti = 0;
//	//�ӵ�λ��ʼ���
//	int ai = ASize - 1;
//	int next = 0; // ��λֵ
//	while (ai >= 0 || K > 0)
//	{
//
//		int x1 = 0;
//		//���aiû��Խ�磬����δ��ӵ�λ��ȡ��һλ����x1
//		if (ai >= 0)
//		{
//			x1 = A[ai];
//			--ai;
//		}
//
//		int x2 = 0;
//		//���k����0����ȡk�ĵ�iλ
//		if (K > 0)
//		{
//			x2 = K % 10;
//			K /= 10;
//		}
//		//��iλ�Ľ����ÿһλ��ֵ + ��λ
//		int ret = x1 + x2 + next;
//		//����������9����Ҫ��λ
//		if (ret > 9)
//		{
//			ret %= 10;
//			next = 1;
//		}
//		else
//		{
//			next = 0;
//		}
//		//�����iλ�Ľ����������
//		addRet[reti++] = ret;
//	}
//	//������λ�н�λ����Ҫ�ڴ���1
//	if (next == 1)
//	{
//		addRet[reti++] = 1;
//	}
//	//���ý��
//	reverse(addRet, 0, reti - 1);
//	*returnSize = reti;
//
//	return addRet;
//}

// 
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int kSize = 0;
	int kNum = K;
	while (kNum){
		++kSize;
		kNum /= 10;
	}
	int len = ASize > kSize ? ASize : kSize;
	int *retArr = (int*)malloc(sizeof(int)*(len+1));
	//
	int Ai = ASize - 1;
	int reti = 0;
	int nextNum = 0;//��λ
	while (len--){

		//�ж��Ƿ�Խ��
		int a = 0;
		if (Ai >= 0){
			a = A[Ai];
			Ai--;
		}

		int ret = a + K % 10 + nextNum;
		K /= 10;

		//�ж��Ƿ��н�λ
		//˳�ŷ�,֮����
		if (ret > 9){
			ret -= 10;
			nextNum = 1;
		}
		else{
			nextNum = 0;
		}

		retArr[reti] = ret;
		++reti;
	}
	
	//����ж��Ƿ�����ӵ�10�ı��磺
	// 
	if (nextNum == 1){
		retArr[reti] = 1;
		++reti;
	}
	
	//����
	int left = 0;
	int right = reti - 1;
	while (left < right){
		int temp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = temp;
		left++;
		right--;
	}

	//����Ͳ���
	*returnSize = reti;
	return retArr;
}


////��һ�ֽⷨ
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//	int len_K, len;
//	int * res;
//
//	if (K == 0)
//	{
//		*returnSize = ASize;
//		return A;
//	}
//
//	len_K = (int)log10(K) + 1;//���ֳ���   ��K=100 ��len_K=2+1;
//	*returnSize = (ASize > len_K) ? ASize + 1 : len_K + 1;//����󳤶ȿ��ٿռ�
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
	int array[] = { 9, 2, 0, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	int key = 1034;
	int returnSize=0;
	int *p = addToArrayForm(array, len, key, &returnSize);
	int *arr = (int *)malloc(sizeof(int)*(returnSize));//����returnSize��С������ �����洢���ص�����
	arr = p;//������ֵ�������д洢

	for (int i = 0; i < returnSize;i++)
	{
		printf("%d ", arr[i]);
	}
		
	system("pause");
	return 0;
}

//˼����������� ������ˣ���ɼӷ��� 