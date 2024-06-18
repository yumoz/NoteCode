//参考：https://github.com/liu-zhao-jun/leetcode/blob/1854d20b86db1554701a78f71adeb9c93c6f2fc1/rotate-image.c

#include<stdio.h>
#include<windows.h>

//经典解法：先水平翻转、后对角线翻转

void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	// 水平翻转
	for (int i = 0; i < matrixSize / 2; ++i) {
		for (int j = 0; j < matrixSize; ++j) {
			swap(&matrix[i][j], &matrix[matrixSize - i - 1][j]);
		}
	}
	// 主对角线翻转
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < i; ++j) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}
}
void Print(int** matrix, int matrixSize, int* matrixColSize) {
	int i, j;
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixColSize[i]; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void test()
{
	//int matrix[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };

	//int matrixColSize[3];
	//int **matrix = (int **)malloc(sizeof(int *) * 3);
	//int i;
	//for (i = 0; i < 3; i++) {
	//	matrix[i] = (int *)malloc(sizeof(int) * 3);
	//	matrixColSize[i] = 3;
	//}
	
	int matrixColSize[3];
	int **matrix = (int **)malloc(sizeof(int *) * 3);
	int i;
	for (i = 0; i < 3; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * 3);
		matrixColSize[i] = 3;
	}
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2][0] = 7;
	matrix[2][1] = 8;
	matrix[2][2] = 9;

	Print(matrix, 3, matrixColSize);
	rotate(matrix, 3, matrixColSize);
	Print(matrix, 3, matrixColSize);
}
int main()
{
	test();
	system("pause");
	return 0;
}