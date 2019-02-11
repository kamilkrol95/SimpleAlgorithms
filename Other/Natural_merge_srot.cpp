#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 8;

void merge(int T[], int l, int p, int q){
	int *tab = NULL;
	tab = new int[N];
	
	int i = l;
	int j = p;
	int k = 0;
	
	while(i < p && j <=q){
		if(T[i] < T[j]){
			tab[k] = T[i];
			i++;
		}
		else{
			tab[k] = T[j];
			j++;
		}
		k++;
	}
	
	if(i == p)
		while(j <= q){
			tab[k] = T[j]; 
			j++; k++;
		}
	else
		while(i < p){
			tab[k] = T[i];
			i++; k++;
		}	
	
/*	cout << "merge:" << endl;
	for(int i = 0; i < k; i++)
		cout << i << ". " << tab[i] << endl;
*/		
	k = 0;
	for(int i = l; i <= q; i++){
		T[i] = tab[k];
		k++;
	}
	delete[] tab;
}

void natural_merge_sort(int T[], int N){
	int l; //poczatek 1 serii
	int p; //poczatek 2 serii
	int q; //element za 2 seria
	
	while(true){
		l = 0;
		while(l < N){
			p = l+1;
			while(p < N && T[p-1] <= T[p]) p++;
			q = p+1;
			while(q < N && T[q-1] <= T[q]) q++;
			merge(T,l,p,q-1);
						
			if(l == 0 && p >= N) return;
			l = q;
		}
	}
}

int main(){
		
	int tab[N];
	int l,p,q;
	cout << "Start" << endl;
	//cout << "Podaj l > 0, q" << endl;
	//cin >> l >> q;
	
	srand(time(0));
	
	for(int i = 0; i < N; i++){
		tab[i] = rand()%100;
		cout << i << ". " << tab[i] << endl;
	}	
	cout << endl << "--------" << endl;	

	natural_merge_sort(tab,N);
	
	for(int i = 0; i < N; i++)
		cout << i << ". " << tab[i] << endl;
	
	return 0;
}
