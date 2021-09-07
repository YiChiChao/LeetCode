#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(){
    int nums[] = {2,2};
    int returnSize;
    int *ans = searchRange(nums, sizeof(nums)/ sizeof(int), 2, &returnSize);
    printf("%d\n", ans[0]);
    printf("%d\n", ans[1]);
    return 0;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = malloc(3 * sizeof(int));
    int low = 0;
    int high = numsSize - 1;
    int mid;
    int key = 0;
    ans[0] = -1;
    ans[1] = -1;
    if(numsSize==0){
        *returnSize = 2;
        return ans;
    }
    //for the head
    while(low < high){
       mid = low + (high - low)/2;
       if(nums[mid] >= target) high = mid;
       else low = mid + 1;
    }
    ans[0] = low;
    low = 0;
    high = numsSize - 1;

    //for the end
    while(low < high){
        mid = low + (high - low)/2;
        if(nums[mid] > target) high = mid;
        else low = mid + 1;
    }
    ans[1] = low;

    if (key != 1){
        *returnSize = 2;
        return ans;
    }
   
    *returnSize = 2;
    return ans;
    
}