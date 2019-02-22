#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * GetStr()
{
	char * str;
	char * _str;
	int i=1;
	str=(char *)malloc(sizeof(char)*(i+1));
	while('\n'!=(str[i-1]=getchar()))
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

int QuickSum(char * str)
{
	int i,sum=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
			continue;
		sum+=((i+1)*(str[i]-'A'+1));
	}

	return sum;
}

int main()
{
	char *input;
	while(strcmpi("#",(input=GetStr())))
	{
		int sum = QuickSum(input);
		printf("%d\n",sum);
	}

	return 0;
}