int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize-1;
    
    while(right > left){
        int mid = (left+right)/2;
        //printf("%d\n", nums[mid]);
        if(nums[mid] > target){
            right = mid;
            //printf("%d %d\n", left, right);
        }
        else if(nums[mid] < target){
            left = mid+1;
            //printf("%d %d\n", left, right);
        }
        else return mid;
    }
    if(nums[left] == target)return left;
    else return -1;
}
