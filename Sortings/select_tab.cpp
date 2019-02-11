// Selection sort table

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

void swap(int* tab, int a, int b){
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void sort(int* tab, int n){
    for(int j = 0; j < n; j++){
        int max = j;
        for(int i = j; i < n; i++)
            if(tab[i] < tab[max])
                max = i;
        swap(tab,j,max);
    }
}

int main(){

    int n,range;
    cin >> n;
    range = 100;
    int* tab = new int[n];

    makeTab(tab,n,range);
    printTab(tab,n);

    sort(tab,n);

    printf("\n");
    printTab(tab,n);
}