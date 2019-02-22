#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum 
{
	PERFECT=1,GOOD,TRIANGLE
}Triangle;

void CalculateResult(Triangle triangle)
{
	switch(triangle)
	{
	case 1:
		printf("perfect\n");
		break;
	case 2:
		printf("good\n");
		break;
	case 3:
		printf("just a triangle\n");
		break;
	default:
		break;
	}
}

int main()
{
	int s,n,*result;
	scanf("%d\n",&n);
	result=(int *)malloc(sizeof(int)*n);
	s=n;
	while(s--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);

		if(((a-b)*(b-c)*(c-a))==0)
		{
			result[s]=PERFECT;
			continue;
		}
		else if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
		{
			result[s]=GOOD;
			continue;
		}
		else
		{
			result[s]=TRIANGLE;
		}
	}

	while(n--)
	{
		CalculateResult(result[n]);
	}
	
	free(result);
	return 0;
}