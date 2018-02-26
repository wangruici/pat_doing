#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using std::vector;
using std::queue;
const int maxn=1010;

struct Node{
	int id;
	int layer;
	Node(int _id,int _layer):id(_id),layer(_layer){;}
};
vector<Node> Adj[maxn];

bool inq[maxn]={false};

int BFS(int id,int llayer_counted){
	queue<Node> que;
	int num=0;
	que.push(Node(id,0));
	inq[id]=true;
	while(!que.empty()){
		Node front=que.front();
		que.pop();
		int id=front.id;
		int follow_num=(int)Adj[id].size();
		if(front.layer<llayer_counted){
			for(int i=0;i<follow_num;++i){
				if(inq[Adj[id][i].id]==false){
					++num;
					inq[Adj[id][i].id]=true;
					que.push(Node(Adj[id][i].id,front.layer+1));
				}
				else{
					;
				}
			}
		}
		else{
			;
		}
		
	}
	return num;
}
int main(){
	int user_num=0,llayer_counted=0;
	scanf("%d %d",&user_num,&llayer_counted);
	for(int i=1;i<=user_num;++i){
		int count=0;
		int id=0;
		scanf("%d",&count);
		for(int j=0;j<count;++j){
			scanf("%d",&id);
			Adj[id].push_back(Node(i,0));
		}
	}
	int numQuerry,id;
	scanf("%d",&numQuerry);
	for(int i=0;i<numQuerry;++i){
		scanf("%d",&id);
		memset(inq,false,sizeof(inq));
		int num=BFS(id,llayer_counted);
		printf("%d",num);
		if(i!=numQuerry-1){
			printf("\n");
		}
	}
}
