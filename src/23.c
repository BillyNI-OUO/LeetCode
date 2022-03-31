//Merge k Sorted Lists
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
    struct cmp{
        bool operator()(pair<int, ListNode*> a, pair<int, ListNode*> b){
            return a.first > b.first;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp> pq;
        
        for(int i = 0; i < lists.size(); i ++){
            if(lists[i] != nullptr)
                pq.push({lists[i]->val, lists[i]});
            }   
        

        ListNode *head = nullptr, *preNode = nullptr, *newNode;
        
        while(!pq.empty()){
            auto temp = pq.top();
            int val = temp.first;
            ListNode *curListNode = temp.second;
            pq.pop();
            
            if(curListNode->next != nullptr){
                curListNode = curListNode->next;
                pq.push({curListNode->val, curListNode});
            }
            
            newNode = new ListNode(val);
            if(preNode != nullptr)
                preNode->next =newNode;
            else 
                head = newNode;
            preNode = newNode;
        }

        return head;
    }

};