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

void inorder(struct TreeNode* root, int* arr, int* index){
    if(root == NULL)return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
    return;
}

int* findMode(struct TreeNode* root, int* returnSize){
    int array[10001]={0};
    
    int arr_index = 0;
    int duplicate = 0;
    int cur = 100001;
    int count = 0;
    *returnSize = 0;
    
    inorder(root, array, &arr_index);
    int *ans = (int*)malloc(arr_index * sizeof(int));
    for(int i = 0; i < arr_index; ++i){
        if(array[i] == cur)count++;
        else{
            cur = array[i];
            count = 1;
        }
        
        if(count > duplicate){
            duplicate = count;
            ans[0] = array[i];
            (*returnSize) = 1;
        }
        else if(count == duplicate){
            ans[(*returnSize)++] = array[i];
        }
    }

    return ans;
}

