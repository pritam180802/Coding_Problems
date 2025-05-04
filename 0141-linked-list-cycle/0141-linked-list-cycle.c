/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow,*fast;
    slow = fast = head;
    if(head==NULL || head->next == NULL)
    return 0;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        return 1;
    }
    return 0;
}