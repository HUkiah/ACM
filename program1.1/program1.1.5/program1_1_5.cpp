#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			int m;
			scanf("%d",&m);
			int sum=0;
			while(m--)
			{
				int a;
				scanf("%d",&a);
				sum+=a;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}