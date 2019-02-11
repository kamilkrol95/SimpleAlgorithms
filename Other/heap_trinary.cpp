#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
const int n = 41;
int size = 16;
#define SIZE 16
void make(int t[]){
	srand(time(0));
	
	for(int i = 1; i <= SIZE; i++)
		t[i] = rand()%100;		
}

void write(int t[]){
	int nl = 1;
	for(int i = 1; i <= SIZE; i++){
		printf("%d\t",t[i]);
		if(i == nl){
			printf("\n");
			nl = nl*3+1;
		} 
		
	}		
}

void writeline(int t[]){
	for(int i = 1; i <= SIZE; i++)
		printf("%d ",t[i]);
}

void swap(int t[], int a, int b){
	int tmp = t[a];
	t[a] = t[b];
	t[b] = tmp;
}

int parent(int i){
	if(i%3 == 2) return i/3 + 1;
	return i/3;	
} 
int left(int i){
	return i*3 - 1;
} 
int mid(int i){
	 return i*3;
}
int right(int i){
	 return i*3 + 1;
}

void heapify(int t[], int i){
	int l = left(i);
	int m = mid(i);
	int r = right(i);
	int max = i;
	
	if(l <= size && t[l] > t[max])
		max = l;
	if(m <= size && t[m] > t[max])
		max = m;
	if(r <= size && t[r] > t[max])
		max = r;
	
	if(max != i){
		swap(t,i,max);
		heapify(t,max); 	
	}
		
}

void build_heap(int t[]){
	for(int i = parent(size); i > 0; i--)
		heapify(t,i);		
}

void heap_sort(int t[]){
	build_heap(t);
	for(int i = size; i > 1; i--){
		swap(t,1,i);
		size--;
		heapify(t,1);
	}
}

int heap_max(int t[]){
	return t[1];
}

int heap_extract_max(int t[]){
	if(size < 1){
		printf("Kopiec pusty\n");
		return 1;
	}
	int max = t[1];
	swap(t,1,size);
	size--;
	heapify(t,1);
	return max;
}

void heap_increase_key(int t[],int i, int key){
	if(key < t[i]){
		printf("Klucz musi byæ wiêkszy od poprzedniego!\n");
		return;
	}
	t[i] = key;
	while(i > 1 && t[i] > t[parent(i)]){
		swap(t,i,parent(i));
		i = parent(i);
	}
}
int main() {
    
    int* tab = new int[n];
    
    make(tab);
    writeline(tab);
    printf("\n\n");
    write(tab);
    //printf("l: %d m: %d r: %d \n",tab[left(2)],tab[mid(2)],tab[right(2)]);
    //printf("%d %d\n",tab[5],tab[7]);
    heap_sort(tab);
    printf("\n\n\n");
    write(tab);
    printf("\n\n");
 	writeline(tab);
   
	delete tab;
}
