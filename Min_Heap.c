#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Swap 
void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

// Generate Array
int * generateArray(int n){ 
    int * t; 
    t = (int *) malloc(n*sizeof(int)); 
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; 
        } 
    }
    return t; 
}
// Print Array 
void printArray(int *a, int n){
    printf("Array = ");
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

void createMinHeap(int * A, int n){    
    int i, j, k;
    for(i = 0; i < n; i++){     
        k = i;                 
        do{                     
            j = (k - 1) / 2;        
            if(A[j] > A[k]){        
                swap(&A[j], &A[k]);
            }
            k = j;                 
        }while(k != 0);            
    }
}

int main(int argc, char const *argv[])
{
    int n;
    // int *A;
    srand(time(NULL)); 
    int *A;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    A = generateArray(n); 
    printArray(A, n);
    makeMinHeap(A, n);

    printArray(A, n);
    free(A);
    return 0;
}
