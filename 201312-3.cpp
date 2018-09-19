#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i + 1; j++)
		{
			int min = a[j];
			for (int k = 1; k < i; k++)
			{
				if (min > a[j + k])
					min = a[j + k];
			}
			int square = i * min;
			if (max < square)
				max = square;
		}
	}
	cout << max;
	
	return 0;
}
