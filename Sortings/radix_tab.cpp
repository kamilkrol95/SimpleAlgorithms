// Radix sort table

#include <iostream>
#include <time.h>
#include <string>
#include <cstring>

using namespace std;

string makeString(int size){
    srand(time(NULL));
    string result = "";
    for(int i = 0; i < size; i++)
        result[i] = rand()%10;
    return result;
}

void makeTab(string* tab, int n, int size){
    for(int i = 0; i < n; i++)
        tab[i] = makeString(size);
}

void makeIntTab(int* tab, int n, int size){
    srand(time(NULL));
    for(int i = 0; i < n; i++) tab[i] = 0;
    for(int i = 0; i < n; i++){
        for(int s = 0; s < size; s++)
            tab[i] = tab[i]*10 + rand()%9 + 1;
    }
}

void printTab(string* tab, int n){
    for(int i = 0; i < n; i++)
        cout << tab[i] << endl;
        // printf("%s\n",tab[i]);
        printf("\n");
}

void radixSort(string* tab, int n, int s){

}

int main(){
    int n, size;
    cin >> n;
    size = 6;
    string* tab = new string[n];
    printf("cos\n");
    makeTab(tab,n,size);
    printTab(tab,n);

    radixSort(tab,n,size);
    // printTab(tab,n);
    
    delete [] tab;
}