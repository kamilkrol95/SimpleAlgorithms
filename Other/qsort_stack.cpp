#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class stack{
	
	int t = 0;
	int *S = new int[n]; 
	
	public: 
	int n;
	int top(){
		return t;
	}
	bool empty(){
		if (top() == 0) return true;
		else return false;
	}
	
	void push( int x){
		t++;
		S[top()] = x;
	}
	
	int pop( ){
		if (empty()) printf("Stos pusty!\n");
		else{
			t--;
			return S[t+1];
		}
	}
};

void make(int tab[], int n, int k){
    srand(time(0));
    for(int i = 0; i < n; i++)
        tab[i] = rand()%k;
}

void write(int tab[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]); 
    printf("\n");
}

void swap(int tab[], int a, int b){
	int tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
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

void qsort_stack(int tab[], int n){
	stack Q;
	Q.n = n;
	Q.push(0);
	Q.push(n-1);
	//printf("%d\n",Q.pop());
	while(!Q.empty()){
		printf("jestem -> %d\n",Q.top());
		int r = Q.pop();
		int p = Q.pop();
		int q = partition(tab,p,r);
		
		if(p < q){
			Q.push(p);
			Q.push(q);
		}
		if(q+1 < r){
			Q.push(q+1);
			Q.push(r);
		}
		//int a = Q.pop();
		
	}
}

int main(){

	int n = 10;
	int *tab = new int[n];
	
	make(tab,n,10);
	write(tab,n);
	qsort_stack(tab,n);
	//swap(tab,1,3);
	write(tab,n);
	return 0;
}
