// Insertion sort list

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
    srand(time(NULL));
    Node* tmp = new Node();
    Node* head = tmp;
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

void insert(Node* list, Node* el){
    if(list == NULL || el == NULL) return; 
    while(list->next != NULL && list->next->val < el->val){
        list = list->next;
    }
    el->next = list->next;
    list->next = el;
}

Node* insertSort(Node* list){
    Node* sortedList = new Node();
    sortedList->next = NULL;
    while(list->next != NULL){
        Node* tmp = list->next;
        list->next = tmp->next;
        tmp->next = NULL;
        insert(sortedList,tmp);
    }
    delete list;
    return sortedList;
}

int main(){
    int n, range = 100;
    cin >> n;
    
    Node* node = makeList(n,range);
    printList(node);

    Node* sortedHead = insertSort(node);
    printList(sortedHead);
    delete node; 
}