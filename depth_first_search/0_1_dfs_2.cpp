#include <queue>
#include <cstdio>
#include <stack>
using std::queue;
using std::stack;
const int max_x=1000;
const int max_y=1000;

struct NODE{
	int x,y;
};
typedef struct NODE node;

int matrix[max_x][max_y]={{0}};
bool matrix_visited[max_x][max_y]={{false}};

int get_matrix(int (*matrix)[max_x],int x,int y){
	for(int i=0;i<y;++i){
		for(int j=0;j<x;++j){
			scanf("%d",&(matrix[i][j]));
		}
	}
	return x*y;
}

int print_matrix(int (*matrix)[max_x],int x,int y){
	for(int i=0;i<y;++i){
		for(int j=0;j<x;++j){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	return x*y;
}
#ifndef __NDEBUG__
int print_bool_matrix(bool (*matrix)[max_x],int x,int y){
	for(int i=0;i<y;++i){
		for(int j=0;j<x;++j){
			printf("%d",(int)matrix[i][j]);
		}
		printf("\n");
	}
	return x*y;
}
#endif

bool juge(int x,int y,int (*matrix)[max_x],bool (*matrix_visited)[max_x],const int len_x,const int len_y){
	if(x>=len_x||x<0||y>=len_y||y<0) return false;
	if(matrix[y][x]==0||matrix_visited[y][x]==true) return false;

	return true;
}

void bfs(int x,int y,int (*matrix)[max_x],bool (*matrix_visited)[max_x],const int len_x,const int len_y){
	queue<node> qu;
	node no;
	no.x=x;no.y=y;
	qu.push(no);
	matrix_visited[y][x]=true;
	const int X[]={0,0,1,-1};
	const int Y[]={1,-1,0,0};
	while(!qu.empty()){
		node top=qu.front();
		qu.pop();
#ifndef __NDEBUG__
		printf("(%d,%d) ",top.x,top.y);
#endif
		for(int i=0;i<4;++i){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(juge(newX,newY,matrix,matrix_visited,len_x,len_y)){
				no.x=newX,no.y=newY;
				qu.push(no);
				matrix_visited[newY][newX]=true;

			}
		}
	}
}
const int X[]={0,0,1,-1};
const int Y[]={1,-1,0,0};
void dfs(int x,int y,int (*matrix)[max_x],bool (*matrix_visited)[max_x],const int len_x,const int len_y){
	matrix_visited[y][x]=true;
	for(int i=0;i<4;++i){
		int newX=x+X[i];
		int newY=y+Y[i];
		if(juge(newX,newY,matrix,matrix_visited,len_x,len_y)){
			dfs(newX,newY,matrix,matrix_visited,len_x,len_y);
		}
	}
}

void dfs2(int x,int y,int (*matrix)[max_x],bool (*matrix_visited)[max_x],const int len_x,const int len_y){
	stack<node> qu;
	node no;
	no.x=x;no.y=y;
	qu.push(no);
	matrix_visited[y][x]=true;
	const int X[]={0,0,1,-1};
	const int Y[]={1,-1,0,0};
	while(!qu.empty()){
		node top=qu.top();
		qu.pop();
		for(int i=0;i<4;++i){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(juge(newX,newY,matrix,matrix_visited,len_x,len_y)){
				no.x=newX,no.y=newY;
				qu.push(no);
				matrix_visited[newY][newX]=true;
			}
		}
	}
}


int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	get_matrix(matrix,x,y);
	print_matrix(matrix,x,y);
	int ans=0;
	for(int i=0;i<y;++i){
		for(int j=0;j<x;++j){
			if(matrix[i][j]==1&&matrix_visited[i][j]==false){
				++ans;
#ifndef __NDEBUG__
				printf("path_%d:",ans);
#endif
				dfs2(j,i,matrix,matrix_visited,x,y);
#ifndef __NDEBUG__
				printf("\n");
#endif
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

