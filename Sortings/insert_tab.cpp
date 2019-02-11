// Insertion sort table

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

void sort(int* tab, int n){
    for(int i = 1; i < n; i++){
        int tmp = tab[i];
        int j = i-1;
        while(j >= 0 && tab[j] > tmp){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = tmp;
    }
}

int main(){
    int n, range;
    range = 100;
    cin >> n;
    int* tab = new int[n];

    makeTab(tab,n,range);
    printTab(tab,n);

    sort(tab,n);
    printf("\n");
    printTab(tab,n);
}