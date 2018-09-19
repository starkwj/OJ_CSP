#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m];
	bool b[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			b[i][j] = false;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
			{
				b[i][j] = b[i][j + 1] = b[i][j + 2] = true;
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n - 2; i++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
			{
				b[i][j] = b[i + 1][j] = b[i + 2][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j])
			{
				a[i][j] = 0;
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
