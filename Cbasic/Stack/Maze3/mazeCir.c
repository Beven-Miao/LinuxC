#include<stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define LEN 4

struct point {int row, col,predessor;} queue[LEN];
int head = 0 ,tial = 0 ;

void enqueue(struct point p)
{	
	if(tial == LEN)
		tial = -0;
	queue[tial++] = p; 
}

struct point dequeue(void)
{
	if(head == LEN)
		head = 0;
	return queue[head++];
}

int is_empty(void)
{
	return head == tial;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i,j;
	for (i=0; i<MAX_ROW; i++){
		for(j=0; j<MAX_COL; j++)
			printf("%d ",maze[i][j]);
		printf("\n");
	}
	printf("*********\n");
}

void visit(int row, int col)
{
	struct point visit_point = {row, col, head};
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = {0,0,-1};
	maze[p.row][p.col] = 2;
	enqueue(p);
	int n = 0;
	while(!is_empty()){
		p = dequeue();
		if(p.row == MAX_ROW -1 && p.col == MAX_COL - 1)
			break;
		if(p.row+1 < MAX_ROW && maze[p.row+1][p.col] == 0)
			visit(p.row+1,p.col);
		if(p.col+1 < MAX_COL && maze[p.row][p.col+1] == 0)
			visit(p.row,p.col+1);
		if(p.row-1 >=0 && maze[p.row-1][p.col] == 0)
			visit(p.row-1,p.col);
		if(p.col-1 >=0 && maze[p.row][p.col-1] == 0)
			visit(p.row,p.col-1);
		
		printf("%d\n",n++);
		print_maze();
	}
	if(p.row == MAX_ROW -1 && p.col == MAX_COL -1){
		printf("Yes there is a path\n");	
	}else
		printf("No path!\n");
	return 0;
}
