#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DLinkList
{
	int value;
	struct DLinkList *next;
	struct DLinkList *prev;

}DLL;

DLL *head, *tail;


void init_list(void);
DLL* create_node(int key);
void insert_node(DLL *, DLL *);
void delete_node(DLL **, DLL *);

int main() {

	return 0;
}

void init_list() {
	head = (DLL *)malloc(sizeof(DLL));
	tail = (DLL *)malloc(sizeof(DLL));

	head->next = tail;
	head->prev = head;

	tail->next = tail;
	tail->prev = head;
}

DLL* create_node(int key) {
	DLL *new_node = (DLL *)malloc(sizeof(DLL));
	new_node->value = key;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

void append_node(DLL **head, DLL* NewNode) {
	if ((*head) == NULL) {
		*head = NewNode;
	}
	else {
		DLL* tail = *head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = NewNode;
		NewNode->prev = tail;
	}
}

void insert_node(DLL *current, DLL* NewNode) {
	NewNode->next = current->next;
	NewNode->prev = current;

	if (current->next != NULL) {
		current->next->prev = NewNode;
	}
	current->next = NewNode;

	/*
	DLL *new_node = (DLL *)malloc(sizeof(DLL));
	DLL *temp = node;

	new_node->value = key;
	temp = node->next;
	temp->prev = new_node;
	new_node->next = temp;
	node->next = new_node;
	new_node->prev = node;

	return new_node;
	*/
}

void delete_node(DLL ** head, DLL* DelNode) {
	if (*head == DelNode) {
		*head = DelNode->next;
		if (*head != NULL) {
			(*head)->prev = NULL;
		}
		DelNode->prev = NULL;
		DelNode->next = NULL;
	}
	else {
		DLL* empty = DelNode;
		DelNode->prev->next = empty->next;
		if (DelNode->next != NULL) {
			DelNode->next->prev = empty->prev;
		}
		DelNode->prev = NULL;
		DelNode->next = NULL;
	}
}