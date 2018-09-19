#include <stdio.h>
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	for (i = 0; i < m; i++)
	{
		int num, move;
		scanf("%d %d", &num, &move);
		for (j = 0; j < n; j++)
		{
			if (a[j] == num)
			{
				break;
			}
		}
		if (move > 0)
		{
			int k;
			for (k = 0; k < move; k++)
			{
				a[j + k] = a[j + k + 1];
			}
			a[j + move] = num;
		}
		else
		{
			int k;
			for (k = 0; k > move; k--)
			{
				a[j + k] = a[j + k - 1];
			}
			a[j + move] = num;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
