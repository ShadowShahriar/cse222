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

void display(const char *message, struct node *start)
{
	struct node *temp = start;
	printf(message);
	printf("Head -> ");
	while (temp != NULL)
	{
		printf("[%d] -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

struct node *insertStart(struct node *newNode, struct node *start)
{
	newNode->next = start;
	return newNode;
}

void insertEnd(struct node *newNode, struct node *start)
{
	newNode->next = NULL;
	struct node *temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

void insertAt(struct node *newNode, int position, struct node *start)
{
	struct node *temp = start;
	for (int i = 2; i <= position; i++)
	{
		if (i == position)
		{
			newNode->next = temp->next;
			temp->next = newNode;
		}
		temp = temp->next;
	}
}

int main()
{
	// =====================
	// === initial setup ===
	// =====================
	struct node *head = malloc(sizeof(struct node));
	struct node *one = createNode(2);
	struct node *two = createNode(5);
	struct node *three = createNode(7);

	one->next = two;
	two->next = three;
	three->next = NULL;

	head = one;
	display("Given LinkedList: ", head);

	printf("\nNode Insertion:\n");

	// =================================
	// === add node at the beginning ===
	// =================================
	struct node *four = createNode(6);
	head = insertStart(four, head);
	display("At the beginning: ", head);

	// ===========================
	// === add node at the end ===
	// ===========================
	struct node *five = createNode(9);
	insertEnd(five, head);
	display("At the end      : ", head);

	// =======================================
	// === add node at a specific position ===
	// =======================================
	struct node *six = createNode(4);
	insertAt(six, 2, head);
	display("At position     : ", head);

	return 0;
}