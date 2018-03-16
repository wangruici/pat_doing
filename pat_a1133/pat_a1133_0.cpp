#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
const int maxn=100010;

struct Node{
	int data;
	int next;
}link_list[maxn];

struct No{
	int data;
	int address;
	int next;
	No(int _address,int _data,int _next){
		this->data=_data;
		this->address=_address;
		this->next=_next;
	}
};

vector<No>	negative;
vector<No> notGreaterK;
vector<No>	greaterK;
vector<No> ans;

int main(){
	int total_num;
	int begin_add;
	int K;
	scanf("%d%d%d",&begin_add,&total_num,&K);
	int temp_add;
	int temp_data;
	int temp_next;
	for(int i=0;i<total_num;++i){
		scanf("%d%d%d",&temp_add,&temp_data,&temp_next);
		link_list[temp_add].data=temp_data;
		link_list[temp_add].next=temp_next;
	}

	int i=begin_add;
	while(i!=-1){
/*
		if(link_list[i].data>=0&&link_list[i].data<=K){
			notGreaterK.push_back(No(i,link_list[i].data,link_list[i].next));
		}
		else if(link_list[i].data<0){
			negative.push_back(No(i,link_list[i].data,link_list[i].next));
		}
		else{
			greaterK.push_back(No(i,link_list[i].data,link_list[i].next));
		}
*/
		if(link_list[i].data<0){
			negative.push_back(No(i,link_list[i].data,link_list[i].next));
		}
		else if(link_list[i].data<=K){
			notGreaterK.push_back(No(i,link_list[i].data,link_list[i].next));
		}
		else{
			greaterK.push_back(No(i,link_list[i].data,link_list[i].next));
		}
		i=link_list[i].next;
		
	}
	for(int i=0;i<(int)negative.size();i++){
		ans.push_back(negative[i]);
	}

	for(int i=0;i<(int)notGreaterK.size();++i){
		ans.push_back(notGreaterK[i]);
	}
	for(int i=0;i<(int)greaterK.size();++i){
		ans.push_back(greaterK[i]);
	}
	for(int i=0;i<(int)ans.size();++i){
		if(i!=ans.size()-1){
			printf("%05d %d %05d\n",ans[i].address,ans[i].data,\
					ans[i+1].address);
		}
		else{
			printf("%05d %d -1\n",ans[i].address,ans[i].data);
		}
	}
	return 0;
}
