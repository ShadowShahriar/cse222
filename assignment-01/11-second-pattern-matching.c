#include <stdio.h>
#include <string.h>
#define d 256
#define q 101

int main()
{
	char text[] = "Voicetextreceived";
	char pattern[] = "text";
	int len_P = strlen(pattern);
	int len_T = strlen(text);

	int i, j;
	int val_P = 0;
	int current_T = 0;
	int calcuP = 1;

	for (i = 0; i < len_P - 1; i++)
		calcuP = (calcuP * d) % q;

	for (i = 0; i < len_P; i++)
	{
		val_P = (d * val_P + pattern[i]) % q;
		current_T = (d * current_T + text[i]) % q;
	}

	for (i = 0; i <= len_T - len_P; i++)
	{
		if (val_P == current_T)
		{
			for (j = 0; j < len_P; j++)
			{
				if (text[i + j] != pattern[j])
					break;
			}

			if (j == len_P)
				printf("The first occurrence found at index %d\n", i);
		}

		if (i < len_T - len_P)
		{
			current_T = (d * (current_T - text[i] * calcuP) + text[i + len_P]) % q;
			if (current_T < 0)
				current_T = (current_T + q);
		}
	}

	return 0;
}