#include <cmath>
#include <cstdio>

int get_count(int num){
	int count=0;
	while(num){
		++count;
		num/=10;
	}
	return count;
}

double get_significant(int num,int significant){
	int count=get_count(num);
	if(significant<=count){
		count-=significant;
		for(int i=0;i<count;++i){
			num/=10;
		}
	}
	return num;
}

void print_ans(int significant_count,int significant,int count){
	printf("0.%d",significant);
	int p=get_count(significant);
	for(int i=0;i<significant_count-p;++i){
		printf("0");
	}
	printf("*10^%d",count);
}
int main(){
	float num1,num2;
	int significant_count;
	scanf("%d %f %f",&significant_count,&num1,&num2);
	int count1=get_count((int)num1);
	int count2=get_count((int)num2);
	int sig1=get_significant((int)num1,significant_count);
	int sig2=get_significant((int)num2,significant_count);
	if(sig1==sig2){
		printf("YES ");
		print_ans(significant_count,sig1,count1);
		printf("\n");
	}
	else{
		printf("NO ");
		print_ans(significant_count,sig1,count1);
		printf(" ");
		print_ans(significant_count,sig2,count2);
		printf("\n");
		
	}

	return 0;
}
