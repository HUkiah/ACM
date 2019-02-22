#include<stdio.h>
#include<string.h>

char * GetResult(int tag)
{
	static char advertise[]={"advertise"};
	static char doesNotMatter[]={"does not matter"};
	static char doNotAdvertise[]={"do not advertise"};
	static char Default[]="";
	if(tag==0)
		return advertise;
	else if(tag == 1)
		return doesNotMatter;
	else if(tag == 2)
		return doNotAdvertise;
	else
		return Default;
}

int main()
{
	int s,n,*result;
	float r,e,c;
	scanf("%d",&n);
	result=(int *)malloc(sizeof(int)*n);

	s=n;
	while(s--)
	{
		scanf("%f%f%f",&r,&e,&c);

		if(e-c>r)
			*(result+s)=0;
		else if(e-c<r)
			*(result+s)=2;
		else
			*(result+s)=1;
	}

	while(n--)
	{
		printf("%s\n",GetResult(*(result+n)));
	}
	return 0;
}