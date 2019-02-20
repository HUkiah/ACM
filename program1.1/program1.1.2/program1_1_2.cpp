#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	/* 二维数组的申请
	int **p=(int **)malloc(sizeof(int *)*n);

	for(int m=0;m<n;m++)
	{
		p[m]=(int *)malloc(sizeof(int)*2);
	}
	*/

	//数组指针的申请
	int (*p)[2] = (int(*)[2])malloc(sizeof(int *)*2*n);

	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i][0],&p[i][1]);
	}

	for(int j=0;j<n;j++)
	{
		printf("%d\n",p[j][0]+p[j][1]);
	}
	

	/*
	for (int c = 0; c < n; ++c)
	{
		free(*(p + c));
	}
	*/
	free(p);


	return 0;
}