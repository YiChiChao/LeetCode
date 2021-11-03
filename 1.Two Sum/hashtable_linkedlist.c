#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TABLE_SIZE 20000

typedef struct{
    int value;
    int index;
}NUM;

NUM *hash_table[TABLE_SIZE];

int hash(long int value){
    long int hashval;
    hashval = (value*11) % TABLE_SIZE;
    return hashval;
}

void hash_init(){
    for (int i = 0; i < TABLE_SIZE;++i){
        hash_table[i] = NULL;
    }
}
void insert_hash_table(long int value, int arr_index){
    int index = hash(value);
    for (int i = 0; i < TABLE_SIZE; ++i){
        int try = (index + i)%TABLE_SIZE;
        if(try<0)try = try*(-1);
        if(hash_table[try] == NULL){
            hash_table[try] = malloc(sizeof(NUM));
            hash_table[try]->value = value;
            hash_table[try]->index = arr_index;
            break;
        }
    }
}

int hash_lookup(int value){
    int index = hash(value);
    for (int i = 0; i < TABLE_SIZE;++i){
        int try = (index + i)%TABLE_SIZE ;
        if(try<0)try = try*(-1);
        if(hash_table[try] == NULL)return-1;
        if(hash_table[try]!=NULL && hash_table[try]->value == value){
            return hash_table[try]->index;
        }
    }
    return -1;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hash_init();
    int *ans = malloc(2 * sizeof(long int));
    insert_hash_table(nums[0], 0);
    *returnSize = 2;
    for (int i = 1; i < numsSize;++i){
        int remaining = target - nums[i];
        int index = hash_lookup(remaining);
        if(index != -1){
            ans[0] = index;
            ans[1] = i;
            return ans;
        }
        else
            insert_hash_table(nums[i], i);
    }
    return ans;
}

int main(){
    int nums[] = {-3, 4, 3, 90};
    int returnSize;
    int* ans = twoSum(nums, 4, 0, &returnSize);
    for (int i = 0; i < 2;++i){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;


    /*if(hash_lookup(2))
        printf("2 is found\n");
    else
        printf("2 is not found\n");
    if(hash_lookup(7))
        printf("7 is found\n");
    else
        printf("7 is not found\n");
    if(hash_lookup(11))
        printf("11 is found\n");
    else
        printf("11 is not found\n");
    if(hash_lookup(15))
        printf("15 is found\n");
    else
        printf("15 is not found\n");
        */

}

