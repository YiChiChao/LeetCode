int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize;
    if(target > nums[right-1])return numsSize;
    if(target < nums[0])return 0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] >= target){
            return i;
        }
    }
    return numsSize;
}