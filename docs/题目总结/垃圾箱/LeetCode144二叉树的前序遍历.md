# 二叉树的前序遍历

[题目链接](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/submissions/)

## 非递归参考代码

分析图：

![](ImageSave/LeetCode144二叉树的前序遍历.png)

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
    vector<int> preorderTraversal(TreeNode* root) {        
        vector<int> v;
        if(root == nullptr) return v;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur !=nullptr || !st.empty())
        {
            while(cur != nullptr){
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = st.top();//取栈顶元素            
            st.pop();

            cur = top->right;
        }
        return v;
    }
};
```

时间复杂度为$O(n)$，空间复杂度$O(n)$；

