#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


struct node {
	int val;
	struct node * next; 
};


typedef struct node * NodeAddress; 


void bubbleSort(int * a, int n){
	int done, i, temp, swap; 

	for(done = 0; done<n; done++) {
		swap = 0;

		for (i = 0; i < n-1-done; i++) { 	
			if (a[i] > a[i+1]) {
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;
				swap   = 1;
			}
		} 
		if(swap == 0)
			break;
	}  
}

NodeAddress bubbleSortLinkedList(NodeAddress head){
	NodeAddress c, lastDone;
	int temp; 
	for (lastDone = NULL; lastDone != head; lastDone=c) { 
		for(c=head; c->next != lastDone; c=c->next ){
			if(c->val > c->next->val){
				temp 		 = c->val;
				c->val 		 = c->next->val;
				c->next->val = temp;
			} // end of c loop.  
		}
	}


	return head;
}

int * generateArray(int n){ 
	int * t; // declare a address
	t = malloc( n*sizeof(int) );
	if(t){ 
		for (int i = 0; i < n; i++){ t[i] = rand()%1000; } 
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n){
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;
	// special case for head
	if(n>0){
		head = malloc(sizeof(struct node));
		head->val = a[0];
		head->next = NULL;
		temp = head;
	}
	for(i=1; i<n; i++){
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}
	return head;
}

void freeLinkedList(NodeAddress head){
	NodeAddress prev;
	while(head){
		prev = head;
		head = head->next;
		free(prev); 
	}
}

void printArray(int * a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf(i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n){
	for (int i = 0; i < n; i++){
		printf(" %d ", a[i]);
	}
}
void printLinkedList(NodeAddress head){
	NodeAddress c;
	printf("Linked List = ");
	for (c = head; c; c=c->next){ 
		printf(c==head?"%d":", %d", c->val);
	}
	printf(".\n");

}

int main(int argc, char **argv){
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));
 
	a = generateArray(n);
	list = linkedListFromArray(a, n); 
	printArray(a, n); 
	bubbleSort(a, n); 
	printArray(a, n);

	printLinkedList(list);
	bubbleSortLinkedList(list);
	printLinkedList(list);
	

	
	free(a);
	freeLinkedList(list);
	return 0;
}
