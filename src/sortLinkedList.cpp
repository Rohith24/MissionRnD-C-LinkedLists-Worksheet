/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node *sll;
void swap(sll ll, sll p, sll q);
struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	sll p = head , q;
	while (p !=NULL)
	{
		q = p->next;
		while (q!=NULL)
		{
			if (p->num > q->num)
				swap(head, p, q);
			q = q->next;
		}
		p = p->next;
	}
	return head;
}

void swap(sll ll, sll p, sll q)
{
	int t;
	t = p->num;
	p->num = q->num;
	q->num = t;
}