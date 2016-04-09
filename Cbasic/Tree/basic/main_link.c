#include <stdio.h>
#include "link.h"

void print_item(link p)
{
	printf("%d", p->item);
}

int main()
{
	unsigned char element[] = {1,2,3,4,5,6};
	link tial = init(element,6);
	pre_order(head,print_item);
	return 0;
}
