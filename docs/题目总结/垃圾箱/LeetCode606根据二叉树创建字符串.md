# 根据二叉树创建字符串

[题目链接](https://leetcode-cn.com/problems/construct-string-from-binary-tree/)

你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /    

  4     

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。



输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。

## 思路一：传值返回

传值返回一：

思路：

> 1. 没有节点，返回空
> 2. 没有左右节点，直接返回本节点值
> 3. 没有右子树节点，只需要在左子树节点外加括号，右子树不做任何处理；
> 4. 只有右子树节点，左子树节点不存在，先给左子树加一层（）,在对右子树进行处理；

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == nullptr)
            return "";
        if(root->left == nullptr && root->right == nullptr)
            return to_string(root->val) ;
        if(root->right == nullptr)
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};
```

运行结果：

![image-20211205103917186](ImageSave/image-20211205103917186.png)

递归分析图：

![image-20211205103408088](ImageSave/LeetCode606传值返回01.png)



传值返回二：

思路：

> 1. 若根为空，return空
> 2. 若左子树不为空，或者右子树不为空，递归遍历左树，并在左树外加括号（左树为空也要加括号）
> 3. 若右子树不为空，递归遍历右子树，右子树外加括号

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        //1.空树
        if(root == nullptr)
            return "";
        string str;
        str += to_string(root->val);
        //2.左子树不为空 或者 右子树不为空
        if(root->left || root->right)
            str = str + "(" + tree2str(root->left) + ")";
        //3.右子树不为空
        if(root->right)
            str = str + "(" + tree2str(root->right) + ")";
        return str;
    }
};
```

![image-20211205101644561](ImageSave/image-20211205101644561.png)

递归分析图：

![image-20211205101833356](ImageSave/LeetCode606递归分析图.png)

改写上述代码，参考；

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == nullptr)
            return string();
        
        string str;
        str += to_string(root->val);
        //1.左不为空，左边值外带括号；右不为空，左为空，左边的空括号不可省略
        if(root->left != nullptr || root->right != nullptr)
        {
            str +="(";
            str += tree2str(root->left);
            str += ")"; 
        } 

        //2.右树不为空，右树外面带括号
        if(root->right != nullptr)
        {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }
};
```

上述代码存在很大问题，return str是传值返回，存在大量的string深拷贝，所以下面给出另一种方法。

## 思路二：传引用

直接改为传引用返回，减少深拷贝次数。

分析如下：

![image-20211205101047356](ImageSave/LeetCode606传引用返回.png)

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    void _tree2str(TreeNode* root, string& str)  //通过传引用返回，减少深拷贝
    {
        if(root == nullptr) return ;

        str += to_string(root->val);
        //1.左树不为空 或者 右数不为空
        if(root->left != nullptr || root->right != nullptr)
        {
            str += "(";
            _tree2str(root->left, str);//遍历左树，左树为空时也加括号
            str += ")";
        }
        
        //2. 右树不为空，右树的值外加括号
        if(root->right != nullptr)
        {
            str += "(";
            _tree2str(root->right, str);
            str += ")";
        }
            
    }
    string tree2str(TreeNode* root) {
        string s;
        _tree2str(root, s);

        return s;
    }
};
```

执行结果：

![image-20211205100930044](ImageSave/image-20211205100930044.png)

