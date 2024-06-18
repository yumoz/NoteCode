/*

给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同 

 示例 1：

 输入：s = "bcabc"
 输出："abc"
 示例 2：

 输入：s = "cbacdcbc"
 输出："acdb"
  

  提示：

  1 <= s.length <= 104
  s 由小写英文字母组成

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/remove-duplicate-letters
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

  参考：Leetcode官方解答
  参考以下：
  作者：yuan20191128
  链接：https ://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/solution/cyu-yan-bu-tong-zi-fu-de-zui-xiao-zi-xu-lie-by-yua/
  来源：力扣（LeetCode）
  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include<windows.h>


//char* removeDuplicateLetters(char* s) {
//	int vis[26], num[26];
//	memset(vis, 0, sizeof(vis));
//	memset(num, 0, sizeof(num));
//
//	int n = strlen(s);
//	for (int i = 0; i < n; i++) {
//		num[s[i] - 'a']++;//对每个字符出现次数进行统计，存在字符串中
//	}
//
//	char* stk = malloc(sizeof(char) * 27);
//	int stkTop = 0;
//	for (int i = 0; i < n; i++) {
//		if (!vis[s[i] - 'a']) {//判断字符串中当前字符的偏差
//			while (stkTop > 0 && stk[stkTop - 1] > s[i]) {//利用栈的先入后出知识，进行重复元素的舍去
//				if (num[stk[stkTop - 1] - 'a'] > 0) {
//					vis[stk[--stkTop] - 'a'] = 0;
//				}
//				else {
//					break;
//				}
//			}
//			vis[s[i] - 'a'] = 1;
//			stk[stkTop++] = s[i];
//		}
//		num[s[i] - 'a'] -= 1;
//	}
//	stk[stkTop] = '\0';
//	return stk;
//}


//参考：1080 不同字符的最小子序列
char res[27];

//char *smallestSubsequence(char *text)
char *removeDuplicateLetters(char *text)
{
	int flag[26];
	int index = 0;
	for (size_t i = 0; i < 26; i++)
	{
		flag[i] = 0;
	}

	while (*text != '\0')
	{
		int ch = *text - 'a';
		if (flag[ch] == 1)
		{
			*text++;
			continue;
		}
		while (index != 0 && *text < res[index - 1] && strchr(text, res[index - 1]) != NULL)
		{
			flag[res[index - 1] - 'a']--;
			index--;
		}

		flag[ch]++;
		res[index++] = *text++;
	}
	res[index] = '\0';
	return res;
}



void test()
{
	char str1[] = "cbacdcbc";
	char str2[] = "bcabc";
	char * ret = removeDuplicateLetters(str2);
	printf("%s\n", ret);
}
int main()
{
	test();
	system("pause");
	return 0;
}