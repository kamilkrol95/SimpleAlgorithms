// Sorotowanie listy metodą prostego wybierania
// Selection Sort listy

#include <iostream>
#include <time.h>

struct node{
    int v;
    node* next;
};

node* makeList(int n, int range){
    srand(time(NULL));
    node* head = new node();
    node* res = head;
    for(int i = 0; i < n; i++){
        node* tmp = new node();
        tmp->v = rand()%range;
        tmp->next = NULL;
        head->next = tmp;
        head = head->next;
    }
    return res;
}

void writeList(node* head){
    if(head->next == NULL) return;
    else head = head->next;
    while(head != NULL){
        printf("%d ",head->v);
        head = head->next;
    }
    printf("\n");
}

node* findMax(node* p){
    if(p == NULL) return NULL;
    if(p->next == NULL) return p;

    node* prev = p;
    p = p->next;
    node* before_max = prev;

    while(p != NULL){
        if(p->v > before_max->next->v)
            before_max = prev;
        prev = p;
        p = p->next;
    }

    node* max = before_max->next;
    if(max != NULL)
        before_max->next = max->next;

    return max;
}

node* selectSort(node* p){
    node* newFirst = new node;
    newFirst->next = p;
    node* result = NULL;

    while(newFirst->next != NULL){
        node* tmp = findMax(newFirst);
        tmp->next = result;
        result = tmp;
    }

    delete newFirst;
    return result;
}

int main(){

    int n = 10;
    int range = 100;
    node* head = makeList(n,range);
    printf("Select Sort\nRAW:\n");
    writeList(head);
    node* sortedList = selectSort(head);
    printf("SORT:\n");
    writeList(sortedList);
    return 0;
}