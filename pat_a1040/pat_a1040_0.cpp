#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int getMaxSym(string s);
int main(){
	string s;
	getline(cin,s);
	int maxSym=getMaxSym(s);
	cout<<maxSym<<endl;
	return 0;
}

int getMaxSym(string s){
	const int len=(int)s.size();
	int maxSym=0;
	for(int left=0;left<len;++left){
		for(int right=len-1;right>=left;--right){
			int tempSym=1;
			bool flag=true;
			for(int i=left,j=right;i<=j;++i,--j){
				if(s[i]!=s[j]){
					flag=false;
					break;
				}
			}
			if(flag==true){
				tempSym=right-left+1;
				if(maxSym<tempSym){
					maxSym=tempSym;
				}
			}
		}
	}
	return maxSym;

}
