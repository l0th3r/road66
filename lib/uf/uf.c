/* 
	USEFUL LIBRARY 
	basic tools /
*/

#include "../../includes.h"

void uf_wait(long msec);

int uf_str_len(char *str);
int uf_random(int max);
int uf_compare(char* to_use);

void uf_init()
{
	/* generate random seed */
	srand(time(NULL));
}

/* return 1 if same */
int uf_strcmp(char* src, char* dest)
{
	int to_return = 0;
	int i = 0;

	if(uf_str_len(src) == uf_str_len(dest))
	{
		while(i < uf_str_len(src))
		{
			to_return = 1;
			if(src[i] != dest[i])
				to_return = 0;
			i++;
		}
	}

	return to_return;
}

int uf_compare(char* to_use)
{
	int to_return = 0;
	int i = 0;

	while(i < inventory->pa_count)
	{
		if(uf_strcmp(to_use, inventory->passengers[i]) == 1)
			to_return = 1;
		i++;
	}

	return to_return;
}

int uf_str_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;

	return i;
}

/* wait in milliseconds */
void uf_wait(long msec)
{
	fflush(stdout);
	usleep(msec);
}

int uf_random(int max)
{
	return rand() % max;
}