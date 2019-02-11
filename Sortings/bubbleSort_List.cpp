// Bubble sort - lista

#include <iostream>
#include <time.h>

struct node{
    int val;
    node* next;
};

node* makeList(int n, int range){
    srand(time(NULL));
    node* head = new node();
    node* tmpHead = head;
    for(int i = 0; i < n; i++){
        node* tmp = new node();
        tmp->val = rand()%range;
        tmp->next = NULL;
        head->next = tmp;
        head = head->next;
    }
    return tmpHead;
}

void writeList(node* head){
    if(head->next == NULL) return;
    else head = head->next;
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
}

node* bubbleSort(node* head, int n){
    node* tmpHead = head->next;
    node* tmpPrev = head;
    for(int i = 0; i < n; i++){
        node* curr = tmpHead;
        node* prev = tmpPrev;
        while(curr != NULL){
            if(curr->val >= curr->next->val){
                printf("%d %d\n",curr->val, curr->next->val);
                node* tmp = curr->next;
                prev->next = tmp;
                curr->next = tmp->next;
                tmp->next = curr;
            }
            prev = curr;
            curr = curr->next;             
        }
    }
    return tmpPrev;
}

int main(){

    int n = 10;
    int range = 100;
    node* head = makeList(n,range);
    printf("BUBBLE SORT LIST\nRAW:\n");
    writeList(head);
    node* sortList = bubbleSort(head,n);
    printf("SORTED:\n");
    writeList(sortList);
    return 0;
}