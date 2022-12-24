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

// Inserting
int * Insertheap(int *A, int n, int k){             
    A = realloc(A, (n+1)*sizeof(int));              
    A[n] = k; 
    int i = n;
    while(i>0 && A[i]<A[(i-1)/2]){             
        swap(&A[i], &A[(i-1)/2]);              
        i = (i-1)/2;                            
    }
    return A;
    
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

// Create Minimum Heap 
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
    int n, k;
    // int *A;
    srand(time(NULL)); // random number generator
    int *A;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    A = generateArray(n); 
    printArray(A, n);
    createMinHeap(A, n);
    printf("Minimum Heap ");
    printArray(A, n);
    
    printf("Enter the element to be inserted: ");
    scanf("%d", &k);

    A = Insertheap(A, n, k);
    printArray(A, n+1);

    free(A);
    return 0;
}
