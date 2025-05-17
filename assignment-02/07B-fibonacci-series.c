#include <stdio.h>

int fibonacci(int n)
{
	int fib;
	if (n > 2)
		fib = fibonacci(n - 1) + fibonacci(n - 2);
	else if (n == 2)
		fib = 1;
	else
		fib = 0;
	return fib;
}

int main()
{
	int n = 10;
	for (int i = 1; i <= n + 1; i++)
		printf("%d ", fibonacci(i));

	return 0;
}