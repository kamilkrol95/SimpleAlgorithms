// Merge sort table

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
}

void merge(int* tab, int n, int l, int q, int r){
    int l1 = l, l2 = q+1;
    int k = l;
    int* result = new int[n];

    while(l1 <= q && l2 <= r){
        if(tab[l1] < tab[l2])
            result[k] = tab[l1++];
        else
            result[k] = tab[l2++];
        k++;
    }

    while(l2 <= r)
        result[k++] = tab[l2++];

    while(l1 <= q)
        result[k++] = tab[l1++];

    for(int i = l; i <= r; i++)
        tab[i] = result[i];

    delete [] result;
}

void mergeSort(int* tab, int n, int l, int r){
    if(l < r){
        int q = (l+r)/2;
        mergeSort(tab,n,l,q);
        mergeSort(tab,n,q+1,r);
        merge(tab,n,l,q,r);
    }
}

int main(){
    int n, range;
    range = 100;
    cin >> n;
    int* tab = new int[n];
    
    makeTab(tab,n,range);
    printTab(tab,n);

    mergeSort(tab,n,0,n-1);
    printf("\n");
    printTab(tab,n);

    delete [] tab;
}