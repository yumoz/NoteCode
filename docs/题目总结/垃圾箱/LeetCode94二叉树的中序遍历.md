二叉树练习题总结

# 1 二叉树的层序遍历

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
        //中序遍历  根左右
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

            //此时，cur为空，遍历到的左子树为空，后面需要遍历右子树。
            TreeNode *top = st.top();//取出栈顶元素
            st.pop();
            v.push_back(top->val); //栈顶元素插入到vector中保存

            cur = top->right;//遍历右子树
        }
        return v;
    }
};
```

时间复杂度为$O(n)$，空间复杂度$O(n)$；



# 2 二叉树的层序遍历

