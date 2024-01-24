/*
My C implementation of a queue from college.
Some comments were refactored to better describe the logic.
Also it took me 8 years to fix the "remove from empty queue" segfault :p
*/

#include <stdlib.h>
#include <stdio.h>

// Abstract Data Type "node". The structure of a node.
struct node{ 
	int value;
	struct node* next;
};
typedef struct node NODE;

// Abstract Data Type "queue". The queue's structure.
struct queue{ 
	NODE* head;
	NODE* tail;
};
typedef struct queue QUEUE;


QUEUE* initQueue();
int isEmpty(QUEUE* queue);
void insertion(QUEUE* queue, int value);
int deletion(QUEUE* queue);
void peekHead(QUEUE* queue);

int main(){
	
	int menu;
	int value;
	QUEUE* queue;
	
	do{
		printf("\n[MENU]\n\n1-Init Queue\n2-Insert value\n3-Remove value\n4-Peek head value\n0-Exit\n");
		scanf("%d", &menu);
		switch (menu){
			case 1:
				queue = initQueue();
			break;
			case 2:
				printf("\nInsert the value: ");
				scanf("%d", &value);
				insertion(queue, value);
			break;
			case 3:
				deletion(queue);
			break;
			case 4:
				peekHead(queue);
			break;
		}
	} while (menu != 0);

	return 0;
}

// Queue initialization, with head and tail poiting to NULL.
QUEUE* initQueue(){ 
	QUEUE* queue = malloc(sizeof(QUEUE));
	queue->head = NULL;
	queue->tail = NULL;
	printf("\nQueue created\n");
	return queue;
}

// Checks if queue is empty through the head pointer
int isEmpty(QUEUE* queue){
	if (queue->head == NULL) return 1;
	else return 0;
}

void insertion(QUEUE* queue, int value){
	NODE* novo = malloc(sizeof(QUEUE));
	novo->value = value;
	novo->next = NULL;

	// If queue is empty, both head and tail points to the new node.
	if (isEmpty(queue)){
		queue->head = novo;
		queue->tail = novo;
	}
	else{
		(queue->tail)->next = novo;
		queue->tail = novo;
	}

	printf("\nValue %d inserted\n", value);
}

int deletion(QUEUE* queue){
	NODE* aux = queue->head;
	int value;

	if (queue->head == NULL) {
		printf("Queue is already empty");
		return 0;
	}

	queue->head = aux->next; // The second node is now the head (the first one is being deleted)
	value = aux->value; // Save the value so we can return it after memory cleaning (free the node space)
	free(aux);
	aux = NULL;

	if (queue->head == NULL) queue->tail = NULL;

	printf("\nValue removed: %d\n", value);

	return value;
}

// Returns the value from the head node without any modifications
void peekHead(QUEUE* queue){ 
	if (!isEmpty(queue)) printf("\nPrimeiro da queue: %d\n", (queue->head)->value);
	else printf("\nQueue is empty!\n");
}