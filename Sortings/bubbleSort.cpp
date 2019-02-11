// Bubble sort - implementacja tablicowa

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

void bubbleSort(int *tab, int n){
    for(int i = 0 ; i < n; i++){
        for(int j = 1; j < n; j++){
            if(tab[j-1] > tab[j]){
                int tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;
            }
        }
    }
}

int main(){

    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("BUBBLE SORT\nRAW:\n");
    printTab(tab,n);
    bubbleSort(tab,n);
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete []tab;
    return 0;
}