#include <stdio.h>
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	int i, cnt = 0, cake = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		cake += a[i];
		if (cake >= k)
		{
			cnt++;
			cake = 0;
		}
	}
	cnt += cake > 0 ? 1 : 0; 
	printf("%d", cnt);
	return 0;
}
