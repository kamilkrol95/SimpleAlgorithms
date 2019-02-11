#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>

//using namespace std;

void make(int tab[], int n, int k){
    srand(10);
    for(int i = 0; i < n; i++)
        tab[i] = rand()%k;
}

void write(int tab[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]); 
    printf("\n");
}

int digit(int num, int base, int pos) {
    if(pos == 1) return num%base;
    int i = 1;
    num /= base;
    int dig = 0;
    while(num != 0 && i != pos){
    	dig = num%base;
    	num /= base;
    	i++;
	}
	return dig;
}

void sortByPosition(int tab[], int n, int pos) {
    int *counters = new int[n];
    int *result = new int[n];
	for(int i=0; i<n; i++) counters[i] = 0;
	for(int i = 0; i < n; i++) counters[digit(tab[i],n,pos)]++;
	for(int i = 1; i < n; i++) counters[i] = counters[i] + counters[i-1];
	for(int i = n-1; i >= 0; i--){
		counters[digit(tab[i],n,pos)]--;
		result[counters[digit(tab[i],n,pos)]] = tab[i];
	}
	for(int i = 0; i < n; i++) tab[i] = result[i];
   
    delete [] counters;
    delete [] result;
}

void radixSort(int tab[], int n, int length) {
	for(int i = length-1; i >= 0; i--)
		sortByPosition(tab, n, i);
    
}
int main(){

	int n = 10;
    int k = 100;
    int *tab = new int[n];
    
    make(tab,n,k);
    write(tab,n);
    radixSort(tab,n,k);
    write(tab,n);
}
