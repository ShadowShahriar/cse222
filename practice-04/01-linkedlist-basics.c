#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *head;
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *three = NULL;

	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));

	one->data = 2;
	two->data = 5;
	three->data = 7;

	one->next = two;
	two->next = three;
	three->next = NULL;

	head = one;

	struct node *temp = head;
	printf("Head -> ");
	while (temp != NULL)
	{
		printf("[%d] -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
	return 0;
}