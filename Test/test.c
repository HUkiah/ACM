#include<stdio.h>

#define N 20

typedef struct Student
{
	char * Id;
	int score;
}Student;

Student * GetStu(char * Id,int score)
{
	Student * str;

	str=(Student *)malloc(sizeof(Student));
	str->Id = Id;
	str->score = score;
	return str;
}


void Student_sort(Student * stu,int n)
{
	int i,j;
	Student temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{

			printf("Sort 姓名：%s，年龄：%d\n",stu[i].Id,stu[i].score);

			if((stu[i].score)<(stu[j].score))
			{
				temp =stu[j];
				*stu[i]=*stu[j];
				*stu[i]=temp;

			}else if(stu[i].score==stu[j].score&&strcmp(stu[i].Id,stu[j].Id)>0)
			{
				temp =*stu[j];
				*stu[i]=*stu[j];
				*stu[i]=temp;
			}
		}
	}
}

int main()
{
	int i;
	Student *stu[10];
	for(i=0;i<10;i++)
	{
		stu[i]=GetStu("Custoum001",i);
	}

	//Student_sort(stu,10);

	for(i=0;i<10;i++)
	{
		printf("姓名：%s，年龄：%d\n",stu[i]->Id,stu[i]->score);
	}

	for(i=0;i<10;i++)
	{
		free(stu[i]);
	}
	
	return 0;
}