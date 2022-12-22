#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition(int *arr, int start, int end){
    int pivot = arr[start]; // pivot
    int wall = start; 
    int scout = start+1;        
    while(scout <= end){
        if(arr[scout] < pivot){
            wall++;                         
            int swap_temp = arr[wall];
            arr[wall] = arr[scout];
            arr[scout] = swap_temp;
        }
        scout++;                            
    }
    int swap_temp = arr[wall];
    arr[wall] = arr[start];
    arr[start] = swap_temp;

    return wall;
}
void quickSort(int *arr, int low, int high){
    if(low <= high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}


int * generateArray(int n){ 
    int * t; // declaring a new address
    t = (int *) malloc(n*sizeof(int)); // allocating memory for the array
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; // rand()%1000 for a smaller number, all between 0 and 999
        } 
    }
    return t; 
}


void printArray(int *a, int n){
    printf("Array = ");
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

/* ========== main() ========== */
int main(int argc, char **argv){
	int * a;
	int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

	
	srand(time(NULL));  

	a = generateArray(n); 
	printArray(a, n);  

	quickSort(a, 0, n-1);   
	
    printArray(a, n);
	free(a);
	return 0;
}
