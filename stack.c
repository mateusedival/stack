#include <stdio.h>

#define max 5

typedef struct
{
	int bag[max];
	int top;
} stack;

void start(stack *p)
{
	p->top = 0;
}

int isEmpty(stack *p)
{
	return !(p->top);
}

int isFull(stack *p)
{
	return p->top == max;
}

void push(stack *p, int new)
{
	p->bag[p->top] = new;
	p->top++;
	return;
}

void pop(stack *p)
{
	if(isEmpty(p))
		return;
	p->top--;
}

void print(stack p)
{
	int i;
	for( i = --p.top; i >= 0; i--)
	{
		printf("%d\n",p.bag[i]);
	}
}


int main()
{
	stack p;
	int n;
	
	start(&p);
	while(scanf("%d", &n) && n)
	{
		push(&p,n);
	}
	print(p);
	
	if(isEmpty(&p))
		printf("4\n");
	
	if (isFull(&p))
		printf("t\n");
	
		
		
	return 0;
}
