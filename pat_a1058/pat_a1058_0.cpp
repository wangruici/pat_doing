#include <cstdio>

int* convert(int nsmoney[3]){
	nsmoney[1]+=nsmoney[2]/29;
	nsmoney[2]=nsmoney[2]%29;
	nsmoney[0]+=nsmoney[1]/17;
	nsmoney[1]=nsmoney[1]%17;
	return nsmoney;
}

int* add(int m1[3],int m2[3]){
	for(int i=0;i<3;++i){
		m1[i]=m1[i]+m2[i];
	}
	return m1;
}
int main(){
	int m1[3],m2[3];
	scanf("%d.%d.%d %d.%d.%d",&m1[0],&m1[1],&m1[2],&m2[0],&m2[1],&m2[2]);
	int* m=add(m1,m2);
	m=convert(m);
	printf("%d.%d.%d\n",m[0],m[1],m[2]);
	return 0;
}


