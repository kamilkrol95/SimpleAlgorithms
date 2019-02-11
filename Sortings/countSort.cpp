// Count sort - implementacja tablicowa

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

void countSort(int *tab, int n, int r){
    int *res = new int[n];
    int *cnt = new int[r];

    for(int i = 0; i < r; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[tab[i]]++;
    for(int i = 1; i < r; i++) cnt[i] += cnt[i-1];
    for(int i = n-1; i >=0; i--)
        res[--cnt[tab[i]]] = tab[i];

    for(int i = 0; i < n; i++)
        tab[i] = res[i];
    
    delete [] cnt;
    delete [] res;
}

int main(){

    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("COUNTING SORT\nRAW:\n");
    printTab(tab,n);

    countSort(tab,n,range);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete []tab;
    return 0;
}