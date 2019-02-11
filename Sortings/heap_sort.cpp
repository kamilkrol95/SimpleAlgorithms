// Heap sort table

#include <iostream>
#include <time.h>

using namespace std;

const int N = 6;
void makeTab(int* tab, int n, int range){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        tab[i] = rand()%range;
}

void printTab(int* tab, int n){
    for(int i = 0; i < n; i++)
        printf("%d ",tab[i]);
    printf("\n");
}

int left(int i) { return 2*i + 1; }
int right(int i) { return 2*i + 2;} 
int parent(int i) { return (i - 1)/2; }

void swap(int* tab, int a, int b){
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void heapify(int* tab, int n, int i){
    int ind_max = i;
    if(left(i) < n && tab[left(i)] > tab[ind_max])
        ind_max = left(i);
    if(right(i) < n && tab[right(i)] > tab[ind_max])
        ind_max = right(i);

    if(ind_max != i){
        swap(tab,i,ind_max);
        heapify(tab,n,ind_max);
    }   
}

void buildHeap(int* tab, int n){
    for(int i = parent(n-1); i >= 0; i--)
        heapify(tab,n,i);
}

void heapSort(int* tab, int n){
    buildHeap(tab,n);
    for(int i = n-1; i > 0; i--){
        swap(tab,0,i);
        heapify(tab,i,0);           
    }
}

int main(){
    int n, range;
    range = 100;
    cin >> n;
    int* tab = new int[n];

    makeTab(tab,n,range);
    printTab(tab,n);

    heapSort(tab,n);
    printTab(tab,n);

    delete [] tab;
}