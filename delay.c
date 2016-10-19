#include<stdio.h>
#include<time.h>

void main()
{
	int i;
	for (i=0; i<5; i++)
	{
		fflush(stdout);
		sleep(5);
		printf("DELAY");
	}
}
