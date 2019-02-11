// Przesuwanie tablicy o n miejsc

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

void swap(int *tab, int a, int b){
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void reverse(int *tab, int l, int r){
    while(l <= r){
        swap(tab,l,r);
        l++; r--;
    }
}

void moveRight(int *tab, int n, int k){
    reverse(tab,n-k,n-1);
    reverse(tab,0,n-k-1);
    reverse(tab,0,n-1);
}

void moveLeft(int *tab, int n, int k){
    reverse(tab,0,k-1);
    reverse(tab,k,n-1);
    reverse(tab,0,n-1);
}

int main(){

    int n = 10;
    int range = 100;
    int k = 1;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printTab(tab,n);
    printf("MOVE RIGHT -->\n");
    moveRight(tab,n,k);
    printTab(tab,n);
    printf("MOVE LEFT <--\n");
    moveLeft(tab,n,k+1);
    printTab(tab,n);
    return 0;
}