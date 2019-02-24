#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) ((x)<(y)?(y):(x))
#define MIN(x,y) ((x)>(y)?(y):(x))

int main()
{
	int n,result;
	scanf("%d\n",&n);

	while(n--)
	{
		int i,s;
		int corridor[200];
		result=0;
		memset(corridor,0,sizeof(int)*200);
		scanf("%d",&s);
		while(s--)
		{
			int a,b,minVal,maxVal;
			scanf("%d%d",&a,&b);
			minVal=MIN(a,b);
			maxVal=MAX(a,b);
			for(i=(minVal+1)/2-1;i<(maxVal+1)/2;i++)
			{
				corridor[i]++;
			}
		}
		for(i=0;i<200;i++)
		{
			result=MAX(result,corridor[i]);
		}
		printf("%d\n",result*10);
	}
	return 0;
}