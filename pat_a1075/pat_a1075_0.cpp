#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
//未能执行的代码
using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

class Pater{
public:
	string id;
	int* scores;
	Pater(string id,int problem_num);
	~Pater();
	int how_per(){
		return this->perfect;
	}
	int count_per(int* maxScores);
private:
	int scores_size;
	int perfect;
friend void sort_PaterScore(Pater* beginer,Pater* ender);
};

int
Pater::count_per(int* maxScores){
	perfect=0;
	if()
	for(int i=0;i<scores_size){
		if(scores[i]>=maxScores[i]){

		}
	}
}

Pater::Pater(string id,int problem_num):id(id),scores_size(problem_num){
	this->scores=new int[problem_num];
	//没有进行过计算的对象返回-1
	this->perfect=-1;
	//未进行读入成绩为-1
	for(int i=0;i<problem_num;++i){
		scores[i]=-1;
	}
}
Pater::~Pater(){
	delete []scores;
}

void
sort_PaterScore(Pater* beginer,Pater* ender){
	struct cmpFunction{
		void operator()(Pater a,Pater b){
			if(a.scores!=b.scores){
				return a.scores>b.scores;
			}
			else if(a.perfect!=b.perfect)
		}
	}
}

