#include<stdio.h>
#include<limits.h>//INT_MAX INT_MIN

int reverse(int x);
int main()
{
	int ret = reverse(2147483648);
	printf("%d\n", ret);
	system("pause");
	return 0;
}int reverse(int x){
	int a, rev = 0;
	int z_ed = INT_MAX % 10;//�ó�INT_MAX�ĸ�λ
	while (x){
		a = x % 10;//tail 
		x = x / 10;//ȥ��tail����
		//��rev��������ж�
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && a > 7)){
			return 0;
		}
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && a < (-8))){
			return 0;
		}
		rev = rev * 10 + a;
	}

	return rev;

}