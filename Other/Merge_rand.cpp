#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

const int N = 30;

void swap(int T[], int a, int b){
	int tmp;
	tmp = T[a];
	T[a] = T[b];
	T[b] = tmp;
}

void merge(int T[], int l, int p, int q){
	
//	int tab[N];
	int i = l;
	int j = p;
	int k = 0;
	
	while(i < p && j <= q){
		if(T[i] > T[j]){
			//tab[k] = T[j];
			swap(T,k,j);
			j++;
		}			
		else{
			//tab[k] = T[i];
			swap(T,k,i);
			i++;
		}
		k++;
	}
	if(i == p)
		while(j <= q){
			//tab[k] = T[j];
			swap(T,k,j);
			j++; k++;
		}
	else 
		while (i < p){
			//tab[k] = T[i];
			swap(T,k,i);
			i++; k++;
		}
	cout << "merge:" << endl;
	for(int i = 0; i < k; i++)
		cout << i << ". " << T[i] << endl;
	
}

int main(){
	
	int tab[N];
	int l,p,q;
	cout << "Podaj l > 0, p, q" << endl;
	cin >> l >> p >> q;

	srand(time(0));
	for(int i = 0; i < N; i++){
		tab[i] = rand()%100;
		cout << i << ". " << tab[i] << endl;
	}	
	cout << endl << "--------" << endl;		
	for(int i = l+1; i < p; i++){
		int tmp = tab[i];
		int j = i-1;
		while(tmp < tab[j] && j >= l){
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = tmp;
	}
	
	for(int i = p; i <= q; i++){
		int tmp = tab[i];
		int j = i-1;
		while(tmp < tab[j] && j >= p){
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = tmp;
	}
	
	for(int i = 0; i < N; i++)
		cout << i << ". " << tab[i] << endl;	
		
	merge(tab,l,p,q);
	
	return 0;
}
