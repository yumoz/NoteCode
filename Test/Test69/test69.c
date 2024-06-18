//求平方根
#include<stdio.h>
#include<windows.h>
int mySqrt(int x);
int main()
{
	printf("%d\n",mySqrt(8));
	system("pause");
	return 0;
}
int mySqrt(int x){
	long i = 0;
	for (i = 0; i <= x; i++){

		if (i*i > x){
			return (int)i - 1;
		}
		else if (i*i == x){
			return (int)i;
		}
	}
	return 0;
}