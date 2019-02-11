#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
const int n = 26;
int size = 10;

void make(int t[]){
	srand(time(0));
	for(int i = 0; i < n; i++)
		t[i] = 0;
	for(int i = 1; i <= size; i++)
		t[i] = rand()%100;		
}


void write(int t[]){
	for(int i = 1; i < n; i++)
		printf("%d ",t[i]);
}

int move_one(int t[], int i, int k){
	int tmp;
	if(i+k < n){
		tmp = t[i+k];
		t[i+k] = t[i];
	}	
	else{
		tmp = t[i+k-n];
		t[i+k-n] = t[i];
	}
	return tmp;
}

void move(int t[], int k){
	int tmp;
	int i = 0;
	int j = i;
	while(i != j){
		tmp = move_one(t,i,k);
			
	}
	
	move(t,k);
}


int main(){
	
	int* tab = new int[n];
	
	make(tab);
	write(tab);
	move(tab,2);
	printf("\n\n");
	write(tab);
	delete tab;
	return 0;
}
