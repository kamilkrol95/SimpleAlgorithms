// Insert sort - implemetnacja tablicowa

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

void insertSort(int * tab, int n){
    for(int i = 1; i < n; i++){
        int key = tab[i];
        int j = i-1;
        while (j >= 0 && tab[j] > key){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = key;
    }
}

int main(){
    
    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("INSERT SORT\nRAW:\n");
    printTab(tab,n);

    insertSort(tab,n);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}