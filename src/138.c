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
Node *o_nodelist[10001];
int findNode(Node *curNode, int size){
    for(int i = 0; i <= size; i ++){
        if(curNode == NULL)return size;
        if(o_nodelist[i] == curNode)return i;
    }
    return 0;
}
struct Node* copyRandomList(struct Node* head) {
    
    Node *curNode = head;
    int cnt = 0;
    while(curNode->next != NULL){
        o_nodelist[cnt++] = curNode;
        curNode = curNode->next;
    }
    int size = cnt;
    o_nodelist[size] = NULL;
    Node *newHead = NULL;
    Node *last = NULL;
    Node *a_nodelist[10001];
    curNode = head;
    cnt = 0;
    while(curNode->next != NULL){
        last = newNode(curNode->val);
        a_nodelist[cnt++] = last;
        if(newHead == NULL)
            newHead = last;
        curNode = curNode->next;
        last = last->next;
    }
    last = NULL;
    cnt = 0;
    curNode = head;
    while(cnt < size){
        int index = findNode(curNode->random, size);
        a_nodelist[cnt]->random = a_nodelist[index];
        curNode = curNode->next;

    }
    return newHead;
}