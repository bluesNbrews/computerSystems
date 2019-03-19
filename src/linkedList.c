//Author: Steven Williams
//CSCI 6011
//In class problem set 3 (linked list using structures)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Three value fields and a pointer for the next node
struct Node{
	char id[5];
	char name[10];
	char grade;
	struct Node *next;
};

//Pass in the address of head to make a pointer to the head pointer
//Also pass in all of the values to constitute the new head node data
void add_stack(struct Node **head_ptr, char new_id[], char new_name[], char new_grade){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(new_node->id, new_id);
	strcpy(new_node->name, new_name);
	new_node->grade = new_grade;
	//Point to the current head node
	new_node->next = (*head_ptr);
	//Set this pointer to the pointer of head with the new node, which is now the head
	(*head_ptr) = new_node;
}

//Pass in the head of the list to iterate through from the beginning and also pass in the student ID to search for (key)
//Iterate through just like the print function below
void find(struct Node *n, char key_id[]){
	while(n != NULL){
		if (strcmp(n->id, key_id) == 0){
			printf("Student %s has been found.\n", n->id);
			break;
		}
		n = n->next;
	}
	printf("\n");
}

//Pass in the head of the list to iterate through from the beginning and also pass in the student ID to search for (key)
//Also pass in the new grade which will replace the current grade for the student identified by the key
//Iterate through just like the print function below
void modify(struct Node *n, char key_id[], char new_grade){
	while(n != NULL){
		if (strcmp(n->id, key_id) == 0){
			printf("Student %s's grade was %c. ", n->id, n->grade);
			n->grade = new_grade;
			printf("Student %s's grade is now %c.\n", n->id, n->grade);
			break;
		}
		n = n->next;
	}
}

//Pass in the address of head to make a pointer to the head pointer and the student ID(key)
void delete(struct Node **head_ptr, char key_id[]){
	//Create temp node and previous node with the value of the head node
	struct Node *temp = *head_ptr, *prev;

	//If the key is the head of the list, go ahead and change the pointer to the head pointer to the next one (pointer) after the head
	if (temp != NULL && strcmp(temp->id, key_id) == 0){
		*head_ptr = temp->next;
		//Deallocate memory
		free(temp);
		return;
	}

	//Move along the list. Set prev to currentand the current to the next node
	//Stop once the key matches or if at the end of the list
	while(temp != NULL && strcmp(temp->id, key_id) != 0){
		prev = temp;
		temp = temp->next;
	}

	//If at the end of the list, do nothing
	if(temp == NULL)
		return;

	//This must mean that the key matches
	//Set the previous node to the next node, leaving out the node that is identified
	prev->next = temp->next;
	//Deallocate memory for the node identified
	free(temp);
}

//This will print out the linked list by passing in the head of the list
void printList(struct Node *n)
{
	//The loop will iterate and print until the final node that has NULL as it's next pointer node
	//Then the loop will stop
	while(n != NULL)
	{
		printf("Student: %s has the name %s and the letter grade %c.\n", n->id, n->name, n->grade);
		n = n->next;
	}
	printf("\n");
}

//Pass in the node to insert the new node after along with the values for the new node
void insert_after(struct Node *prev_node, char new_id[], char new_name[], char new_grade){
	
	//Break if node to insert after is null
	if(prev_node == NULL)
		return;

	//Create the new node
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(new_node->id, new_id);
	strcpy(new_node->name, new_name);
	new_node->grade = new_grade;
	//Set the new node to point to what the previoius node was pointing to, thus taking it's place
	//Also need to have the previous node now point to the new node
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

int main(){

	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	head = malloc(sizeof(struct Node));
	second = malloc(sizeof(struct Node));
	third = malloc(sizeof(struct Node)); 

	
	strcpy(head->id, "1234");
	strcpy(head->name, "Steven");
	head->grade = 'A';
	head->next = second;

	strcpy(second->id, "2345");
	strcpy(second->name, "Stu");
	second->grade = 'B';
	second->next = third;

	strcpy(third->id, "3456");
	strcpy(third->name, "Milo");
	third->grade = 'C';
	third->next = NULL;

	printf("Three students have been added. See below for their info.\n");
	printList(head);

	printf("Student 4321 has been added to the front of the list and Student 7657 has been added directly after Stu.\n");
	add_stack(&head, "4321", "Khruangbi", 'D');
	insert_after(second, "7657", "Laura", 'F');
	printList(head);

	find(head, "1234");

	modify(head, "7657", 'B');
	printf("Now deleting Student 1234.\n");
	delete(&head, "1234");
	printf("Here is the final list of students after all of the actions.\n");
	printList(head);

	return 0;
}