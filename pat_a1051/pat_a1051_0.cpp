#include <stack>
#include <iostream>
#include <string>
#include <cstdio>



using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int pop_sequence[1010][1010]={{0}};


bool core_fun(int array[],int len,int max_capa){
	int flag=true;
	int has_push_max=0;
	stack<int> core_stack;
	for(int i=0;i<len;++i){
		while(has_push_max<array[i]&&(int)core_stack.size()<max_capa){
			core_stack.push(++has_push_max);
		}
		if(core_stack.empty()||core_stack.top()!=array[i]){
			flag=false;
			break;
		}
		core_stack.pop();
	}
	return flag;
}

int main(){
	int max_capa=0,len=0,pop_sequence_count=0;
	scanf("%d%d%d",&max_capa,&len,&pop_sequence_count);
	for(int i=0;i<pop_sequence_count;++i){
		for(int j=0;j<len;++j){
			scanf("%d",&pop_sequence[i][j]);
		}
	}
	for(int i=0;i<pop_sequence_count;++i){
		int flag=core_fun(pop_sequence[i],len,max_capa);
		if(flag){
			cout<<"YES"<<endl;			
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
