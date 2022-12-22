#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to generate random numbers


/* ========== Bubble Sort ========== */
void bubbleSort(int * a, int n){
	int done, i, temp, swap;
		for (i = 0; i < n-1; i++) { // taking pairs of elements, cant take i<n, memory overflow. There is no a[n+1]
			
			if (a[i] > a[i+1]) 
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;

	for(done = 0; done<n; done++) {

		swap = 0; 
		
		for (i = 0; i < n-1-done; i++)
			
			if (a[i] > a[i+1]) {
				// Swape these elements since they are in the wrong order
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;
				swap   = 1;
			}

		} // end of the i loop
		if(swap == 0)
			break;

	} 
}

/*	for(done = 0; done<n; done++) {
		for (i = 0; i < n-1-done; i++) {
*/

/* ========== Generate Array ========== */

int * generateArray(int n){ 
	int * t; // declaring a new address

	t = malloc( n*sizeof(int) );

	
	if(t){ 
		for (int i = 0; i < n; i++){ t[i] = rand()%1000; } 
		}

	return t;
}

/* ========== Print Array ========== */

void printArray(int *a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf(i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n){
	// Basic printing 
	for (int i = 0; i < n; i++){
		printf(" %d ", a[i]);
	}
}



int main(int argc, char **argv){
	int * a;
	int n = 10;

	
	srand(time(NULL)); 

	a = generateArray(n); 

	printArray(a, n);  
	bubbleSort(a, n); 
	printArray(a, n);

	
	free(a);
	return 0;
}
