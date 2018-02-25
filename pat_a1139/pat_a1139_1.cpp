#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::string;

struct friends{
	int x,y;
	friends(int a,int b):x(a),y(b){}
};

vector<int> v[10000];
bool matrix[10000][10000];

void search(vector<friends> &ans,int a,int b)
{
	for(int x:v[a]){
		for(int y:v[b]){
			if(x==y||x==b||y==a) continue;
			if(matrix[x][y]) ans.push_back(friends(x,y));
		}
	}
}


bool cmp(const friends &a,const friends &b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

int main(){
	int n,m,k;
	cin>>n>>m;
	string a,b;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		//memory same gender
		if(a.size()==b.size()){
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		//general friends.
		matrix[abs(stoi(a))][abs(stoi(b))]=matrix[abs(stoi(b))][abs(stoi(a))]=true;

	}
	cin>>k;
	while(k--){
		int a,b;
		cin>>a>>b;
		vector<friends> ans;
		search(ans,abs(a),abs(b));
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<endl;
		for(auto w:ans){
			printf("%04d %04d\n",w.x,w.y);
		}
	}
	return 0;
}
