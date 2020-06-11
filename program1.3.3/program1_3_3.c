#include<stdio.h>
#include<stdlib.h>

#define N 1000
#define M 10

typedef struct student
{
	char * Id;
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

Student * GetStudent(char * Id,int score)
{
	Student * str;

	str=(Student *)malloc(sizeof(Student));
	str->Id = Id;
	str->score = score;
	return str;
}

int main()
{
	int i,n;
	//考生人数n
	scanf("%d",&n);
	while(n!=0)
	{
		int m,g,j,score=0,temp;
		//考题数m,分数线g
		int mnum[M];
		char * p;
		Student *stu[N];
		scanf("%d%d",&m,&g);
		printf("m:%d,g:%d\n",m,g);
		for(i=0;i<m;i++)
		{
			scanf("%d",&mnum[i]);
		}
		//考生号 题目总数 题号(1-M)
		for(i=0;i<n;i++)
		{
			p=GetStr();
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&temp);
				score+=mnum[temp-1];
			}
			stu[i]=GetStudent(p,score);
		}

		//输出
		//不低于分数线的考生人数
		//分数高低 输出Student信息
		printf("output g:%d",g);
		for(i=0;i<n;i++)
		{
			if(stu[i]->score>=g)
			{
				printf("%s %d\n",stu[i]->Id,stu[i]->score);
			}
			
		}


		scanf("%d",&n);
	}



	return 0;
}