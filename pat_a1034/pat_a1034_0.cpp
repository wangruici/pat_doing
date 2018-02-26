#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>

using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;


const int maxn=2010;
map<string,int> strToint;
map<int,string> intTostr;
bool hasVisited[maxn]={false};
map<string,int> gang;
int tu[maxn][maxn]={{0}};
int weight[maxn]={0};
int count=0;
int mapped(string name){
	if(strToint.find(name)!=strToint.end()){
		return strToint[name];
	}
	else{
		strToint[name]=count;
		intTostr[count++]=name;
		return strToint[name];
	}
}

int time_limit=0,link_count=0;
int numPerson=0;
void DFS(int nowVisited,int &head,int &numMember,int &totalValue){
	++numMember;
	hasVisited[nowVisited]=true;
	if(weight[nowVisited]>weight[head]){
		head=nowVisited;
	}
	for(int i=0;i<numPerson;++i){
		if(tu[nowVisited][i]>0){
			totalValue+=tu[nowVisited][i];
			tu[nowVisited][i]=tu[i][nowVisited]=0;
			if(hasVisited[i]==false){
				DFS(i,head,numMember,totalValue);
			}
		}
	}
	
}

void DFSTrave(){
	for(int i=0;i<numPerson;++i){
		if(hasVisited[i]==false){
			int head=i,numMember=0,totalValue=0;
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>time_limit){
				gang[intTostr[head]]=numMember;
			}
		}
	}
}

int main(){
	int w;
	string str1,str2;
	cin>>link_count>>time_limit;
	for(int i=0;i<link_count;++i){
		cin>>str1>>str2>>w;
		int id1=mapped(str1);
		int id2=mapped(str2);

		weight[id1]+=w;
		weight[id2]+=w;
		tu[id1][id2]+=w;
		tu[id2][id1]+=w;
	}
	numPerson=count;
	DFSTrave();
	cout<<gang.size()<<endl;
	for(map<string,int>::iterator it=gang.begin();it!=gang.end();++it){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
