/* link.c */
#include <stdlib.h>
#include "link.h"

static link head = NULL;
static link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
	return p;
}
link init(unsigned char element[],int n)
{
	link t;
	if(n < 0)
		return NULL;
	t = make_node(element[0]);
	t->next = init(element + 1,n--);
	if(n == 0)
		head = t;
	return t;
}
void pre_order(link t,void (*visit)(link))
{
	if(!t)
		return;
	visit(t);
	pre_order(t->next,visit);
}

int count(link t)
{
	if(!t)
		return 0;
	return 1 + count(t->next);
}

void destroy(link t)
{
	free(t);
}
