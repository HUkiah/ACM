#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,s,n,*sum;
	scanf("%d",&n);
	sum=(int *)malloc(sizeof(int)*n);
	s= n;

	while(s--)
	{
		int m;
		scanf("%d",&m);
		*(sum+s)=0;
		while(m--)
		{
			int a;
			scanf("%d",&a);
			*(sum+s)+=a;
		}
	}
	
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",*(sum+i));
		if(i!=0)
			printf("\n");
	}
	
	
	return 0;
}