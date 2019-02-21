#include<stdio.h>

int main()
{
	int n,sum,result;
	scanf("%d",&n);
	
	while(n!=0)
	{
		sum=0;
		result=1;
		while(n%2==0)
		{
			sum++;
			n/=2;
		}

		while(sum--)
		{
			result*=2;
		}

		printf("%d\n",result);
		scanf("%d",&n);
	}
	return 0;
}