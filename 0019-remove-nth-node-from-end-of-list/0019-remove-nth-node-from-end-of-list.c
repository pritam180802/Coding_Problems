/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    struct ListNode *ptr,*temp;
    ptr = head;
    int count = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    ptr = head;
    if(count == n){
        head = head->next;
        free(ptr);
        return head;
    }
    count = count-n;
    for(int i=0;i<count;i++){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
    return head;
}