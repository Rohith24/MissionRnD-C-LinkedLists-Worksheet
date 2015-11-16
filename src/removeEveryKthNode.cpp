/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *sll;
void deletepos(sll head, sll pos);
sll findpos(sll ll, int k);

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1)
		return NULL;
	else
	{
		int i;
		sll temp = head, pos;
		pos = findpos(temp, K);
		while (temp != NULL&&pos!=NULL)
		{
			deletepos(temp, pos);
			for (i = 0; i < K; i++)
			{
				if (pos->next != NULL){
					pos = pos->next;
				}
				else
				{
					pos = NULL;
					break;
				}
			}
		}
		return head;
	}
}
sll findpos(sll ll, int k)
{
	int i;
	sll t = ll;
	for (i = 1; i<k; i++)
	{
		if (t != NULL)
			t = t->next;
		else
			return NULL;
	}
	return t;
}
void deletepos(sll head, sll pos){
	sll temp = head;
	if (temp == pos)
		temp = temp->next;
	else
	{
		while (temp->next != pos)
			temp = temp->next;
		temp->next = pos->next;
	}
}