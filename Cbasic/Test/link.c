#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node* next;
};

struct node* head = NULL;

struct node* create_head()
{
    struct node* pnode = (struct node*)malloc(sizeof(struct node));

    pnode->next = NULL;

    head = pnode;

    return head;
}

void free_all()
{
   struct node* p;
   for(p = head; p != NULL; p = p->next)
   {
       free(p);
   }
}

void insert(int nu)
{
    struct node* pre = (struct node*)malloc(sizeof(struct node));

    pre->num = nu;

    pre->next = head;
    head = pre;  
}

void print_node()
{
    struct node* p;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%d, ",p->num);
    }

    printf("\n");
}

int main(void)
{
    head = create_head();

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    print_node();

    free_all();

    return 0;
}
