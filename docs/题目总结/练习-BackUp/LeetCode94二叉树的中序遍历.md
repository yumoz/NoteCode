# 二叉树的层序遍历

[题目链接](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/submissions/)

## 非递归参考代码

分析图：

![](ImageSave/LeetCode94二叉树的中序遍历.png)

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
    vector<int> inorderTraversal(TreeNode* root) {        
        vector<int> v;

        TreeNode *cur = root;
        stack<TreeNode*> st;
        while(cur != nullptr || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode *top = st.top();
            st.pop();
            v.push_back(top->val);

            cur = top->right;
        }
        return v;
    }
};
```

时间复杂度为$O(n)$，空间复杂度$O(n)$；

