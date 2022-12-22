#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
    int val;
    struct Node * next;
};

typedef struct Node * NodeAddress;  

void InsertNewElement(NodeAddress head, int x)
{
    // Create a new node
    NodeAddress newnode = malloc(sizeof(struct Node));
    newnode->val = x;
    newnode->next = head;
    head = newnode;
}

NodeAddress insertionSort_LinkedList(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    int input;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        printf("Enter the value 1: ");
        scanf("%d", &input);
        head->val = input;                  
        head->next = NULL;                  
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next; 
        printf("Enter the value %d: ", i+1);
        scanf("%d", &input);
        temp->val = input;            
        temp->next = NULL;                  
        for(NodeAddress temp2 = head; temp2 != temp; temp2=temp2->next)
            {
                if(temp2->val >= temp2->next->val){
                    int swap_temp = temp2->val;
                    temp2->val = temp2->next->val;
                    temp2->next->val = swap_temp;
                }
            }
    }
    return head;                            
}


void printLinkedList(NodeAddress head, int n){
    NodeAddress temp = head;
    printf("Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}


void deleteLinkedList(NodeAddress head){
    NodeAddress prev;
	while(head){                
		prev = head;
		head = head->next;
		free(prev);
	}
}


int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list, list_rev;         
    srand(time(NULL));                  
    list = insertionSort_LinkedList(n);       
    printLinkedList(list, n);           
    deleteLinkedList(list);                         
    return 0;
}
