#include<stdio.h>

#define N 1001

void Print(int n)
{
	printf("%d ",n);
}

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
		//printf("Key:%d\n",key);
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

int main()
{
	int i,j,h,n;
	int TJ[N],KING[N];
	int kquick,kslow,tquick,tslow,total;
	
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&TJ[i]);
		}

		for(i=0;i<n;i++)
		{
			scanf("%d",&KING[i]);
		}
		quickSort(TJ,0,n-1);
		quickSort(KING,0,n-1);
		
		total=0;
		kquick=tquick=0;
		kslow=tslow=n-1;

		for(i=0;i<n;i++)
		{
			//田忌的最快的马比国王最快的马快时 用田忌最快的马跟国王最快的马比较
			if(TJ[tquick]>KING[kquick])
			{
				total+=200;
				kquick++;
				tquick++;
			}
			else if(TJ[tquick]<KING[kquick])
			{
				total-=200;
				tslow--;
				kquick++;
			}
			else
			{
				for( j=tslow,h=kslow; j>=tquick; j--,h--)
				{
					if(TJ[j]>KING[h])
					{
						total+=200;
						tslow--;
						kslow--;
					}
					else
					{
						//田忌最慢的马与国王最快的马比较
						if(TJ[j]<KING[i])
						{
							total-=200;
							tslow--;
							kquick++;
						}
						tslow=--j;
						kslow=h;
						break;
					}
				
				}
			}
			if(tquick>tslow)
				break;
		}
		printf("%d\n",total);
		scanf("%d",&n);
	}

	return 0;
}