#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char * CalculateResult(char oper, int perv, int next)
{
	char * str;
	char * _str;

	str = (char *)malloc(sizeof(char) * sizeof(int));
	if (NULL == str)
	{
		printf("No enough memory!");
		return NULL;
	}

	switch (oper)
	{
	case '+':
		sprintf(str, "%d", perv + next);
		break;
	case '-':
		sprintf(str, "%d", perv - next);
		break;
	case '*':
		sprintf(str, "%d", perv*next);
		break;
	case '/':
		if (perv%next == 0)
		{
			sprintf(str, "%d", perv / next);
		}
		else
		{
			free(str);
			str = (char *)malloc(sizeof(char) * sizeof(double));
			if (NULL == str)
			{
				printf("No enough memory!");
				return NULL;
			}
			sprintf(str, "%.2lf", (perv*1.0 / next));
		}
		break;
	default:
		break;

	}

	_str = (char*)malloc(strlen(str) + 1);
	if (NULL == str)
	{
		free(str);
		printf("No enough memory!");
		return NULL;
	}
	strcpy(_str, str);
	_str[strlen(_str)] = '\0';
	free(str);
	return _str;
}



int main()
{
	int n;
	char *result;
	scanf("%d\n", &n);
	while (n--)
	{
		char oper;
		int perv, next;
		scanf("%c%d%d", &oper, &perv, &next);
		getchar();
		result = CalculateResult(oper, perv, next);
		printf("%s\n",result);
		free(result);
	}

	return 0;
}