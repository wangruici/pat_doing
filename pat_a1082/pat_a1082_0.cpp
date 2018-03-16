#include<stdio.h>
int arr[9];
char brr[9][5]={"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi"};
char crr[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void output(int i,int x)
{
	static int l=0;
	static int flag=0;
	if(x)
	{
		if(l++)
		printf(" ");
		if(flag)
			printf("ling ");
		flag=0;
		if(i<8)
		printf("%s %s",crr[x],brr[i]);
		else
			printf("%s",crr[x]);
	}
	else
	{
		if(i==4)
		{
			printf(" Wan");
			flag=0;
			return;
		}
		if(i==8)
		{
			return;
		}		
		flag=1;
	}
}

int main()
{
	int x,i,j;
	scanf("%d",&x);
	int arr[9];
	
	if(x<0)
	{
		x=-x;
		printf("Fu ");	
	}
	if(x==0)
	{
		printf("ling\n");
		return 0;
	}
	for(i=0,j=100000000;i<9;i++,j/=10)
	{
		arr[i]=(x/j)%10;
	}
	for(i=0;i<9;i++)
	{
		if(arr[i]!=0)
			break;
	}
	for(;i<9;i++)
	{
		output(i,arr[i]);
	}
	printf("\n");
	return 0;
}
