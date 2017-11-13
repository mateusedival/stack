#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef int data;

typedef struct node
{
		data info;
		struct node *next;
} node;

typedef struct list
{
	node *first;
	node *last;
	data length;
} list;

void startL(list *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}
void popAll(list *L)
{
	node *l = L->first;
	while(l)
	{
		L->first = L->first->next;
		free(l);
		L->length--;
		l = L->first;
	}
	L->last = L->first = NULL;
}

int isEmpty(list L)
{
	return !(L.length);
}

int pushRight(list *L, data new)
{
	node *aux = (node*)malloc(sizeof(node));
	if( aux == NULL)
		return 1;
	else
	{
		aux->info = new;
		aux->next = NULL;
		
		if (L->last == NULL)
			L->first = L->last = aux;
			
		else
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return 0;
	}
}

int pushLeft(list *L, data new)
{
	node *aux = (node*)malloc(sizeof(node));
	if ( aux == NULL)
		return 1;
	else
	{
		aux->info = new;
		aux->next = L->first;
		L->first = aux;
		
		if(L->last == NULL)
		{
			L->last = aux;
		}	
		L->length++;
		return 0;
	}
}	

void popLeft(list *L)
{
	node *aux = L->first;
	
	L->first = L->first->next;
	
	free(aux);
	
	if(L->first == NULL)
		L->last == NULL;
	
	L->length--;
}	

void popRight(list *L)
{
	node *aux = L->last;
	node *aux2 = L->first;
	
	if(L->last == L->first)
	{
		free(aux2);
		L->first = L->last = NULL;
	}
	else
	{
		while(aux2->next->next != NULL)
			aux2 = aux2->next;		
			
		L->last = aux2;
		free(aux);
		L->last->next = NULL;
		L->length--;
	}
}

void printL(list L)
{
	node *aux = L.first;
	
	while(aux)
	{
		printf("element : %d\n", aux->info);
		aux = aux->next;
	}
}	
	
int main()
{
	list L;
	startL(&L);
	
	pushLeft(&L,2);
	pushLeft(&L,1);
	pushRight(&L,3);
	
	printL(L);
	
	popLeft(&L);
	popRight(&L);
	
	printL(L);
	
	popAll(&L);
	
	printL(L);
	return 0;
}
