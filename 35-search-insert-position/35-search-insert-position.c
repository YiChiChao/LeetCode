int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize;
    if(target > nums[right-1])return numsSize;
    if(target < nums[0])return 0;
    while(left < right){
        int mid = (left+right)/2;
        if(nums[mid] > target){
            right = mid;
        }else if(nums[mid] < target){
            left = mid+1;
        }else{
            return mid;
        }
    }
    return left;
}