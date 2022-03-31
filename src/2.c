struct ListNode {
    int val;
    struct ListNode *next;
};
 
typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    else if(l2 == NULL) return l1;
    ListNode *newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
     
    int value = l1->val + l2->val;
    
    newNode->val = value;
    if(value >= 10){
        newNode->val = value - 10;
        ListNode *carryout;
        carryout = (ListNode*)malloc(sizeof(ListNode));
        carryout->val = 1;
        carryout->next = NULL;
        if(l1->next == NULL && l2->next == NULL){
            newNode->next = carryout;
            return newNode;
        }
        else if(l1->next != NULL && l2->next != NULL){
            l1->next->val += 1;
            newNode->next = addTwoNumbers(l1->next, l2->next);
        }
        else if(l1->next != NULL) newNode->next = addTwoNumbers(l1->next, carryout);
        else if(l2->next != NULL) newNode->next = addTwoNumbers(l2->next, carryout);
        
    }
    else newNode->next = addTwoNumbers(l1->next, l2->next);
    return newNode;
}

ListNode* makeNode(int val){
    ListNode *carryout;
    carryout = (ListNode*)malloc(sizeof(ListNode))
    carryout->val = val;
    carryout->next = NULL;
    return carryout;
}

void printans(ListNode* list){
    ListNode *cur = list;
    while(cur != NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("/n");
}

int main(){
    ListNode *l1, *l2;
    l1 = makeNode(2);
    l1->next = makeNode(4);
    l1->next->next = makeNode(3);
    l2 = makeNode(5);
    l2->next = makeNode(6);
    l2->next->next = makeNode(4);
    ListNode *ans;
    ans = addTwoNumbers(l1, l2);
    printlist(ans);

}