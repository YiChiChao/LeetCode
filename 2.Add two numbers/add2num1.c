/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode** mem = (struct ListNode**)malloc(sizeof(struct ListNode*));;
    *mem = ans;
    int ten = 0;
    if(l1->val == 0 && l1->next ==NULL && l2->val ==0 && l2->next ==NULL){
        ans->val = 0;
        ans->next = 0;
        return ans;
    }
    while(!(l1 == NULL && l2 == NULL)){
        if(l2 == NULL){
            ans->val = (l1->val + ten) %10;
            ten = (l1->val + ten) /10;
            l1 = l1->next;
        }
        else if(l1 == NULL){
            ans->val = (l2->val + ten) %10;
            ten = (l2->val + ten) /10;
            l2 = l2->next;
            
        }
        else{
            ans->val = (l1->val + l2->val + ten) % 10;
            ten = (l1->val + l2->val + ten) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ans->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1 == NULL && l2 == NULL){
            if(ten != 0){
                ans->next->val = ten;
                ans->next->next = NULL;
            }
            else ans->next = NULL;
        } 
        ans = ans->next;
    }
    

    /*while(*mem != NULL){
        printf("%d\n", (*mem)->val);
        *mem = (*mem)->next;
    }*/
    return *mem;
}