#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using std::vector;
using std::sort;
using std::fill;
const int INF=0x3fffffff;
const int max_point_num=510;
vector<int> distance_v;
vector<int> time_v;
int distance_cost1[max_point_num];
int distance_cost2[max_point_num];
int time_cost1[max_point_num];
int time_cost2[max_point_num];
int pre1[max_point_num];
int pre2[max_point_num];
int time_cost_matrix[max_point_num][max_point_num];
int distance_cost_matrix[max_point_num][max_point_num];
bool visited[max_point_num];
void dijkstra(int point_num,int begin_point,int (*cost_matrix1)[max_point_num],\
		int (*cost_matrix2)[max_point_num],int *cost1,int *cost2,int *pre,bool *visited){
	fill(cost1,cost1+max_point_num,INF);
	fill(cost2,cost2+max_point_num,INF);
	fill(visited,visited+max_point_num,false);
	fill(pre,pre+max_point_num,-1);
	cost1[begin_point]=0;
	cost2[begin_point]=0;
	for(int i=0;i<point_num;++i){
		int u=-1;
		int d=INF;
		for(int j=0;j<point_num;++j){
			if(d>cost1[j]&&visited[j]==false){
				u=j;
				d=cost1[j];
			}
		}
		if(u==-1) return;
		visited[u]=true;
		for(int v=0;v<point_num;++v){
			if(visited[v]==false&&cost_matrix1[u][v]!=INF){
				if(cost1[u]+cost_matrix1[u][v]<cost1[v]){
					cost1[v]=cost1[u]+cost_matrix1[u][v];
					pre[v]=u;
					cost2[v]=cost2[u]+cost_matrix2[u][v];
				}
				else if(cost1[u]+cost_matrix1[u][v]==cost1[v]){
					if(cost2[u]+cost_matrix2[u][v]<cost2[v]){
						cost2[v]=cost2[u]+cost_matrix2[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
/*
void print_pre(int point,int *pre){
	if(pre[point]==-1){
		printf(" %d",point);
		return;
	}
	else{
		print_pre(pre[point],pre);
		printf(" -> %d",point);	
	}
}
*/
void get_ans(int point,int *pre,vector<int> &v){
	if(pre[point]==-1){
		v.push_back(point);
		return;
	}
	else{
		v.push_back(point);
		get_ans(pre[point],pre,v);	
	}
}
void print_ans(vector<int> &v){
	printf(": ");
	for(int i=v.size()-1;i>=0;--i){
		printf("%d",v[i]);
		if(i!=0) printf(" -> ");
	}
	printf("\n");
}

void dijkstra(int point_num,int begin_point,int (*cost_matrix1)[max_point_num],\
		int (*cost_matrix2)[max_point_num],int *cost1,int *cost2,int *pre,bool *visited);
int main(){
	fill(distance_cost_matrix[0],distance_cost_matrix[0]+max_point_num*max_point_num,INF);
	fill(time_cost_matrix[0],time_cost_matrix[0]+max_point_num*max_point_num,INF);
	int point_num;
	int road_num;
	int flag;
	int v1;
	int v2;
	int t;
	int d;
	scanf("%d %d",&point_num,&road_num);
	for(int i=0;i<road_num;++i){
		scanf("%d %d %d %d %d",&v1,&v2,&flag,&d,&t);
		if(flag){
			distance_cost_matrix[v1][v2]=d;
			distance_cost_matrix[v2][v1]=INF;
			time_cost_matrix[v1][v2]=t;
			time_cost_matrix[v2][v1]=INF;
		}
		else{
			
			distance_cost_matrix[v1][v2]=distance_cost_matrix[v2][v1]=d;
			time_cost_matrix[v1][v2]=time_cost_matrix[v2][v1]=t;
		}
	}
	int begin_point;
	int end_point;
	scanf("%d %d",&begin_point,&end_point);

	dijkstra(point_num,begin_point,distance_cost_matrix,time_cost_matrix,distance_cost1,time_cost1,pre1,visited);
	dijkstra(point_num,begin_point,time_cost_matrix,distance_cost_matrix,time_cost2,distance_cost2,pre2,visited);
/*
	for(int i=0;i<point_num;++i){
		if(pre1[i]!=pre2[i]){
			printf("Distance = %d:",distance_cost1[end_point]);
			print_pre(end_point,pre1);
			printf("\n");
			printf("Time = %d:",time_cost2[end_point]);
			print_pre(end_point,pre2);
			printf("\n");
			return 0;
		}
	}
	
	printf("Distance = %d; ",distance_cost1[end_point]);
	printf("Time = %d:",time_cost1[end_point]);
	print_pre(end_point,pre1);
	printf("\n");
	return 0;
*/	
	get_ans(end_point,pre1,distance_v);
	get_ans(end_point,pre2,time_v);
	if(time_v==distance_v){
		printf("Distance = %d; ",distance_cost1[end_point]);
		printf("Time = %d",time_cost2[end_point]);
		print_ans(distance_v);
		
	}
	else{
		printf("Distance = %d",distance_cost1[end_point]);
		print_ans(distance_v);
		printf("Time = %d",time_cost2[end_point]);
		print_ans(time_v);
	}
	return 0;
}
