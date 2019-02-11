// Bubble sort table

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
    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(tab[j-1] > tab[j]){
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;
            }
        }
    }
}

int main(){

    int n, range;
    cin >> n;
    range = 100;
    int* tab = new int[n];
    
    makeTab(tab,n,range);
    printTab(tab,n);

    sort(tab,n);
    cout << "\n";
    printTab(tab,n);

}