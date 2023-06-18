#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

int main()
{
	char buf[255]; // creat buffer
	int ch = '\0'; 
	char* p = NULL;

	if (fgets(buf, sizeof(buf), stdin))
	{
		p = strchr(buf, '\n');
		if (p)
		{
			*p = '\0'; //loai bo newline
		}
		else
		{
			while (((ch = getchar() != '\n') && !feof(stdin) && !ferror(stdin)));
		}
	}
	
	else
	{
		;
	}
	printf("Our buffer : %s \n", buf);
}