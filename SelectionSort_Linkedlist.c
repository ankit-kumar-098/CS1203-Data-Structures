#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*= Linked List Structure =*/
struct Node{
    int val;
    struct Node * next;
};
typedef struct Node * NodeAddress;  
void selectionSortLinkedList(NodeAddress head){
    NodeAddress temp, max, prev, curr;     
    temp = head;                                    
    while(temp->next != NULL){                      
        max = temp;                               
        prev = temp;                                
        curr = temp->next;                            
        while(curr != NULL){
            if(curr->val < max->val){               
                max = curr;                         
            }
            curr = curr->next;                      
        }

        
        int swap_temp = temp->val;
        temp->val = max->val;
        max->val = swap_temp;
        
        
        temp = temp->next;                          
    }
}


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
    printf("Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}
/*=Delete Linked List=*/
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
    int n;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list;         
    srand(time(NULL));                  
    list = generateLinkedList(n);       
    printLinkedList(list, n);           
    selectionSortLinkedList(list);                 
    printLinkedList(list, n);           
    deleteLinkedList(list);                         
    return 0;
}
