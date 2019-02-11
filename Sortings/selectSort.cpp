// Select sort - implementacja tablicowa

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

void selectSort(int * tab, int n){
    for(int i = 1; i < n; i++){
        int min = i-1;
        for(int j = i; j < n; j++)
            if(tab[j] < tab[min]) min = j;
        swap(tab,i-1,min);        
    }
}

int main(){
    
    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("SELECT SORT\nRAW:\n");
    printTab(tab,n);

    selectSort(tab,n);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}