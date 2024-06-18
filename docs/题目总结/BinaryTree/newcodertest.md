```c
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
     char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateTree(char* arr,int *pi)
{
     if (arr[*pi] == '#')
     {
         return NULL;
     }
     else
     {
     TreeNode * root = (TreeNode *)malloc (sizeof(TreeNode));
         root->val = arr[(*pi)++] ;
         root->left = CreateTree(arr,pi);
           ++(*pi);
         root->right = CreateTree(arr,pi);
         return root;
     } 
}
void Inorder(TreeNode * root)
{
    if (root == NULL)
    {
        return ;
    }
    Inorder(root->left);
    printf("%c ",root->val);
    Inorder(root->right);
}

int main()
{
     char arr[100];
     scanf("%s",arr);
     int i = 0;
     TreeNode * root = CreateTree(arr,&i);
     Inorder(root);
     return 0;
}

```