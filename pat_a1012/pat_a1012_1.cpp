#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::ceil;
const int maxn=1000010;
char na[4]={'A','C','M','E'};
struct Stu{
	int grades[4];
	int rank[4];
	int lrank;
	Stu(){
		grades[0]=-1;
		lrank=-1;
	}
};
vector<Stu> stu(maxn);
vector<Stu*> stu_re(maxn);
int index=0;
int cmp(Stu *s1,Stu *s2){	
	return s1->grades[index]>s2->grades[index];
}
void write_rank(vector<Stu*> &stu_re,int num,int p){
	index=p;
	sort(stu_re.begin(),stu_re.begin()+num,cmp);
	stu_re[0]->rank[index]=1;
	for(int i=1;i<num;++i){
		if(stu_re[i]->grades[index]==stu_re[i-1]->grades[index]){
			stu_re[i]->rank[index]=stu_re[i-1]->rank[index];
		}
		else{
			stu_re[i]->rank[index]=i+1;
		}
	}

}
int main(){
	int id;
	int stu_num,query_num;
	cin>>stu_num>>query_num;
	for(int i=0;i<stu_num;++i){
		cin>>id;
		cin>>stu[id].grades[1]>>stu[id].grades[2]>>stu[id].grades[3];
		stu[id].grades[0]=ceil((stu[id].grades[1]+stu[id].grades[2]+stu[id].grades[3])/3);
		stu_re[i]=&stu[id];
	}
	for(int i=0;i<4;++i){
		write_rank(stu_re,stu_num,i);	
	}

	for(int i=0;i<maxn;++i){
		if(stu[i].grades[0]==-1){
			continue;
		}
		else{
			int min_rank;
			int min=stu_num;
			for(int j=0;j<4;++j){
				if(min>stu[i].rank[j]){
					min=stu[i].rank[j];
					min_rank=j;
				}
			}
			stu[i].lrank=min_rank;
		}
	}
	for(int i=0;i<query_num;++i){
		cin>>id;
		if(stu[id].grades[0]!=-1){
			cout<<stu[id].rank[stu[id].lrank]<<" "<<na[stu[id].lrank]<<endl;	
		}
		else{
			cout<<"N/A"<<endl;
		}
	}
	return 0;

}


