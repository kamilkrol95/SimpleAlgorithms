// Quick sort table

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

void swap(int* tab, int a, int b){
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

int partition(int* tab, int n, int l, int r){
    int x = tab[r];
    int j = l-1;
    for(int i = l; i < r; i++)
        if(tab[i] < x)         
            swap(tab,++j,i);      

    swap(tab,j+1,r);
    return j+1;
}

void quickSort(int* tab, int n, int l, int r){
    if(l < r){
        int q = partition(tab,n,l,r);
        quickSort(tab,n,l,q-1);
        quickSort(tab,n,q+1,r);
    }
}

/* void quickSort(int* tab, int n, int l, int r){
    while(l < r){
        int q = partiton(tab,n,l,r);
        quickSort(tab,n,l,q-1);

    }
} */

int main(){
    int n, range;
    range = 100;
    cin >> n;
    int* tab = new int[n];

    makeTab(tab,n,range);
    printTab(tab,n);

    quickSort(tab,n,0,n-1);

    printTab(tab,n);
    delete [] tab;
}