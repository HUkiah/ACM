#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

bool isLeapYear(int year)
{
	if(year%4==0)
	{
		if(year%100==0&&year%400!=0)
			return FALSE;

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main()
{
	int s,n,*result;
	scanf("%d",&n);
	result = (int *)malloc(sizeof(int)*n);
	s=n;
	while(s--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		while(b)
		{
			if(isLeapYear(a))
			{
				--b;
				if(!b)
				{
						*(result+s)=a;
						break;
				}
				
			}
			a++;	
		}
	}

	while(n--)
	{
		printf("%d\n",*(result+n));
	}
	return 0;
}