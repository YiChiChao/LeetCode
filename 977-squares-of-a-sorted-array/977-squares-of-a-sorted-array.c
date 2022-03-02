

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* ans = malloc(numsSize*sizeof(int));
    int left = 0, right = numsSize-1;
    int leftPow = pow(nums[left],2), rightPow = pow(nums[right],2);
    int index = right;
    while(left <= right){
        if(leftPow > rightPow){
            ans[index--] = leftPow;
            ++left;
            leftPow = nums[left]*nums[left];
        }else if(rightPow > leftPow){
            ans[index--] = rightPow;
            printf("v\n");
            --right;
            rightPow = nums[right]*nums[right];
            printf("v\n");
        }else if(right != left){
            ans[index--] = rightPow;
            ans[index--] = rightPow;
            ++left;
            --right;
            leftPow = nums[left]*nums[left];
            rightPow = nums[right]*nums[right];
            printf("v\n");
        }else{
            ans[index--] = rightPow;
            left++;
            printf("v\n");
        }
    }
    for(int i = 0; i < numsSize; ++i){
        printf("%d ", ans[i]);
    }printf("\n");
    return ans;
}