#include <iostream>
using namespace std;

int a[100001];
long long c[100001];	// Ê÷×´Êý×é

long long getsum(int x)
{
	long long sum = 0;
	while (x > 0)
	{
		sum += c[x];
		x -= x & (-x);
	}
	return sum;
}

void update(int i, int x, int n)
{
	while (i <= n) {
		c[i] += x;
		i += i & (-i);
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i, a[i], n);
	}
	
	int mode, l, r;
	int v;
	for (int i = 0; i < m; i++)
	{
		cin >> mode;
		if (mode == 1)
		{
			cin >> l >> r >> v;
			if (v == 1)	continue;
			for (int j = l; j <= r; j++)
			{
				if (a[j] >= v && a[j] % v == 0) {
					update(j, a[j] / v - a[j], n);
					a[j] /= v;
				}
			}
		}
		else
		{
			cin >> l >> r;
			long long sum = getsum(r) - getsum(l - 1);
			cout << sum << endl;
		}
	}
	return 0;
}

