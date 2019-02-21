#include<stdio.h>

int CalculateResult(int src,int desc)
{
	int temp=src;
	int sum=0;
	while(temp!=0)
	{
		sum+=temp%desc;
		temp/=desc;
	}
	return sum;
}

int main()
{
	int n=1000;
	while(10000>n)
	{
		int result=CalculateResult(n,10);
		if(result==CalculateResult(n,12)&&result==CalculateResult(n,16))
		{
			printf("%d\n",n);
		}
		n++;
	}
	return 0;
}