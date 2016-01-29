/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head)
{
	if (head == NULL)
		return -1;
	struct node *slow_ptr = head;
	struct node *fast_ptr = head;
	fast_ptr = fast_ptr->next;
	int result=0;
	if (head != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}

		//printf("The middle element is [%d]\n\n", slow_ptr->data);
	}
	if (fast_ptr == NULL)
	{
		result = slow_ptr->num;
	}
	else
	{
		result = (((slow_ptr->num + (slow_ptr->next->num))) / 2);
	}

	
	return result;
}