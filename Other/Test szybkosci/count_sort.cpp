// czas liniowy O(n+k)
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

double ob_sek(clock_t czas){
    return static_cast <double>(czas)/CLOCKS_PER_SEC*1000.0;
}

void rewrite(int tab1[], int tab2[], int n){
    for(int i = 0; i < n; i++)
        tab2[i] = tab1[i];
}

void swap(int tab[], int a, int b){
    int tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void countSort(int tab[], int n, int k){
    int *counters = new int[k];
    int *result = new int[n];

    for(int i = 0; i < k; i++) counters[i] = 0;
    for(int i = 0; i < n; i++) counters[tab[i]]++;
    for(int i = 1; i < k; i++) counters[i] = counters[i] + counters[i-1];
    for(int i = n-1; i >= 0; i--){
        counters[tab[i]]--;
        result[counters[tab[i]]] = tab[i];        
    }
    for(int i = 0; i < n; i++) tab[i] = result[i];

    delete [] result;
    delete [] counters;
}

int partition(int tab[], int p, int r){
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

void quickSort(int tab[], int p, int r){
    if(p < r){
        int q = partition(tab,p,r);
        quickSort(tab,p,q-1);
        quickSort(tab,q+1,r);
    }
}

int main(){
    double start_prog = ob_sek(clock());
    printf("Start: %.4f\n",start_prog);
	std::fstream plik, plik_c, plik_q;
	plik.open("dane.txt", std::ios::in | std::ios::out);
	plik_c.open("czas_c.txt", std::ios::in | std::ios::out);
	plik_q.open("czas_q.txt", std::ios::in | std::ios::out);
	if(plik.good()){
		for(int j = 10; j <= 1000; j+=10){
	   		for(int i = 50; i <= 10000; i+=2){
	        
	            int n = i;
	            int k = 100;
	            int *tab = new int[n];
	            int *count_tab = new int[n];
	            int *quick_tab = new int[n];
	            
	            make(tab,n,k);
	            //write(tab,n);
	            rewrite(tab,count_tab,n);
	            rewrite(tab,quick_tab,n);
	            
	            // count sort
	            double start_c = ob_sek(clock());
	            countSort(count_tab,n,k);
	            //write(count_tab,n);
	            double stop_c = ob_sek(clock());
	            double czas_c = stop_c - start_c;
	            // quick sort
	            double start_q = ob_sek(clock());
	            quickSort(quick_tab,0,n-1);
	            //write(quick_tab,n);
	            double stop_q = ob_sek(clock());
	            double czas_q = stop_q - start_q;
	
	            delete [] count_tab;
	            delete [] quick_tab;
	            delete [] tab;
	            if(n > 4)
	            if(czas_c-czas_q > 0){
	              //  printf("N: %d\tK: %d\n",n,k);
	                //printf("Czas countSort: %.4f\n",czas_c);
	               // printf("Czas quickSort: %.4f\n",czas_q);
	                plik << n << "\t" << k << std::endl;
	                plik_c << n << "\t" << czas_c << std::endl;
	                plik_q << n << "\t" << czas_q << std::endl;
	                plik.flush(); plik_c.flush(); plik_q.flush();
	                break;
	            }
	        }
	    }
	    plik.close();
	    plik_c.close();
	    plik_q.close();
	}	
    
    double stop_prog = ob_sek(clock());
    printf("Stop: %.4f\n",stop_prog);
    double czas_prog = stop_prog - start_prog;
    printf("Czas wykonania: %.4f\n",czas_prog);
//    printf("Czas countSort: %.4f\n",czas_c);
//    printf("Czas quickSort: %.4f\n",czas_q);
    return 0;
}
