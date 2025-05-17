#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int top, n;
	int *arr;
};

struct stack *createStack(int size)
{
	struct stack *stack = malloc(sizeof(struct stack));
	stack->n = size;
	stack->top = -1;
	stack->arr = malloc(size * sizeof(int));
	printf("Created stack with a capacity of %d\n", size);
	return stack;
}

void deleteStack(struct stack *stack)
{
	free(stack->arr);
	free(stack);
	printf("The stack was deleted\n");
}

int isFull(struct stack *stack)
{
	return stack->top >= stack->n - 1;
}

int isEmpty(struct stack *stack)
{
	return stack->top < 0;
}

int push(struct stack *stack, int x)
{
	if (isFull(stack))
	{
		printf("Overflow\n");
		return 0;
	}
	stack->arr[++stack->top] = x;
	return 1;
}

int pop(struct stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Underflow\n");
		return 0;
	}
	return stack->arr[stack->top--];
}

int peek(struct stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Empty\n");
		return 0;
	}
	return stack->arr[stack->top];
}

void display(struct stack *stack)
{
	int n = stack->top;
	for (int i = 0; i <= n; i++)
	{
		printf("%d", stack->arr[i]);
		if (i != n)
			printf(", ");
	}
}

int main()
{
	struct stack *s = createStack(10);
	push(s, 122);
	push(s, 154);
	push(s, 408);

	printf("Popped element: %d\n", pop(s));
	printf("Top element   : %d\n", peek(s));

	printf("\nCurrent elements in stack:\n");
	display(s);

	printf("\n\b");
	deleteStack(s);
	return 0;
}