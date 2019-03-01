#include<stdio.h>

#define N 1000
#define M 10

struct student
{
	char num[20];
	int score;
} Student;

char * GetStr()
{
	char * str;
	char * _str;
	int i=1;
	str=(char *)malloc(sizeof(char)*(i+1));
	while(' '!=(str[i-1]=getchar()))
	{
		i++;
		_str = (char *)malloc(strlen(str)+1);
		if(NULL==_str)
		{
			free(str);
			printf("No enough memory");
			return NULL;
		}
		str[i-1]='\0';
		strcpy(_str,str);
		free(str);
		str=(char *)malloc(sizeof(char)*(i+1));
		if(NULL==str)
		{
			free(_str);
			printf("No enough memory");
			return NULL;
		}
		strcpy(str,_str);
		free(_str);
	}
	str[i-1]='\0';
	return str;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	while(n!=0)
	{
		int m,g;
		int mnum[M];
		char (*p)[N];
		scanf("%d%d",&m,&g);
		printf("m:%d,g:%d\n",m,g);
		for(i=0;i<m;i++)
		{
			scanf("%d",&mnum[i]);
		}
		//考生号 题目总数 题号(1-M)
		for(i=0;i<n;i++)
		{
			*p[i]=GetStr();

		}

		for(i=0;i<n;i++)
		{
			printf("%s\n",*p[i]);
		}


		scanf("%d",&n);
	}

	return 0;
}