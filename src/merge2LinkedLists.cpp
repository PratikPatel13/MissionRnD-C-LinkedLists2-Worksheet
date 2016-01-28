/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *p = NULL, *head = NULL;  // head is used to return starting of merged list, p is used as current pointer for merged list
	struct node *c1 = head1, *c2 = head2; // c1 and c2 are pointers for current position in two list
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	// set the head of merge list to the list whose first element is small and increment current pointer of that list
	if (c1->num < c2->num)
	{
		p = c1;
		c1 = c1->next;
	}
	else
	{
		p = c2;
		c2 = c2->next;
	}
	head = p;
	while (c1 != NULL && c2 != NULL) 	//Traverse through the list till one of the list is empty
	{
		if (c1->num < c2->num)  //If the data of one list is small than other then the smaller data node should be pointed by p and p points to that node now
		{
			p->next = c1;
			p = c1;
			c1 = c1->next;
		}
		else
		{
			p->next = c2;
			p = c2;
			c2 = c2->next;
		}
	}
	// If one of the list is empty then append the other list to the current mergelist
	if (c1 == NULL)
		p->next = c2;
	else
		p->next = c1;
	return head;
}
