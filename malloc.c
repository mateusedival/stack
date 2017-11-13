#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef int data;

void printD(data *v, data n)
{
	data i;
	printf("[");
	for (i = 0; i < n; i++)
	{
		printf("%-2d", v[i]);
		if(i < n-1)
			printf(", ");
	}
	printf("]\n");
	return;
}

void printDM(data **m, data n)
{
	data i,j;
	
	for(i = 0; i < n; i++)
	{
			for(j = 0; j < n; j++)
			{
				printf("%d", m[i][j]);
				if (j < n-1)
					printf("\t");
			}
			printf("\n");
	}
	return;
}

int main()
{
	data *v;
	data **m;
	data n,i,j;
	
	scanf("%d",&n);
	
	v = (data*)malloc(n*sizeof(data));
	if(v == NULL)
	{
		puts("error\n");
		return 0;
	}
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	
	printD(v,n);
	
	m = (data**)malloc(n * sizeof(data*));
	if(m == NULL)
	{
		printf("error/n");
		return 0;
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			m[i] = (data*)malloc(n * sizeof(data));
			if (m == NULL)
			{
				puts("error\n");
				return 0;
			}
		}
		
		for	(i = 0; i < n ; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &m[i][j]);
				
		printDM(m,n);
	 }
			
		free(v);
			
		for ( i = 0; i < n ; i++ )
			free(m[i]);
		free(m);
	return 0;
}
	
	
	
