#include <stdio.h>
#include <stdlib.h>

#define max 5

typedef int data;

typedef struct 
{
	data v[max];
	data head;
	data tail;
} queue;

void start(queue *F)
{
	F->head = F->tail = 0;
}

int isEmpty(queue F)
{
	return (F.head == F.tail);
}

int isFull(queue F)
{
	return ( (F.tail+1) % max) == F.head;
}

void push(queue *F, data new)
{
	F->v[F->tail] = new;
	F->tail = (F->tail + 1) % max;
}

void pop(queue *F)
{
	F->head = (F->head + 1) % max;
}	

void print(queue f)
{
	int i;
	for( i = f.head; i != f.tail ; i = (i+1)%max)
		printf("%d\n",f.v[i]);
}

int main()
{
	int n;
	queue F;
	
	start(&F);
	
	while(scanf("%d", &n) && n)
		push(&F,n);
	

	print(F);
	
	if(isEmpty(F))
		printf("t\n");
		
	if (isFull(F))
		printf("n\n");
	
	
	return 0;
}
