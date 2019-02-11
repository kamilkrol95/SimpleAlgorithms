#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 8;

void merge(int T[], int l, int p, int q){
	int tab[N];
	int i = l;
	int j = p;
	int k = 0;
	
	while(i < p && j <= q){
		if(T[i] >= T[j]){
			tab[k] = T[j];
			j++; 
		}			
		else{
			tab[k] = T[i];
			i++;
		}
		k++;
	}
	if(i == p)
		while(j <= q){
			tab[k] = T[j];
			j++; k++;
		}
	else 
		while (i < p){
			tab[k] = T[i];
			i++; k++;
		}
		
/*	cout << "merge:" << endl;
	for(int i = 0; i < k; i++)
		cout << i << ". " << tab[i] << endl;
*/	
	k=0;
	for(int i = l; i <= q; i++){
			T[i] = tab[k];
			k++;
	}
	
}

void merge_sort(int T[], int l, int q){
		
		int p = (l+q)/2;
		if(l < p){
			merge_sort(T,l,p);
		}
		if(p+1 < q){
			merge_sort(T,p+1,q);
		}
		merge(T,l,p+1,q);
}

int main(){
	
	int tab[N];
	int l,p,q;
	cout << "Podaj l > 0, q" << endl;
	cin >> l >> q;
	
	srand(time(0));
	
	for(int i = 0; i < N; i++){
		tab[i] = rand()%100;
		cout << i << ". " << tab[i] << endl;
	}	
	cout << endl << "--------" << endl;	

	merge_sort(tab,l,q);
	
	for(int i = 0; i < N; i++)
		cout << i << ". " << tab[i] << endl;
	
	return 0;
}
