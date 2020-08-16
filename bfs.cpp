#include<stdio.h>
#include<stdlib.h>
int n, s, **a, i, j, *nodes, *visited, *q, *bfs, front = -1, rear = -1, bfs_pos=0;
void enqueue(int ele)
{
 if(front == rear == -1)
 {
 front = rear = 0;
 }
 else
 rear++;

 q[rear] = ele;
}
int dequeue()
{
 return(q[front++]);
}
void unvisited(int c)
{
 int pos;
 for(int i=0;i<n;i++)
 {
 if(nodes[i] == c)
 {
 pos = i;
 break;
 
 }
 }
 visited[pos] = 1;
}

int returnpos(int c)
{
 int pos;
 for(int i=0;i<n;i++)
 {
 if(nodes[i] == c)
 {
 pos = i;
 break;

 }
 }

 return (pos);
}
int peep()
{
 return(q[front]);
}
int fillqueue(int pos)
{
 for(int i=0;i<n;i++)
 {
 if(a[pos][i] == 1 && visited[i] == 0)
 {
 enqueue(nodes[i]);
 bfs[bfs_pos++] = nodes[i];
 unvisited(nodes[i]);
 a[pos][i]=2;
 a[i][pos]=2;
 } 
 }
 return 0;
}
int main()
{
 int pos=0,ele;
 scanf("%d",&n);
 scanf("%d",&s);
 a= (int**)malloc(n*sizeof(int*));
 for(i=0;i<n;i++)
 {
 a[i] = (int*)malloc(n*sizeof(int));
 }
 nodes= (int*)malloc(n*sizeof(int));
 visited= (int*)malloc(n*sizeof(int));
 q = (int*)malloc(n*sizeof(int));
 bfs= (int*)malloc(n*sizeof(int));


 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }

 for(i=0;i<n;i++)
 {
 nodes[i] = i+1;
 }
 for(i=0;i<n;i++)
 {
 visited[i] = 0;
 }
 for(i=0;i<n;i++)
 {
 q[i] = 0; 
 }

 bfs[bfs_pos++] = s;
 unvisited(s);
 enqueue(s);
 pos = returnpos(bfs[0]);

 while(bfs_pos<n)
 {
 fillqueue(pos);
 dequeue();
 ele = peep();
 pos = returnpos(ele);
 }

 printf("BFS= " );
 for(i=0;i<n;i++)
 {
 printf("%d ",bfs[i]);
 }

} 
