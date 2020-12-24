/* 
	FILE LIBRARY 
	File handle / file parsing
*/

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

char* fp_read_file(const char* path);

char* fp_read_file(const char* path)
{
	FILE* fp;
	char* to_return;
	char temp;
	int i = 0;
	size_t len = 1;

	to_return = malloc(len * sizeof(char));

	fp = fopen(path, "r");

	if(fp)
	{
		do
		{
			to_return = realloc(to_return, ++len * sizeof(char));
			temp = fgetc(fp);
			to_return[i] = temp;
			i++;
		}
		while(temp != EOF);
		to_return = realloc(to_return, ++len * sizeof(char));
		to_return[i] = '\0';
	}

	fclose(fp);

	return to_return;	
}