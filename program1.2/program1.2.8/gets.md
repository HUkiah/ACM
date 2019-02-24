```C
char *
gets(char *buf)
{
	int c;
	char *s;

	FLOCKFILE(stdin);
	for (s = buf; (c = getchar_unlocked()) != '\n';)
		if (c == EOF)
			if (s == buf) {
				FUNLOCKFILE(stdin);
				return (NULL);
			} else
				break;
		else
			*s++ = c;
	*s = '\0';
	FUNLOCKFILE(stdin);
	return (buf);
}
```

标准库中gets并未进行输入上限的检查，也正是因为这样它是危险的，导致从标准库中除名，有没有一种安全的方式实现gets填充任意字符的特点呢?

gets实现的有点扩充getchar的意思，因为用getchar配合循环语句和内存动态分配，一样可以达到相同的效果，标准库中的gets的“危险”也是应为没有引入动态内存分配导致的,单这样做也会有性能上的损耗,之后我们会尝试C++中Vector容器的做法，将他动态扩容。

```c
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
```



补充下面是除名**gets**后推荐的**fgets**函数

```c
char *fgets(char *s, int n,  FILE *stream)
{
    register int c;
    register char *cs;
    cs=s;
    while(--n>0 &&(c = getc(stream))!=EOF)
    if ((*cs++=  c) =='\n')
          break;
    *cs ='\0';
    return (c == EOF && cs == s) ?NULL :s ;
}
```

