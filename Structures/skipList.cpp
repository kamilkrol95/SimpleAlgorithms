// Skip List

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;


struct SLnode{
    int key;
    int height;
     SLnode** next;
};

struct SkipList{
    SLnode* head;
    SLnode* end;
    int maxLevel;
};

int getLevel(int maxLevel){
    int h = 0;
    double p = 0.75;
    while(h < maxLevel && rand() / (RAND_MAX + 1.) < p)
        h++;
    return h;
}

SLnode* newNode(int val, int maxHeight){
    SLnode* newNode = new SLnode;
    newNode->key = val;
    newNode->height = getLevel(maxHeight);
    // newNode->next[newNode->height] = NULL;
    newNode->next = NULL;
    printf("jestem1 %d\n",newNode->height);

    return newNode;
}

void insert(SkipList*& list, int val){
    SLnode* it = list->head;
    // int l = getLevel(list->maxLevel);
    // SLnode* tmp = new SLnode;
    // tmp->key = val;
    // tmp->height = l;
    // tmp->next = new SLnode*[l];
    SLnode* tmp = newNode(val,list->maxLevel);
    printf("tu\n");
    for(int i = list->maxLevel-1; i >= 0; i--){
        while(it->next[i] != NULL && it->next[i]->key < val)
            it = it->next[i];
        if(i < tmp->height){
            tmp->next[i] = it->next[i];
            it->next[i] = tmp;
        }
    }
}

SkipList* createSL(int height){

    SLnode* first = newNode(-2,height);
    SLnode* last = newNode(102,height);
    first->height = last->height = height-1;
   
    SkipList* newList = new SkipList; 
    newList->maxLevel = height;
    newList->head = first;
    newList->end = last;
    printf("v1: %d\n",newList->head->key);
    printf("v2: %d\n",newList->end->key);
    for(int i = 0; i < height; i++){ 
        newList->head->next[i] = newList->end;
        newList->end->next[i] = NULL;
    }
    printf("cos\n");
    return newList;
}

void makeSL(SkipList*& list, int n, int range){
    for(int i = 0; i < n; i++)
        insert(list,rand()%range);
        
}

void printSL(SkipList* list){
    SLnode* it = list->head;
    while(it->next != NULL){
        printf("%d ",it->key);
        it = it->next[0];
    }
}
int main(){
    srand(time(NULL));
    int n, range = 100, h = 6;
    cin >> n;
    
    SkipList* sList = createSL(h);
    makeSL(sList,n,range);

    printSL(sList);
}