#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* node = head;
    struct ListNode* Node = head;
    int i = 0;
    int count = 0;
    while(node != NULL){
        ++count;
        node = node->next;
    }
    ++count;
    int *a = malloc(count * sizeof(int));
    node = head;
    while(node != NULL){
        a[i]= node->val;//start from 0, but it starts from 0 
        node = node->next;
        ++i;
    }


    //do the swap in the array
    int tmp = a[k-1];
    a[k-1] = a[i-k];
    a[i-k] = tmp;
    i = 0;
    
    while(Node != NULL){
        Node->val = a[i];
        ++i;
        Node = Node->next;
    }
    return head;
}