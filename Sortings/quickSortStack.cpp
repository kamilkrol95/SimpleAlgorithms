// Quick sort with stack

#include <iostream>
#include <time.h>
#include <stack>

using namespace std;

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

void swap(int *A, int a, int b){
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int partition(int *tab, int n, int p, int r){
    int x = tab[r];
    int j = p-1;
    for(int i = p; i < r; i++){
        if(tab[i] <= x){
            j++; 
            swap(tab,i,j);
        }
    }
    swap(tab,j+1,r);
    return j+1;
}

void quickSort(int *tab, int n){
    stack<int> S;

    S.push(0);
    S.push(n-1);

    while(!S.empty()){
        int r = S.top(); S.pop();
        int p = S.top(); S.pop();
        int q = partition(tab,n,p,r);

        if(p < q){
            S.push(p);
            S.push(q-1);            
        }
        if(q+1 < r){
            S.push(q+1);
            S.push(r);
        }
    }
}

int main(){
    
    int n = 10;
    int range = 100;
    int *tab = new int[n];  
    makeTab(tab,n,range);  
    printf("QUICK SORT\nRAW:\n");
    printTab(tab,n);

    quickSort(tab,n);
    
    printf("SORTED:\n");
    printTab(tab,n);
        
    delete [] tab;
    return 0;
}
