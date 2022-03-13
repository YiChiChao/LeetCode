void rotate(int* nums, int numsSize, int k){
    int* ans = (int*)malloc(sizeof(int)*numsSize);
    k = k % numsSize;
    int index = numsSize-k-1;
    for(int i = 0; i < numsSize; ++i){
        index = (index+1) % numsSize;
        printf("%d \n", index);
        printf("\n");
        ans[i] = nums[index];
    }printf("\n");
    for(int i = 0; i < numsSize; ++i){
        nums[i] = ans[i];
    }
    free(ans);
    ans = NULL;
    return ;
}