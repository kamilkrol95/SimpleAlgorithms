#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node{
	int w;
	node* next;
};

node* lmerge(node* p1, node* p2){
	
	node* mp;
	node* head;
	//jedna z list pusta
	if(p1 == NULL) mp = p2;
	if(p2 == NULL) mp = p1;
	//g³owa zmergowanej listy
	if(p1->w < p2->w){
			mp = p1;
			p1 = p1->next;
			mp->next = NULL;
		}
		else{
			mp = p2;
			p2 = p2->next;
			mp->next = NULL;
		}
	head = mp;
	//resta mergea
	while(p1->next != NULL && p2->next != NULL){
		if(p1->w < p2->w){
			mp->next = p1;
			p1 = p1->next;
		}
		else{
			mp->next = p2;
			p2 = p2->next;
		}
		mp = mp->next;
		mp->next = NULL;
	}
	if(p1 == NULL) mp->next = p2;
	else mp->next = p1;
	
	return head;
	
}
int main(){
	
	return 0;
}

