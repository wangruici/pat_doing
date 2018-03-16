#include <iostream>
#include <algorithm>
using std::abs;
using std::cin;
using std::cout;
using std::endl;
using std::fill;

struct Point{
	int x,y;
};

int const n=1010;
bool chessBoard[n][n];

bool isSolution(bool (&chessBoard)[n][n],int formate){
	bool row[n]={false};
	bool column[n]={false};
	bool zheng[2*n]={false};
	bool fan[2*n]={false};
	fill(row,row+n,false);
	fill(column,column+n,false);
	fill(zheng,zheng+2*n,false);
	fill(fan,fan+2*n,false);
	for(int i=1;i<=formate;++i){
		for(int j=1;j<=formate;++j){
			if(chessBoard[i][j]==true){
				if(row[i]==true){
					return false;
				}
				else{
					row[i]=true;
				}
				if(column[j]==true){
					return false;
				}
				else{
					column[j]=true;
				}
				if(zheng[i+j]==true){
					return false;
				}
				else{
					zheng[i+j]=true;
				}
				if(i>=j){
					if(fan[i-j]==true){
						return false;
					}
					else{
						fan[i-j]=true;
					}
				}
				if(i<j){
					if(fan[j-i+formate]==true){
						return false;
					}
					else{
						fan[j-i+formate]=true;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int total_num;
	cin>>total_num;
	int temp;
	int k;
	for(int i=1;i<=total_num;++i){
		fill(chessBoard[0],chessBoard[0]+n*n,false);
		cin>>temp;
		for(int j=1;j<=temp;++j){
			cin>>k;
			chessBoard[j][k]=true;
		}
		if(isSolution(chessBoard,temp)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
