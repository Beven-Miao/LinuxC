#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d\n",p->item);
}

int main(void)
{
	
	link p = make_node(10);//创建一个节点
	insert(p);//将节点插入链表
	p = make_node(5);
	insert(p);
	p = make_node(90);
	insert(p);
	//链表应为90,5,10
	
	p = search(5);
	delete(p);//删除中间的item为5的节点
	free_node(p);//释放该节点的内存

	traverse(print_item);//遍历
	//应打印90,10
	destroy();

	p = make_node(100);
	seq(p);
	p = make_node(250);
	seq(p);
	p = make_node(150);
	seq(p);
	p = make_node(200);
	seq(p);
	//250,200,100
	while( p=pop()){
		print_item(p);
		free_node(p);
	}
	//打印250,200,100

	return 0;
}
