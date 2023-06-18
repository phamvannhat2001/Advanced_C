#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main()
{
	char* buffer = NULL;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char*)malloc(bufsize * sizeof(char));

	if (buffer == NULL)
	{
		exit(1);
	}

	printf("Type something: ");
	characters = getline(&buffer, &bufsize, stdin);

	printf("%zu characters were read. \n", characters);
	printf("You typed: '%s' \n", buffer);
	free(buffer);

	return 0;
}