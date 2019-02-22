#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * GetStr()
{
	char *str = NULL;
	char *_str = NULL;
	int i = 1;
	str = (char *)malloc(sizeof(char) + 2);

	while ((str[i - 1] = getchar()) != '\n')
	{
		if (str[i - 1] == EOF)
		{
			break;
		}
		i++;
		str[i - 1] = '\0';
		if (NULL != _str)
		{
			free(_str);
		}
		_str = str;
		str = (char *)malloc(sizeof(char)*(i + 1));
		if (NULL == str)
		{
			free(_str);
			printf("No enough memory!");
			return NULL;
		}
		strcpy(str, _str);
	}
	free(str);

	return _str;
}

char* GetStrTemp()  
{  
        char* str;  
        char* _str;  
        int i = 1;  
        str = (char*)malloc(sizeof(char) * (i + 1));  
        while('\n' != (str[i - 1] = getchar()))  
        {  
                i ++;  
                _str = (char*)malloc(strlen(str) + 1); 
                str[i - 1] = '\0'; 
                strcpy(_str, str);  
                free(str);  
                str = (char*)malloc(sizeof(char) * (i + 1));  
                if(NULL == str)  
                {  
                        free(_str);  
                        printf("No enough memory!");  
                        return NULL;  
                }  
                strcpy(str, _str);  
                free(_str);  
        }  
        str[i - 1] = '\0';  
        return str;  
}  

char * GetStr1(FILE *fp)
{
	char *str = NULL;
	char *_str = NULL;
	int i = 1;
	str = (char *)malloc(sizeof(char) + 2);

	while ((str[i - 1] = getc(fp)) != '\n')
	{
		if (str[i - 1] == EOF)
		{
			break;
		}
		i++;
		str[i - 1] = '\0';
		if (NULL != _str)
		{
			free(_str);
		}
		_str = str;
		str = (char *)malloc(sizeof(char)*(i + 1));
		if (NULL == str)
		{
			free(_str);
			printf("No enough memory!");
			return NULL;
		}
		strcpy(str, _str);
	}
	free(str);

	return _str;
}



int main()
{
	int i, num, letterList[26];

	char *result;

	FILE *fp;
	fp = fopen("test.txt", "r");

	result = GetStr();

	if (result != NULL)
	{
		num = strlen(result);
		memset(letterList, 0, sizeof(int) * 26);
		for (i = 0; i < num; i++)
		{
			if (result[i]<'a' || result[i]>'z')
				continue;
			letterList[*(result + i) - 'a']++;
		}
		printf("%s\n", result);
		free(result);
		for (i = 0; i < 26; i++)
		{
			printf("%c:%d\n", 'a' + i, letterList[i]);
		}

		printf("\n");
	}

	fclose(fp);

	return 0;
}
