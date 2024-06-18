/*
LeetCode：28
题目：实现strstr
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include<stdio.h>
#include <windows.h>
#include<string.h>


int strStr(char * haystack, char * needle)
{
	char *loc = strstr(haystack, needle);
	return loc ? loc - haystack : -1;
}

int main()
{
	char str1[] = "hello";
	char str2[] = "ll";
	int ret = strStr(str1, str2);
	printf("%d\n", ret);

	system("pause");
	return 0;
}