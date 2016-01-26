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

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	struct node *p = head, *q = head, *prev = NULL;  //Make two pointers at starting element. prev will be used only when there are even terms.
	int flag = 0; //flag for checking if there are even terms in list or odd terms. 
	if (head == NULL) // If the list is empty
		return 0;
	while (q != NULL && q->next != NULL)
	{
		prev = p;
		p = p->next;
		q = q->next->next;
	}
	if (q == NULL)
		flag = 1;
	if (flag == 1) //If the list has even terms then need to take average of two middle elements
	{
		return (prev->num + p->num) / 2.0;
	}
	return p->num; //If there are odd terms then return the middle element
}


