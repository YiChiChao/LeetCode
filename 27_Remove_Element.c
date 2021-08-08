#include <stdio.h>
int removeElement(int* nums, int numsSize, int val){
//two pointer algorithem
    int front = 0;
    int back;
    if(numsSize == 0)back = 0;
    else back = numsSize-1;
    while(front != back){
        if(nums[back] == val){
            --back;
            --numsSize;
            continue;
        }
        if(nums[front] != val) ++front;
        else{
            nums[front] = nums[back];
            nums[back] = val;
        }
    }
    //deal with the [] input
    if(nums[front] == val && numsSize != 0){
        nums[front] = nums[numsSize - 1];
        --numsSize;
    }
    
    return numsSize;
}
/*
input: [] 0
output: []

input:[1] 1
output:[]
*/