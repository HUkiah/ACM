#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * GetStr()
{
	char *str=NULL;
	char *_str=NULL;
	int i=1;
	str=(char *)malloc(sizeof(char)+2);
	
	while((str[i-1]=getchar())!='\n'&&str[i-1]!=EOF)
	{
		i++;
		str[i-1]='\0';
		if(NULL!=_str)
		{
			free(_str);
		}
		_str=str;
		str=(char *)malloc(sizeof(char)*(i+1));
		if(NULL==str)
		{
			free(_str);
			printf("No enough memory!");
			return NULL;
		}
		strcpy(str,_str);
	}
	free(str);
	if(NULL==_str)
	{
		_str=(char *)malloc(sizeof(char));
		_str[0]='\0';
	}
	return _str;
}

int main()
{
	int i,num,letterList[26];
	
	char *result;
	
	result=GetStr();
	while(*result!=NULL)
	{
		num=strlen(result);
		memset(letterList,0,sizeof(int)*26);
		for(i=0;i<num;i++)
		{
			if(result[i]<'a'||result[i]>'z')
				continue;
			letterList[*(result+i)-'a']++;
		}

		free(result);
		for(i=0;i<26;i++)
		{
			printf("%c:%d\n",'a'+i,letterList[i]);
		}

		printf("\n");
		result=GetStr();
	}
	

	return 0;
}