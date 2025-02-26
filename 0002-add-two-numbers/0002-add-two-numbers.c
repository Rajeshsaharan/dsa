/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * append_list(struct ListNode * list, int val){
    struct ListNode * new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
    new_node->val = val;
    if(list == NULL){
        list = new_node;
        new_node->next = NULL;
        return list;
    }
    struct ListNode * current = list;
    while(current->next){
        current = current->next;
    }
    current->next = new_node;
    new_node->next =  NULL;
    return list;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * current1 = l1;
    struct ListNode * current2 = l2;
    struct ListNode * list = NULL;
    //respectively set the current value
    int carry = 0;
    while(current1 || current2){
        //if any  of linked list value exit;
        int data1 = current1 != NULL ? current1->val : 0;
        int data2 = current2 !=NULL ? current2->val : 0;
        int result = data1 + data2 +carry;
        if(result >= 10){
            carry = result/10;
            list = append_list(list, result %10);
        }else{
            carry = 0;
            list = append_list(list, result);
        }
        current1=  (current1 != NULL) ? current1->next : NULL;
        current2 = (current2 !=NULL) ? current2->next : NULL;
    }
    if(carry == 0){
        return list;
    }
    struct ListNode * current = list;
    while(current->next){
        current = current->next;
    }
    struct ListNode * new_node = (struct ListNode *)(malloc(sizeof(struct ListNode)));
    current->next = new_node;
    new_node->val = carry;
    new_node->next = NULL;
    return list;
}