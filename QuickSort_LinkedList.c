#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// defining a linked list structure
struct Node{
    int val;
    struct Node * next;
};
typedef struct Node * NodeAddress;  

/*=Parition=*/

NodeAddress parition(NodeAddress start, NodeAddress end){
    int pivot = start->val;
    NodeAddress wall = start; 
    NodeAddress scout = start->next; // j is the next element 
    while(scout != end->next){
        if(scout->val < pivot){
            wall = wall->next;
            int swap_temp = wall->val;
            wall->val = scout->val;
            scout->val = swap_temp;
        }
        scout = scout->next;
    }
    int swap_temp = wall->val;
    wall->val = start->val;
    start->val = swap_temp;
    
    return wall;
}

/*=Quick Sort=*/
int quickSortLinkedList(NodeAddress head, NodeAddress tail){
    if (head == tail){
        return 0;
    }    
    NodeAddress pivot = parition(head, tail);
    if (pivot != NULL && pivot->next != NULL){
        quickSortLinkedList(pivot->next, tail);
    }
    if (pivot != NULL && head != NULL){
        quickSortLinkedList(head, pivot);
    }
}
NodeAddress generateLinkedList(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
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


NodeAddress getTail(NodeAddress head){
    NodeAddress temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
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
    NodeAddress list, tail;         
    srand(time(NULL));                  
    list = generateLinkedList(n);       
    tail = getTail(list);
    printLinkedList(list, n);           
    quickSortLinkedList(list, tail);                 

    printLinkedList(list, n);           
    deleteLinkedList(list);                         
    return 0;
}
