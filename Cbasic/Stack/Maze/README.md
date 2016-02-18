#深度优先搜索解迷宫问题

#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5
struct point { int row, col; } stack[512];
int top = 0;
void push(struct point p)
{
stack[top++] = p;
}
struct point pop(void)
{
return stack[--top];
}
int is_empty(void)
{
return top == 0;
}
/*迷宫数组*/
int maze[MAX_ROW][MAX_COL] = {
0, 1, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
/*打印迷宫*/
void print_maze(void)
{
int i, j;
201
for (i = 0; i < MAX_ROW; i++) {
for (j = 0; j < MAX_COL; j++)
printf("%d ", maze[i][j]);
putchar('\n');
}
printf("*********\n");
}

/* 前趋 */
struct point predecessor[MAX_ROW][MAX_COL] = {
{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

/*访问数组*/
void visit(int row, int col, struct point pre)
{
struct point visit_point = { row, col }; //存入访问点
maze[row][col] = 2; //将迷宫中访问点的数据存为2
predecessor[row][col] = pre;//在迷宫该点存入前趋
push(visit_point);将该点入栈
}

int main(void)
{
struct point p = { 0, 0 }; //初始访问点为（0,0）
maze[p.row][p.col] = 2;//访问点存为2
push(p);//入栈

while (!is_empty()) {
p = pop();//出栈

if (p.row == MAX_ROW - 1 /* goal */
&& p.col == MAX_COL - 1)
break;//达到出口
//向右
if (p.col+1 < MAX_COL /* right */
&& maze[p.row][p.col+1] == 0)
visit(p.row, p.col+1, p);
//向下
if (p.row+1 < MAX_ROW /* down */
&& maze[p.row+1][p.col] == 0)
visit(p.row+1, p.col, p);
//向左
if (p.col-1 >= 0 /* left */
&& maze[p.row][p.col-1] == 0)
visit(p.row, p.col-1, p);
//向上
if (p.row-1 >= 0 /* up */
&& maze[p.row-1][p.col] == 0)
visit(p.row-1, p.col, p);

print_maze();
}

if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
{
printf("(%d, %d)\n", p.row, p.col);

while (predecessor[p.row][p.col].row != -
1) {
p = predecessor[p.row][p.col];
printf("(%d, %d)\n", p.row,
p.col);
}
} else
printf("No path!\n");
return 0;
}
