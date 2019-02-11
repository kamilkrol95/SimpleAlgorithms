// Selection sort list

#include <iostream>
#include <time.h>

using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* newNode(int v){
    Node* tmp = new Node();
    tmp->val = v;
    tmp->next = NULL;
    return tmp;
}

Node* makeList(int n, int range){
    if(n < 1) return NULL;
    Node* tmp = new Node();
    Node* head = tmp;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        tmp->next = newNode(rand()%range);
        tmp = tmp->next;
    }
    return head;
}

void printList(Node* head){
    if(head->next == NULL) return;
    else head = head->next;
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}
Node* findMax(Node* list){
    if(list->next == NULL) return NULL;
    Node* prevMax = list;
    while(list->next != NULL){
        if(list->next->val >= prevMax->next->val)
            prevMax = list;
        list = list->next;   
    }
    // printf("-> %d\n",prevMin->next->val);
    Node* max = prevMax->next;
    prevMax->next = max->next;
    max->next = NULL;
    return max;
}

Node* selectSort(Node* list){
    if(list == NULL) return NULL;
    Node* sortedList = new Node();
    sortedList->next = NULL;
    while(list->next != NULL){
        Node* tmp = findMax(list);
        tmp->next = sortedList->next;
        sortedList->next = tmp;
    }
    delete list;
    return sortedList;
}

int main(){
    int n, range = 100;
    cin >> n;

    Node* list = makeList(n,range);
    printList(list);

    Node* sortedList = selectSort(list);
    printList(sortedList);
}