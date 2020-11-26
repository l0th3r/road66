/* 
	Useful LIBRARY 
	basic tools /
*/

#include <stdio.h>
#include <time.h>

#include <unistd.h>

void uf_wait(long msec);

int uf_str_len(char *str);
int uf_random(int max);

void uf_init()
{
	/* generate random seed */
	srand(time(NULL));
}

int str_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;

	return i;
}

/* wait in milliseconds */
void wait(long msec)
{
	fflush(stdout);
	usleep(msec);
}

int get_random(int max)
{
	return rand() % max;
}