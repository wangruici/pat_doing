# PAT_A1009. Product of Polynomials (25)

[TOC]

## Problem

This time, you are supposed to find A*B where A and B are two polynomials.

**Input Specification:**

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively.  It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.  

**Output Specification:**

For each test case you should output the product of A and B in one line, with the same format as the input.  Notice that there must be NO extra space at the end of each line.  Please be accurate up to 1 decimal place. 

Sample Input

```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

Sample Output

```
3 3 3.6 2 6.0 1 1.6
```

## Code

```C++
#include <cmath>
#include <cstdio>
#include <algorithm>

using std::fill;
int main(){
	const int maxn=2010;
	double ex1[maxn];
	fill(ex1,ex1+maxn,0);
	int num;
	scanf("%d",&num);
	int ex;
	double co;
	for(int i=0;i<num;++i){
		scanf("%d %lf",&ex,&co);
		ex1[ex]=co;
	}

	double ex2[maxn];
	fill(ex2,ex2+maxn,0);
	
	scanf("%d",&num);
	for(int i=0;i<num;++i){
		scanf("%d %lf",&ex,&co);
		ex2[ex]=co;
	}
	double ex3[maxn];
	fill(ex3,ex3+maxn,0);
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxn;++j){
			if(i+j<maxn){
				ex3[i+j]+=ex1[i]*ex2[j];
			}
		}
	}
	int count=0;
	for(int i=0;i<maxn;++i){
		if(ex3[i]!=0){
			++count;
		}
	}
	printf("%d ",count);
	int temp=0;
	for(int i=maxn-1;i>=0;--i){
		if(ex3[i]!=0){
			++temp;
			if(temp<count){
				printf("%d %.1lf ",i,ex3[i]);
			}
			else{
				printf("%d %.1lf\n",i,ex3[i]);
				break;
			}
		}
	}
}
```

```C++
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
const int maxn=2010;
struct ploy{
	int exp;
	double cof;
	ploy():exp(0),cof(0.0){}
};

int main(){
	vector<ploy> p(maxn);
	vector<double> ans(maxn);
	int exp;
	double cof;
	int num;
	cin>>num;
	for(int i=0;i<num;++i){
		scanf("%d %lf",&p[i].exp,&p[i].cof);
	}
	int counter;
	scanf("%d",&counter);
	for(int i=0;i<counter;++i){
		scanf("%d %lf",&exp,&cof);
		for(int j=0;j<num;++j){
			ans[exp+p[j].exp]+=cof*p[j].cof;
		}
	}
	counter=0;
	for(int i=0;i<maxn;++i){
		if(ans[i]!=0.0){
			++counter;
		}
	}
	cout<<counter<<" ";
	for(int i=maxn;i>=0;--i){
		if(ans[i]!=0.0){
			printf("%d %.1lf",i,ans[i]);
			--counter;
			if(counter>0){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
	return 0;
}
```

