#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return( *(int*)a -  *(int*)b );
}

int main()
{
	int v[5] = {5,4,3,2,1}, i;
	
	qsort(v, 5, sizeof(int), compare);
	
	for(i = 0; i < 5; i++)
		printf("element : %d\n", v[i]);
	
	return 0;
}
