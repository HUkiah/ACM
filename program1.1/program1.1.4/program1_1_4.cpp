#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			continue;
		int sum=0;
		while(n--)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}

	return 0;
}