//Swap Nodes in Pairs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL)return NULL;
    if(head->next == NULL)return head;

    ListNode* tmp;
    tmp = head->next;
    head->next = tmp->next;
    tmp->next = head;
    head->next = swapPairs(head->next);
    head = tmp;
    return head;
}