/* link.h */
#ifndef LINK_H
#define LINK_H

typedef struct node *link;

struct node{
	unsigned char item;
	link next;
};

link init(unsigned char elements[], int n);
void pre_order(link t, void (*visit)(link));
void post_order(link t, void (*visit)(link));
int count(link t);
void destroy(link t);

#endif
