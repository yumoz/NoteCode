/*
��Ŀ��989������ʽ�������ӷ�
���ڷǸ�����x���ԣ�x��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
���磬if X=1231 ��ô��������ʽΪ[1,2,3,1]
�����Ǹ�����X��������ʽA����������X+K��������ʽ

*/

#include<stdio.h>
#include<windows.h>

// malloc
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int kSize = 0;
	int kNum = K;
	//�ж����ֵ�λ����������
	while (kNum){
		++kSize;
		kNum /= 10;
	}

	//������������бȽϴ��ҳ��������ڴ�
	int len = ASize > kSize ? ASize : kSize;
	int *retArr = (int*)malloc(sizeof(int)*(len+1));//�����ڴ��һ ��ֹ��λ���
	//����λ��
	int Ai = ASize - 1;
	int reti = 0;//����ֵλ��
	int nextNum = 0;//��λ
	while (len--){

		//�ж������Ƿ�Խ��
		int a = 0;
		if (Ai >= 0){
			a = A[Ai];
			Ai--;
		}

		//��ÿһλ
		int ret = a + K % 10 + nextNum;
		K /= 10;//��������һλ

		//�ж��Ƿ��н�λ
		//˳�ŷ�,֮����
		if (ret > 9){
			ret -= 10;
			nextNum = 1;
		}
		else{
			nextNum = 0;
		}

		retArr[reti] = ret;//����ӵ�ֵ��ֵ�������д洢
		++reti;//�����±��һ
	}
	
	//����ж��Ƿ�����ӵ�10�ı��磺
	// 
	if (nextNum == 1){
		retArr[reti] = 1;
		//++reti;
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


//����ⷨ  
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
	int *arr = (int *)malloc(sizeof(int)*(returnSize));//����returnSize��С������ �����洢���ص�����
	arr = p;//������ֵ�������д洢

	printf("%d\n", returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}

//˼����������� ������ˣ���ɼӷ��� 



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