整理牛客网剑指offer练习题总结。

# 把字符串转换成整数

```c 
class Solution {
public:
	int strToInt(string str) {
		//1. 字符串为空
		if (str.empty()) return 0;

		// 1.1 考虑前面的空格 如“  -23 min”
		int i = 0;
		for ( i = 0; i < str.size() && str[i] == ' '; ++i)
		{
			//空操作
		}

		str = str.substr(i, str.size() );

		// 2. 考虑正负号
		int sign = 1;
		if (str[0] == '-'){
			sign = -1;
		}
		string res = "";
		if (str[0] == '+' || str[0] == '-') {
			res = str.substr(1, str.size() - 1);
		}
		else{
			res = str;
		}

		//3. 考虑数字越界 出错 问题解决 空格问题
		for (int i = 0; i<res.size(); i++){
			if (res[i]>'9' || res[i] < '0')
				//res[i] = 0;// return 0;
			res = res.substr(0, i);
		}

		// long long result = 0;
		// long long bitcount = 1;
		// for (int i = res.size() - 1; i >= 0 ; i--){
		// 	// result = result + (res[i] - '0')*bitcount;
		// 	// bitcount = bitcount * 10; // 从个位往上加

        //     result = result*10 + (res[i] - '0');

        //     //考虑大数
        //     if(sign == 1 && result > INT_MAX){
        //         return INT_MAX;
        //     }
        //     else if(sign == -1 && -result < INT_MIN){
        //         return INT_MIN;
        //     }
		// }

        // // 正序写法
        long long result = 0;
		int bitcount = 1;
        for (int i = 0; i <= res.size()-1 && isdigit(res[i]); ++i){
			// result = result*10 + (res[i] - '0')*bitcount;
			// bitcount = bitcount * 10; // 从个位往上加
            
            result = result*10 + (res[i] - '0')*bitcount;

            //考虑大数
            if(sign == 1 && result > INT_MAX){
                return INT_MAX;
            }
            else if(sign == -1 && -result < INT_MIN){
                return INT_MIN;
            }
		}

		return sign*result;
	}
};
```

# 数组中重复出现的数字

```c 
int findRepeatNumber(int* nums, int numsSize){
    int arr[numsSize];
    memset(arr,0,sizeof(arr));
    for(int i = 0;i<numsSize;i++){
        if(arr[nums[i]]++) //第二次遇到同样数字，if语句为真
            return nums[i];
    }
    return -1;
}

```

# 数组中出现超过一半的整数

题目描述：

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。你可以假设数组是非空的，并且给定的数组总是存在多数元素。1<=数组长度<=50000，0<=数组元素<=10000

## 思路

方法一：直接排序，出现超过一半的数字肯定在中间直接返回数组中间的数字即可。

> 缺点：效率低，使用了sort

方法二：依次遍历数组（代码如下面code）

1. 找出基准数字，例如numbers[0];
2. 记count = 1；
3. 遍历数组，若数组中的值等于 numbers[0]，count++；否则count--；
4. 若count == 0 时，说明第一个数字numbers[0]不是出现超过一半的数字，继续找数组下一个数字numbers[1];
5. 若找到，直接返回这个数。



## code

```C++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        int curNum = numbers[0];
        int count = 1; //统计出现多少次
        for(int i = 1;i<numbers.size();++i)
        {
            if(numbers[i] == curNum) count++;
            else
            {
                count--;
                if(count == 0)
                {
                    //若第一个数不是，那么继续找数组下一位
                    curNum = numbers[i]; 
                    count = 1;
                }
            }
        }
        return curNum;
    }
};
```





# 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）

```
输入：head = [1,3,2]
输出：[2,3,1]
```

**限制：**0 <= 链表长度 <= 10000





```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head == nullptr) return {};
        vector<int> v;
        v = reversePrint(head->next);
        v.push_back(head->val);
        return v;
    }
};
```



```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    int total = 0;
    struct ListNode* p = head;
    int *res = malloc(10000 * sizeof(int));

    memset(res, 0, 10000 * sizeof(int));
    while (p) {
       res[total++] = p->val;//顺序存放
       p = p->next;
    }
    //逆置
    for (int i = 0; i < total / 2; i++) {
        int temp = res[i];
        res[i] = res[total - i - 1];
        res[total - i - 1] = temp;
    }
    *returnSize = total;
    return res;
}
```

# 链表中最后k个节点

```c
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode * cur = head;
    int num = 0;
    while(cur != NULL)//统计链表的长度
    {
        num++;
        cur = cur->next;
    }
    cur = head;
    while(num != k)
    {
        cur = cur->next;
        num--;
    }
    return cur;
}
```

## analyse

![输入图片说明](ImageSave/205936_9b436ee0_3043085.png "offer22链表中倒数第k个节点.png")

## C++  stack & vector思路

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }

        while(!st.empty()){
            res.push_back(st.top()); //stack存放到vector中
            st.pop();
        }
        return res;
    }
};
```



#　二叉树的最近公共祖先

## C语言

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
//注意关于此类型的返回值问题
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    if(root == NULL) return NULL; //1.空树
    if(root == p || root == q) return root;//2.子树只有一边有
    TreeNode* left = lowestCommonAncestor(root->left,p,q); //3.遍历左子树
    TreeNode* right = lowestCommonAncestor(root->right,p,q); //4. 遍历右子树
    if(left != NULL && right != NULL){  //5. p q 分布在左右子树
        return root;
    }
    if(left != NULL && right == NULL){ //6. 右子树为空， 左子树不空
        return left;
    }
    if(right != NULL && left == NULL){ //7. 右子树不空，左子树不为空
        return right;
    }
    return NULL; // 其他情况
}
```



# 栈的压入、弹出

[LeetCode题目链接](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)

题目描述：

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

# 解析思路

1. 有两个整数序列，分别为pushV 和 popV，分别表示站的压入序列和弹出序列。
2. 将pushV序列逐个push到栈st中。
   * 如栈顶元素 和 popV元素相等；删除栈顶元素 st.pop();
   * 

```C++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int i = 0;//控制入栈的pushV数据下表
        int j = 0;//控制栈元素的pop，记录其popv长度
        while(i < pushV.size()){
            // pushV数组的值入栈
            st.push(pushV[i]);
            ++i;
            
            //出栈，pop数组值依次与栈里面的数据比较
            //若相等 pop ，出栈里的数据 ； 若不等 结束
            while(!st.empty() && st.top() == popV[j]){
                st.pop();
                ++j;
            }
        }
        return j == popV.size();//j走完popv，是匹配
    }
};
```



# JZ8：二叉树的下一个节点

代码，递归式：

```C++
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    vector<TreeLinkNode*> nodes;
    
    //中序遍历子函数，递归式
    void InOrder(TreeLinkNode* root)
    {
        if(root == nullptr)
            return;
        InOrder(root->left);
        nodes.push_back(root);
        InOrder(root->right);
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = pNode;
        while(root->next) root = root->next; //获取根结点
        
        InOrder(root);//中序遍历
        
        int n = nodes.size();
        
        for(int i = 0; i<n-1; i++)
        {
            TreeLinkNode* cur = nodes[i];
            if(pNode == cur)
            {
                return nodes[i+1];
            }
        }
        return NULL;
    }
    
};
```

# JZ13 机器人的运动范围

[题目链接](https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=265&tqId=39217&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D265&difficulty=undefined&judgeStatus=undefined&tags=&title=)；

**深度优先搜索（dfs）**

深度优先搜索一般用于树或者图的遍历，其他有分支的（如二维矩阵）也适用。它的原理是从初始点开始，一直沿着同一个分支遍历，直到该分支结束，然后回溯到上一级继续沿着一个分支走到底，如此往复，直到所有的节点都有被访问到。

**广度优先搜索**

深度优先搜索是一条路走到底，我们还可以尝试广度优先搜索。只要遍历的时候从起点开始，依次访问与其相邻的四个方向（如果可以访问），然后再将与这四个方向相邻的节点都依次加入队列中排队等待访问。这样下来，每次访问都是一圈一圈推进，因此是广度优先搜索。
