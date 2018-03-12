#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using std::pair;
using std::map;
using std::vector;
using std::sort;

const int maxn=10010;
struct Person{
	int family_root;
	int house_num;
	int total_area;
	int num;
	bool flag;
	Person(){
		this->family_root=-1;
		this->house_num=0;
		this->total_area=0;
		this->num=1;
		this->flag=false;
	}
}family_set[maxn];

struct Ans{
	int total_house_num;
	bool isRoot;
	int total_memer_num;
	int total_area_num;
	int id;
	Ans(){
		this->total_area_num=0;
		this->isRoot=false;
		this->total_memer_num=0;
		this->total_house_num=0;
	}
}ans[maxn];

bool cmp(Ans a1,Ans a2){
	if(a1.isRoot!=a2.isRoot){
		return a1.isRoot>a2.isRoot;
	}
	else if(a1.total_area_num*1.0/a1.total_memer_num!=a2.total_area_num*1.0/a2.total_memer_num){
		return a1.total_area_num*1.0/a1.total_memer_num>a2.total_area_num*1.0/a2.total_memer_num;
	}
	else{
		return a1.id<a2.id;
	}
}

void init(){
	for(int i=0;i<maxn;++i){
		family_set[i].family_root=i;
	}
}

int findRoot(int i){
	int j=i;
	while(family_set[i].family_root!=i){
		i=family_set[i].family_root;
	}

	while(family_set[j].family_root!=i){
		int z=family_set[j].family_root;
		family_set[j].family_root=i;
		j=z;
	}

	return i;
}

int Union(int i,int j){
	int root1=findRoot(i);
	int root2=findRoot(j);
	if(root1>root2){
		family_set[root2].house_num+=family_set[root1].house_num;
		family_set[root2].total_area+=family_set[root1].total_area;
		family_set[root1].family_root=root2;
		return root2;
	}
	else if(root1<root2){
		family_set[root1].house_num+=family_set[root2].house_num;
		family_set[root1].total_area+=family_set[root2].total_area;
		family_set[root2].family_root=root1;
		return root1;
	}
	else{
		;
	}
}


int main(){
	init();
	int temp_house_num;
	int temp_house_area;
	int index1;
	int index2;
	int index3;
	int temp_index;
	int child_num;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;++i){
		scanf("%d %d %d",&index1,&index2,&index3);
		family_set[index1].flag=true;
		if(index2!=-1){
			Union(index1,index2);
			family_set[index2].flag=true;
		}
		if(index3!=-1){
			Union(index1,index3);
			family_set[index3].flag=true;
		}
		scanf("%d",&child_num);
		for(int j=0;j<child_num;++j){
			scanf("%d",&temp_index);
			Union(index1,temp_index);
			family_set[temp_index].flag=true;
		}
		scanf("%d",&temp_house_num);
		scanf("%d",&temp_house_area);
		int root=findRoot(index1);
		family_set[root].house_num+=temp_house_num;
		family_set[root].total_area+=temp_house_area;

	}
	int root;
	int counter=0;
	for(int i=0;i<maxn;++i){	
		if(family_set[i].flag){
			root=findRoot(i);
			if(ans[root].isRoot==false){
				ans[root].isRoot=true;	
				++counter;
				ans[root].id=root;
			}
			++ans[root].total_memer_num;
			if(root==i){
				ans[root].total_area_num=family_set[i].total_area;
				ans[root].total_house_num=family_set[i].house_num;
			}
		}
	}
	sort(ans,ans+maxn,cmp);
	printf("%d\n",counter);
	for(int i=0;i<counter;++i){
		printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].total_memer_num,ans[i].total_house_num*1.0/ans[i].total_memer_num,\
				ans[i].total_area_num*1.0/ans[i].total_memer_num);		
	}
	return 0;
}
