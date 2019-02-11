// Heap Sort - implementacja tablicowa

#include <iostream>
#include <time.h>

void makeTab(int *tab, int n, int range){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        tab[i] = rand()%range;
}

void printTab(int *tab, int n){
    for(int i = 0; i < n; i++)
        printf("%d ",tab[i]);
    printf("\n");
}

void swap(int *A, int a, int b){
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int left(int i) { return 2*i; }
int right(int i) { return 2*i+1; }
int parent(int i) { return (i-1)/2; }

void heapify(int *tab, int n, int i){
    int ind_max = i;
    if(left(i) < n && tab[left(i)] > tab[ind_max])
        ind_max = left(i);
    if(right(i) < n && tab[right(i)] > tab[ind_max])
        ind_max = right(i);
    
    if(i != ind_max){
        swap(tab,i,ind_max);
        heapify(tab,n,ind_max);
    }

}

void buildHeap(int *tab, int n){
    for(int i = parent(n-1); i >=0 ; i--)
        heapify(tab,n,i);
}

void heapSort(int *tab, int n){
    buildHeap(tab,n);
    for(int i = n-1; i > 0; i--){
        swap(tab,0,i);
        heapify(tab,i,0);
    }
}   

int main(){
    
    int n = 5;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("HEAP SORT\nRAW:\n");
    printTab(tab,n);

    heapSort(tab,n);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}