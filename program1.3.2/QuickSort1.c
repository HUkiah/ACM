#include<stdio.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void quickSort(int *src,int begin,int end)
{
	if(begin<end)
	{
		int key = src[begin];
		
		int i=begin;
		int j=end;
		printf("Key:%d\n",key);
		while(i<j)
		{
			while(i<j&&src[j]<key)
			{
				j--;
			}
			if(i<j)
			{
				swap(&src[i],&src[j]);
				i++;
			}
			while(i<j&&src[i]>key)
			{
				i++;
			}
			if(i<j)
			{
				swap(&src[i],&src[j]);
				j--;
			}
		}
		src[i]=key;
		quickSort(src,begin,i-1);
		quickSort(src,i+1,end);
	}
}

void QuickSort(int *a,int len)
{
	quickSort(a,0,len);
}

void Print(int *a,int len)
{
	int i;
	for(i=0;i<len;i++)
	 printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	int a[]={47,29,71,99,78,19,24,47};
	
	printf("ÅÅÐòÇ°£º");
	Print(a,(sizeof(a)/sizeof(a[0])));
	QuickSort(a,(sizeof(a)/sizeof(a[0]))-1);
	printf("ÅÅÐòºó£º");
	Print(a,(sizeof(a)/sizeof(a[0])));

	return 0;
}