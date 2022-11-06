#include<stdio.h> // this is the header file for input and output
int main() { // this is the main function
    int i,j,temp,a[5]; // we declare the variables
    printf("Enter the 5 number of array: "); // we ask the user to enter the 5 numbers
    scanf("%d",&a[i]); // we take the input from the user
    for(i=0;i<5;i++){ // this is the for loop to take input from the user
        scanf("%d",&a[i]); //  this is to store the numbers in the array 
        for (j=0;j<i;j++) // this is the outer loop where we will compare the numbers
        {
            if (a[i]<a[j]) // this is the condition where we will compare the numbers
            {
                temp=a[i]; // here we will store the value of a[i] in temp
                a[i]=a[j]; // here we will store the value of a[j] in a[i]
                a[j]=temp; // here we will store the value of temp in a[j]
            }
        }
    for(int i=0;i<5;i++){ // this is the for loop to print the sorted array
        printf("%d ",a[i]); // this is to print the sorted array
    }
    return 0; // this is to return the value 0
}
