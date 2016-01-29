/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<assert.h>
struct node {
	int num;
	struct node *next;
};
void MoveNode(struct node** destRef, struct node** sourceRef)
{
	struct node* newNode = *sourceRef;
	assert(newNode != NULL);
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	struct node* result = NULL;

	struct node** lastPtrRef = &result;

	while (1)
	{
		if (head1 == NULL)
		{
			*lastPtrRef = head2;
			break;
		}
		else if (head2 == NULL)
		{
			*lastPtrRef = head1;
			break;
		}
		if (head1->num <= head2->num)
		{
			MoveNode(lastPtrRef, &head1);
		}
		else
		{
			MoveNode(lastPtrRef, &head2);
		}

		lastPtrRef = &((*lastPtrRef)->next);
	}
	return(result);
}