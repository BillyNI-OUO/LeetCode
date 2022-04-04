//Swapping Nodes in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curNode, *targetHead, *targetTail;
        int cnt = 0, targetTailCnt = 0;
        int targetHeadValue , targetTailValue = 0;
        curNode = head;
        while(curNode != nullptr){
            cnt++;
            curNode = curNode->next;
        }
        if(cnt < 2)return head;
        targetTailCnt = cnt - k + 1;
        curNode = head;
        cnt = 0;
        while(curNode != nullptr){
            cnt++;
            if(cnt == k){
                targetHead = curNode;
                targetHeadValue = curNode->val;
            }if(cnt == targetTailCnt){
                targetTail = curNode;
                targetTailValue = curNode->val;
            }
            curNode = curNode->next;
        }
        targetTail->val = targetHeadValue;
        targetHead->val = targetTailValue;
        return head;
    }
};