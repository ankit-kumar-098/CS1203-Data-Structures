#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*=Linked List Structure=*/
struct Node{
    int val;
    struct Node * next;
};
typedef struct Node * NodeAddress;  // creating a new data type NodeAddress 

NodeAddress chunkReverse(NodeAddress head, int k){
    NodeAddress curr = head;            
    NodeAddress prev = NULL;            
    NodeAddress forward = NULL;         
    if(k==0){                            
        return head;
    }
    for(int i=0; i<k && curr!=NULL; i++){    
        forward = curr->next;                
        curr->next = prev;                   
        prev = curr;                         
        curr = forward;                      
    }
    head->next = curr;                      
    head = prev;                             
    return head;
}

/*==== Generate Linked List ====*/
NodeAddress generateLinkedList(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        head->val = rand()%1000;            
        head->next = NULL;                 
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->val = rand()%1000;            
        temp->next = NULL;                  
    }
    return head;                            
}

/*=Print Linked List=*/
void printLinkedList(NodeAddress head, int n){
    NodeAddress temp = head;
    printf("Complete Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}
/*==== Delete Linked List ====*/
void deleteLinkedList(NodeAddress head){
    NodeAddress prev;
	while(head){                
		prev = head;
		head = head->next;
		free(prev); 
	}
}

/*=main=*/
int main(int argc, char const *argv[])
{
    int n,k;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list, chunk;         
    srand(time(NULL));                  
    list = generateLinkedList(n);       
    printLinkedList(list, n);           

    printf("Enter the value of k: ");
    scanf("%d", &k);

    chunk = chunkReverse(list, k);
    
    printLinkedList(chunk, n);          

    deleteLinkedList(list);                         
    deleteLinkedList(chunk);                         
    return 0;
}
