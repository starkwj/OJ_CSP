// 该题模型等效于——最优二叉搜索树 

#include <bits/stdc++.h>
using namespace std;

int p[1001];
int w[1001][1001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		w[i][i] = 0;
	}
	
	for (int c = 2; c <= n; c++)
	{
		for (int i = 1; i <= n - c + 1; i++)
		{
			int j = i + c - 1;
			int cur = INT_MAX;
			int psum = 0;
			for (int k = i; k < j; k++)
			{
				psum += p[k];
				int temp = w[i][k] + w[k+1][j];
				if (temp < cur)
				{
					cur = temp;
				}
			}
			w[i][j] = cur + psum + p[j];
		}
	}
	printf("%d\n", w[1][n]);
}

