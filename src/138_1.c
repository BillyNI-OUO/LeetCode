/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

typedef struct Node Node;
Node* newNode(int val){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

struct Node* copyRandomList(struct Node* head) {
	Node *newHead, *curNode, *newCurNode;
	curNode = head;
    if(head == NULL)return NULL;
	while(curNode != NULL){
		newCurNode = newNode(curNode->val);
		newCurNode->next = curNode->next;
		curNode->next = newCurNode;
		newCurNode->random = curNode->random;
		curNode = newCurNode->next;
	}
    /*
	newCurNode = newNode(curNode->val);
	if(newHead == NULL)newHead = newCurNode;
	newCurNode->next = curNode->next;
	curNode->next = newCurNode;
	newCurNode->random = curNode->random;
    */
    newHead = head->next;
	curNode = newHead;
	while(curNode != NULL){
		if(curNode->random != NULL)
            curNode->random = curNode->random->next;
        if(curNode->next != NULL)curNode = curNode->next->next;
	    else
            curNode = curNode->next;
    }
	curNode = newHead;
	while(curNode->next != NULL && curNode != NULL){
		curNode->next = curNode->next->next;
        curNode = curNode->next;
	}
   return newHead;
}