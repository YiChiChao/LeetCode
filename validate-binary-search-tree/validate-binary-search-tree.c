/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int MAX = 2147483647;
int MIN = -2147483648;
bool check(struct TreeNode* root, struct TreeNode* upper, struct TreeNode* lower){
    if(root == NULL)return true;
    if((upper != NULL && upper->val <= root->val)||(lower != NULL && lower->val >= root->val))return false;
    return check(root->left, root, lower) && check(root->right, upper, root);   
}

bool isValidBST(struct TreeNode* root){
    if(check(root, NULL, NULL))return true;
    return false;
}

