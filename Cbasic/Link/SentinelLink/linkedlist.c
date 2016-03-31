#include <stdlib.h>
#include "linkedlist.h"

struct node tailsentinel;
struct node headsentinel = {0,NULL,&tailsentinel};
struct node tailsentinel = {0,&headsentinel,NULL};

static link head = &headsentinel;
static link tail = &tailsentinel;

//创建一个节点并返回节点地址
link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->prev = p->next = NULL;
	return p;
}

//释放节点
void free_node(link p)
{
	free(p);
}

//根据item，从head开始，查找节点
link search(unsigned char key)
{
	link p;
	for (p = head->next; p != tail; p = p->next)
		if(p->item ==key)
			return p;
	return NULL;
}

//插入新的节点，将next指向之前链表的头，并将新节点的地址存入head
//只能在链表头部插入
void insert(link p)
{
	p->prev = head;
	p->next = head->next;
	head->next->prev = p;
	head->next = p;

}

void seq(link p)
{
	link pre = head ,pred = head;
	if(head == NULL){
		head = p;
		return;
	}
	while((p->item) < (pre->item)&& pre->next != NULL){
		pred = pre;
		pre = pre->next;
	}
	p->next = pre;
	if(pre == head)
		head = p;
	else
	pred->next = p;
	return;
}

//删除节点，并将head和P之前的p->next全部向后移一位
void delete(link p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

//遍历，
void traverse(void (*visit)(link))
{
	link p;
	for(p = head; p; p = p->next)
		visit(p);
}

//释放整个链表
void destroy(void)
{
	link q,p = head->next;
	head->next = tail;
	tail->prev = head;
	while(p!= tail){
		q = p;
		p = p->next;
		free_node(q);
	}
}

//插入链表
void push(link p)
{
	insert(p);
}

//取出链表，将head指向下一个节点
link pop(void)
{
	if(head == NULL)
		return NULL;
	else{
		link p = head;
		head = head->next;
		return p;
	}
}

void enqueue(link p)
{
	insert(p);
}

link dequeue(void)
{
	if(tail->prev == head)
		return NULL;
	else{
		link p = tail->prev;
		delete(p);
		return p;
	}
	
	
}
