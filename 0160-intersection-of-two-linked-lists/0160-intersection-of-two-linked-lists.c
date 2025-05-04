/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int c1=0,c2=0;
    struct ListNode *a,*b;
    a = headA;
    b = headB;
    
    while(a){
        a = a->next;
        c1++;
    }
    while(b){
        b = b->next;
        c2++;
    }
    a=headA;
    b=headB;
    if(c1>c2){
        int diff = c1-c2;
        for(int i=0;i<diff;i++)
        a = a->next;
    }
    if(c2>c1){
        int diff = c2-c1;
        for(int i=0;i<diff;i++)
        b = b->next;
    }
    while(a){
        if(a == b)
        return a;
        a = a->next;
        b = b->next;
        
    }
    return NULL;
}