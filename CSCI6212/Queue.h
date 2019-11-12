#indef Queue_h
#define Queue_h
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x){

}

void dequeue(){
	
}

int isEmpty(){
	return front == NULL;
}

#endif