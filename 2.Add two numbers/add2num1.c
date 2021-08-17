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
    int carry = 0;//to record the carry from last bit
    if(l1->val == 0 && l1->next ==NULL && l2->val ==0 && l2->next ==NULL){
        ans->val = 0;
        ans->next = NULL;
        return ans;
    }
    //instead of getting the number from linkedlist and sum it all，sum it one by one
    //ex:100000000000000+1(wrong time error)
    while(!(l1 == NULL && l2 == NULL)){
        //separate when l1 == NULL and l2 == NULL
        if(l2 == NULL){
            ans->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) /10;
            l1 = l1->next;
        }
        else if(l1 == NULL){
            ans->val = (l2->val + carry) %10;
            carry = (l2->val + carry) /10;
            l2 = l2->next;
            
        }
        else{
            ans->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ans->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1 == NULL && l2 == NULL){
            //when carry still != 0 need to allocate a node for the last carry
            if(carry != 0){
                ans->next->val = carry;
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