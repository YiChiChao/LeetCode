#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(){
    int nums[] = {};
    int returnSize;
    int *ans = searchRange(nums, sizeof(nums)/ sizeof(int), 0, &returnSize);
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
    if(sizeof(nums)/sizeof(int)==0){
        *returnSize = 2;
        return ans;
    }
    while(mid != low + (high - low)/2){
        mid = low + (high - low)/2;
        //printf("mid = %d low = %d high = %d \n", mid, low, high);
        if(nums[mid] > target) high = mid;
        else if(nums[mid] < target) low = mid;
        else {
            if(nums[mid - 1] != target){
                ans[0] = mid;
                //printf("low = %d\n", low);
                //printf("high = %d\n", high);
                low = mid;
                //printf("ans0 = %d\n", ans[0]);
            }
            if(nums[mid + 1] != target){
                ans[1] = mid;
                high = mid;
                //printf("ans1 = %d\n", ans[1]);
            }
            
        }
    }
    if (key != 1){
        *returnSize = 2;
        return ans;
    }
   
    *returnSize = 2;
    return ans;
    
}