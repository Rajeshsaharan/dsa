/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * helper(struct ListNode * head, int even_flag){
    if(head->next == NULL){
        return head;
    }else{
        if(even_flag ){
            struct ListNode * current_head = head;
            head = helper(head->next, !even_flag);
            struct ListNode  * temp = head->next;
            current_head->next = temp;
            head->next = current_head;
            struct ListNode * current = head;
            return head;
        }else{
            printf("in the case of odd count this will be print first");
            printf("current->head value is %d", head->val);
            head->next = helper(head->next, !even_flag);
            printf("head and head->next val %d and %d\n", head->val, head->next->val);
            return head;
        }
    
    }
}




struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode * current = head;
    int even_flag =1;
    int count =0;
    while(current){
        current= current->next;
        count++;
    }
    if( count == 0 || count == 1){
        return head;
    }
    head = helper(head, even_flag);
    return head;
    
}