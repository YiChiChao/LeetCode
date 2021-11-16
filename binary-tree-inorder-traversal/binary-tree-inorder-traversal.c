/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Traverse(struct TreeNode* root, int* returnSize, int* arr){
    if(root->left != NULL)Traverse(root->left, returnSize, arr);
    arr[(*returnSize)++] = root->val;
    if(root->right != NULL)Traverse(root->right, returnSize, arr);
}



int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = malloc(100 * sizeof(int)); 
    *returnSize = 0;
    if(root){
        Traverse(root, returnSize, arr);
    }
    arr = realloc(arr, (*returnSize)*sizeof(int));
    return arr;
}