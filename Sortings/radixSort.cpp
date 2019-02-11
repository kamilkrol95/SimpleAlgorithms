// Radix sort - implementacja tablicowa

#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

string makeString(int n){
    srand(time(NULL));
    string result = "";
    for(int i = 0; i < n; i++)
        result[i] = rand()%10;
    return result;
}

void makeTab(string *tab, int n, int range){
    for(int i = 0; i < n; i++)
        tab[i] = makeString(range);
}

void printTab(string *tab, int n){
    for(int i = 0; i < n; i++)
        cout << tab[i] << endl;
    printf("\n");
}

void sortByPos(string *tab, int n, int pos){
    int *cnt = new int[10];
    int *res = new int[n];

    for(int i = 0; i < 10; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[res[i]]++;
    for(int i = 1; i < 10; i++) cnt[i] += cnt[i-1];
    for(int i = n-1; i >= 0; i--)
        res[--cnt[tab[i][pos]]]
}

void radixSort(string *tab, int n, int length){
    for(int i = length-1; i >= 0; i--)
        sortByPos(tab,n,i);
}

int main(){

    int n = 10;
    int range = 10;
    string *tab = new string[n];  
    makeTab(tab,n,range);  
    printf("RADIX SORT\nRAW:\n");
    printTab(tab,n);

    radixSort(tab,n,range);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete []tab;
    return 0;
}