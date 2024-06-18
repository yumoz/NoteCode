#include<stdio.h>

#include<windows.h>

int romanToInt(char * s){
	char check = '\0';
	int res = 0;
	while (*s != '\0'){
		switch (*s){
		case 'I':
			res += 1;
			break;
		case 'V':
			if (check == 'I')
				res -= 2 * 1;
			res += 5;
			break;
		case 'X':
			if (check == 'I')
				res -= 2 * 1;
			res += 10;
			break;
		case 'L':
			if (check == 'X')
				res -= 2 * 10;
			res += 50;
			break;
		case 'C':
			if (check == 'X')
				res -= 2 * 10;
			res += 100;
			break;
		case 'D':
			if (check == 'C')
				res -= 2 * 100;
			res += 500;
			break;
		case 'M':
			if (check == 'C')
				res -= 2 * 100;
			res += 1000;
			break;
		}
		check = *s;
		s++;
	}
	return res;
}
int main()
{
	
	int ret =(romanToInt("IIIV"));
	printf("%d\n", ret);
	system("pause");
	return 0;
}