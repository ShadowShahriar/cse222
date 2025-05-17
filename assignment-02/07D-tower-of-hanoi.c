#include <stdio.h>

void hanoi(int n, char S, char D, char A)
{
	if (n == 0)
		return;

	hanoi(n - 1, S, A, D);
	printf("Disk %d: [%c] -> [%c]\n", n, S, D);
	hanoi(n - 1, A, D, S);
}

int main()
{
	int n = 4;
	hanoi(n, 'A', 'C', 'B');
	return 0;
}