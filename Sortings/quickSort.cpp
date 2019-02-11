// Quick Sort - implementacja tablicowa 

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

int partition(int *tab, int p, int r){
    int x = tab[r];
    int j = p-1;
    for(int i = p; i < r; i++){
        if(tab[i] <= x){
            j++;
            swap(tab,j,i);
        }
    }
    swap(tab,j+1,r);
    return j+1;
}

void quickSort(int *tab, int p, int r){
    if(p < r){
        int q = partition(tab,p,r);
        quickSort(tab,p,q-1);
        quickSort(tab,q+1,r);
    }
}

int main(){
    
    int n = 5;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("QUICK SORT\nRAW:\n");
    printTab(tab,n);

    quickSort(tab,0,n-1);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}