#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int *arr;
	int front;
	int rear;
	int n;
};

struct queue *createQueue(int n)
{
	struct queue *q = malloc(sizeof(struct queue));
	q->n = n;
	q->front = 0;
	q->rear = -1;
	q->arr = (int *)malloc(n * sizeof(int));
	return q;
}

int isEmpty(struct queue *q)
{
	return q->front > q->rear;
}

void enqueue(struct queue *q, int x)
{
	if (q->rear < q->n - 1)
		q->arr[++q->rear] = x;
}

void dequeue(struct queue *q)
{
	if (!isEmpty(q))
		q->front++;
}

int peek(struct queue *q)
{
	return isEmpty(q) ? -1 : q->arr[q->front];
}

void display(struct queue *q)
{
	for (int i = q->front; i <= q->rear; i++)
		printf("%d ", q->arr[i]);
	printf("\n");
}

int main()
{
	struct queue *q = createQueue(100);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);

	printf("Front element: %d\n", peek(q));

	dequeue(q);
	enqueue(q, 4);

	printf("Current q: ");
	display(q);
	return 0;
}