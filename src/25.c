//Reverse Nodes in k-Group
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* reverseKGroup(struct ListNode* head, int k){

    if(head == NULL)return NULL;
    if(head->next == NULL || k == 1)return head;
    int time = k;
    ListNode* curNode = head;
    while(time--){
        if(curNode == NULL)return head;
        curNode = curNode->next;
    }
    curNode = head;
    ListNode *prev = NULL, *next = curNode;
    time = k;
    while(time--){
        next = next->next;
        curNode->next = prev;
        prev = curNode;
        curNode = next;
    }
    head->next = reverseKGroup(curNode, k);
    return prev;
}