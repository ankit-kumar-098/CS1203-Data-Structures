#include <stdio.h>
#include <stdlib.h>

int * bl(int val){
	int x;
	int * pointer = &x;
	x = val * val;
	return pointer;
}

int main(int argc, char **argv){
	int * b = bl(5);
	printf("%d.\n", *b);  
	return 0;
}
