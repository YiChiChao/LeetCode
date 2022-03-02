

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* ans = malloc(numsSize*sizeof(int));
    int left = 0, right = numsSize-1;
    int index = right;
    while(left <= right){
        if(abs(nums[left]) > abs(nums[right])){
            ans[index--] = nums[left]*nums[left];
            printf("%d\n", nums[left]*nums[left]);
            ++left;
        }else {
            ans[index--] = nums[right]*nums[right];
            printf("%d\n", nums[right]*nums[right]);
            printf("v\n");
            --right;
            printf("v\n");
        }
    }
    /*for(int i = 0; i < numsSize; ++i){
        printf("%d ", ans[i]);
    }printf("\n");*/
    return ans;
}