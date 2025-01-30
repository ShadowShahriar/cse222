#include <stdio.h>
#include <string.h>

int main()
{
	// string concatination
	char firstName[100] = "Shayan";
	char lastName[100] = "Shahriar";
	strcat(firstName, " "); // adding an additional space at the end of first name
	strcat(firstName, lastName);
	puts(firstName);

	// getting the string length
	printf("%d\n", strlen(firstName));

	// comparing two strings
	char str1[50] = "Hello";
	char str2[50] = "Hi";
	printf("%d\n", strcmp(str1, str2));

	// getting a substring from a string
	const char newName[] = "Hasanur";
	const char search[] = "sa";
	printf("%s\n", strstr(newName, search));

	// copying string
	char str3[] = "Hello";
	char str4[] = "World";
	strcpy(str3, str4);
	printf("%s\n", str3);
	return 0;
}