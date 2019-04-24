//Author: Steven Williams
//CSCI 6011
//Final Exam Problem 3
//Define the size of a circular linked list

#include<stdio.h>
#include<stdlib.h>

//Create the structure for each node in the linked list.
struct Node {
	
	int data;
	struct Node *next;

};

void pushNode(struct Node **head_ptr, int data){
	
	//Allocate memory for the Node itself and assign the pointer to the head as a temp variable
	struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = *head_ptr;

	//Assign data to new node and set the next value of new node to the head
	ptr1->data = data;
	ptr1->next = *head_ptr;

	//If there is only one node (head) have it point to itself
	//If there are two nodes, have the second node (head) point to the new node. The new node will become head at *head_ptr = ptr1
	//If there are more than two nodes, than switch temp to oldest created node (1 in this case) and point to the newest node (5 in this case)
	if (*head_ptr != NULL) {
		while (temp->next != *head_ptr)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; 
	//Set the head as the new pointer created above
	*head_ptr = ptr1;
}

int countNode(struct Node *head){
	
	//Create a temp from the head
	struct Node *temp = head;

	//Counter variable
	int total = 0;

	//Iterate through linked list and increment counter based on the number of nodes
	if (head != NULL){
		do{
			temp = temp->next;
			total++;
		} while (temp != head);
	}
	//Return the count
	return total;
}

int main(){

	//Start the linked list with the head
	struct Node *head = NULL;

	//Add the nodes below
	pushNode(&head, 1);
	pushNode(&head, 3);
	pushNode(&head, 5);

	//Count and print the nodes in the list
	printf("The size of the circular linked list is %d.\n", countNode(head));

	return 0;
}