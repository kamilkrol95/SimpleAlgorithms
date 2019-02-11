// Sprawdzanie czy w posortowanej tablicy znajduja sie elementy o sumie t[i] + t[j] = k

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

void sort(int *tab, int n, int r){
    int *res = new int[n];
    int * cnt = new int[r];

    for(int i = 0; i < r; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[tab[i]]++;
    for(int i = 1; i < r; i++) cnt[i] += cnt[i-1];
    for(int i = n-1; i >= 0; i--)
        res[--cnt[tab[i]]] = tab[i];

    for(int i = 0; i < n; i++)
        tab[i] = res[i];
}

bool search(int *tab, int n, int k){
    int i, j, sum = 0;
    i = 0;
    while(tab[i] <= k) i++;
    j = i; i = 0;
    while(i != j){
        if(tab[i] + tab[j] == k) return true;
        if(tab[i] + tab[j] > k) j--;
        else i++;
    }
    return false;
}

int main(){

    int n = 10;
    int range = 100;
    int k = 25;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printTab(tab,n);
    sort(tab,n,range);
    printTab(tab,n);
    
    if(search(tab,n,k)) printf("JEST\n");
    else printf("NIE MA\n");

    return 0;
}