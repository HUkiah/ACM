#include<stdio.h>

typedef int bool;

#define true 1
#define false 0

#define N 1001

char line[N][N], used[N]; //��ʾ����nֵ,��ʾTJ�����Ƿ��ܴ��King
int king[N];
int TJ[N];

bool find(int x)
{
	int i;
	for (i = N - 1; i >= 1; i--)
	{
		if (line[x][i] == 't' && used[i] == 'f')
		{
			used[i] = 't';
			if (king[i] == i || find(king[i]))
			{
				king[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int s, n,eq=0;
	scanf("%d", &n);

	while (n != 0)
	{
		int i, ans = 0;
		//�滻n,�������
		s = n;

		memset(line, 'f', sizeof(line));
		memset(used, 'f', sizeof(used));
		memset(king, 0, sizeof(king));
		memset(TJ, 0, sizeof(TJ));
		while (s--)
		{
			int m;
			scanf("%d", &m);
			TJ[m] = m;
		}
		s = n;
		while (s--)
		{
			int m;
			scanf("%d", &m);
			king[m] = m;
			for (i = 1; i < N; i++)
			{
				if (TJ[i]>=m)
				{
					if(TJ[i]==m)
					{
						line[TJ[i]][m] = 'e';
						continue;
					}
					line[TJ[i]][m] = 't';

					//printf("%d -> %d\n", TJ[i], m);
				}
			}
		}



		for (i = N-1; i >=1; i--)
		{
			if (TJ[i])
			{
				memset(used, 'f', N);

				if (find(i))
					ans++;
			}
		}

		printf("%d\n", (2 * ans - n+eq) * 200);

		//printf("�ߵĹ�ϵ��\n");
		//for (i = N - 1; i >= 1; i--)
		//{
		//	int j;
		//	for (j = N - 1; j >= 1; j--)
		//	{
		//		if (line[i][j] == 't')
		//		{
		//			printf("%d -> %d\n", TJ[i], j);
		//		}

		//	}
		//}

		scanf("%d", &n);
	}

	return 0;
}