#include <stdio.h>

void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
	return;
}

void bubble(int v[])
{
	int i,j;
	
	for( i = 0; i < 4; i++)
		for( j = 0; j < 4; j++)
		{
			if(v[j] > v[j+1])
				swap(&v[j],&v[j+1]); 
		}

	return;
}
	
void print(int v[])
{
	int i;
	for( i = 0; i < 5; i++)
		printf(" ELement : %d\n", v[i]);
		
	return;
}

int main()
{
	int v[5] = {5,4,3,2,1};
	
	print(v);
	bubble(v);
	print(v);

	return 0;
}
	
