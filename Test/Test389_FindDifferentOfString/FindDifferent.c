/*

LeetCode:389
题目：找不同
题目描述：
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。
 

 示例 1：

 输入：s = "abcd", t = "abcde"
 输出："e"
 解释：'e' 是那个被添加的字母。
 示例 2：

 输入：s = "", t = "y"
 输出："y"
 示例 3：

 输入：s = "a", t = "aa"
 输出："a"
 示例 4：

 输入：s = "ae", t = "aea"
 输出："a"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-the-difference
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include<stdio.h>
#include<windows.h>

//s是未添加字母字符串
//t是s乱序后新增一个字母的字符串

//sol 1：位运算
char findTheDifference(char * s, char * t){
	int n = strlen(s);
	int m = strlen(t);
	int ret = 0;
	for (int i = 0; i < n; i++){
		ret ^= s[i];
	}
	for (int i = 0; i < m; i++){
		ret ^= t[i];
	}
	return ret;
}
void test()
{
	char str1[] = "yumoz";
	char str2[] = "yumozz";
	char  ret = findTheDifference(str1, str2);
	printf("str1:%s\nstr2:%s\ndifferenet:%c\n", str1, str2, ret);
}
int main()
{
	test();
	system("pause");
	return 0;
}