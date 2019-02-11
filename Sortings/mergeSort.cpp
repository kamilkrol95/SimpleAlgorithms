// Merge Sort - implementacja tablicowa

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

void merge(int *tab, int n, int l, int q, int r){
    int *T = new int[n];
    int k = l;
    int l1 = l, l2 = q+1;
    while(l1 <= q && l2 <= r){
        if(tab[l1] < tab[l2])
            T[k] = tab[l1++];
        else
            T[k] = tab[l2++];
        k++;
    }

    while(l2 <= r)
        T[k++] = tab[l2++];

    while(l1 <= q)
        T[k++] = tab[l1++];
        
    for(int i = l; i <= r; i++)
        tab[i] = T[i];
    
    delete [] T;
}

void mergeSort(int * tab, int n, int l, int r){
    if(l < r){
        int q = (l+r)/2;
        mergeSort(tab,n,l,q);
        mergeSort(tab,n,q+1,r);
        merge(tab,n,l,q,r);
    }
}

int main(){
    
    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("MERGE SORT\nRAW:\n");
    printTab(tab,n);

    mergeSort(tab,n,0,n-1);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}