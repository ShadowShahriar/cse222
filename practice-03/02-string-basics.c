#include <stdio.h>

int main()
{
	// string declaration and initialization
	// in four different ways
	char name_1[] = "Shahriar";
	char name_2[9] = "Shahriar";
	char name_3[] = {'S', 'h', 'a', 'h', 'r', 'i', 'a', 'r', '\0'};
	char name_4[9] = {'S', 'h', 'a', 'h', 'r', 'i', 'a', 'r', '\0'};

	// print the strings in the terminal
	printf("%s\n", name_1);
	printf("%s\n", name_2);
	printf("%s\n", name_3);
	printf("%s\n", name_4);

	// take user input via scanf
	char name_5[100];
	scanf("%s\n", &name_5);
	printf("%s\n", name_5);

	// take user input via gets
	char name_7[100];
	gets(name_7);
	printf("%s\n", name_7);

	// take user input via fgets
	char name_6[100];
	fgets(name_6, 100, stdin);
	printf("%s\n", name_6);
}