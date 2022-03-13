void reverse(int* nums, int start, int end){
    int temp;
    while(start <= end){
        temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
    return;
}

void rotate(int* nums, int numsSize, int k){
    if(k >= numsSize) k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
    return ;
}