#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100003

int main()
{
	int i, num, letterList[26];

	char result[N];

	while (gets(result))
	{
		num = strlen(result);
		memset(letterList, 0, sizeof(int) * 26);
		for (i = 0; i < num; i++)
		{
			if(result[i]<'a'||result[i]>'z')
				continue;
			letterList[*(result + i) - 'a']++;
		}

		for (i = 0; i < 26; i++)
		{
			printf("%c:%d\n", 'a' + i, letterList[i]);
		}

		printf("\n");
	}

	return 0;
}