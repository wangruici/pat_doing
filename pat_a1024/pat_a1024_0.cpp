#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

void get_reverse_num(int num[],int reverse_num[],int len){
	for(int i=0;i<len;++i){
		reverse_num[i]=num[len-1-i];
	}
	return;
}
int get_sum(int num1[],int len1,int num2[],int len2,int sum[]){
	int goup=0;
	int temp=0;
	int* max_index;
	int min_bits;
	int max_bits;
	if(len1>len2){
		min_bits=len2;
		max_bits=len1;
		max_index=num1;
	}
	else{
		min_bits=len1;
		max_bits=len2;
		max_index=num2;
	}
	for(int i=0;i<min_bits;++i){	
		temp=num1[i]+num2[i]+goup;
		goup=temp/10;
		sum[i]=temp%10;
	}
	for(int i=min_bits;i<max_bits;++i){
		temp=max_index[i]+goup;
		goup=temp/10;
		sum[i]=temp%10;
	}
	if(goup!=0){
		sum[max_bits]=goup;
		return max_bits+1;
	}
	else
		return max_bits;

}
bool isRight(int num1[],int len1){
	for(int i=0,j=len1-1;i<j;++i,--j){
		if(num1[i]!=num1[j]){
			return false;
		}
	}
	return true;
}
void copy(int object[],int begin[],int len){
	for(int i=0;i<len;++i){
		object[i]=begin[i];
	}
}
void print_array(int array[],int len){
	for(int i=len-1;i>=0;--i){
		printf("%d",array[i]);
	}
}
const int maxn=1000;
int main(){
	string s_num;
	int max_time;
	cin>>s_num>>max_time;
	int num[maxn];
	int reverse_num[maxn];
	int sum[maxn];
	int s_num_size=(int)s_num.size();
	for(int i=0;i<s_num_size;++i){
		num[s_num_size-1-i]=s_num[i]-'0';
	}
	int count=0;
	int len1=s_num_size;
	int flag=false;

	if(isRight(num,len1)){
		print_array(num,len1);
		printf("\n%d\n",count);
		return 0;
	}
	while(count<max_time){
		++count;
		get_reverse_num(num,reverse_num,len1);
		len1=get_sum(num,len1,reverse_num,len1,sum);
		copy(num,sum,len1);
		if(isRight(num,len1)){
			flag=true;
			break;
		}
	}
	print_array(num,len1);
	printf("\n%d\n",count);
	return 0;
	
}
