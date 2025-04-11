#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *createNode(int data)
{
	struct node *temp = NULL;
	temp = malloc(sizeof(struct node));
	temp->data = data;
}

void display(struct node *start)
{
	struct node *temp = start;
	printf("Head -> ");
	while (temp != NULL)
	{
		printf("[%d] -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

int main()
{
	struct node *head = malloc(sizeof(struct node));
	struct node *one = createNode(2);
	struct node *two = createNode(5);
	struct node *three = createNode(7);

	one->next = two;
	two->next = three;
	three->next = NULL;

	head = one;
	display(head);
	return 0;
}