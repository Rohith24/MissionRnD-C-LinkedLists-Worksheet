/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *list;
typedef struct node *position;

void insert(list ll, position p, int e);

struct node * numberToLinkedList(int N) {
	list head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	if (N == 0){
		head->num = 0;
		return head;
	}
	if (N<0)
		N *= -1;
	while (N>0)
	{
		insert(head, head, N%10);
		N /= 10;
	}
	return head->next;
}

void insert(list ll, position p, int e)
{
	list temp;
	temp = (list)malloc(sizeof(struct node));
	temp->num = e;
	temp->next = p->next;
	p->next = temp;
}