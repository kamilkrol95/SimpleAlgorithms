// Counting sort table

#include <iostream>
#include <time.h>

using namespace std;

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

void countSort(int* tab, int n, int r){
    int* counters = new int[r];
    int* result = new int[n];

    for(int i = 0; i < r; i++) counters[i] = 0;
    for(int i = 0; i < n; i++) counters[tab[i]]++;
    for(int i = 1; i < r; i++) counters[i] += counters[i-1];
    for(int i = n-1; i >= 0; i--) result[--counters[tab[i]]] = tab[i];
    
    for(int i = 0; i < n; i++) tab[i] = result[i];
    
    delete [] counters;
    delete [] result;
}

int main(){
    int n, range;
    range = 100;
    cin >> n;
    int* tab = new int[n];

    makeTab(tab,n,range);
    printTab(tab,n);

    countSort(tab,n,range);

    printTab(tab,n);

    delete [] tab;
}