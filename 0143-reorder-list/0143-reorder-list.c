/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;


void reorderList(struct ListNode* head) {
    int size =0;
     ListNode * current = head;
    while(current){
        current = current->next; 
        size++;
    }
    int top =0;
    ListNode * stack[size];
    current = head;
    while(current){
        stack[top] = current;
        current = current->next;
        if(current == NULL){
            break;
        }
        top++;
    }
    
    current = head;
    ListNode * temp;
    printf("top and size %d and %d", top, size);
    int count =0;
    while(current){
        if(count == size/2){
            current->next = NULL;
            return;
        }
        temp =current->next;
        current->next = stack[top--];
        current->next->next = temp;
        current = temp;
        count++;
    }
    
}