#include <iostream>
using namespace std;

int a[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int diff = a[1] - a[0];
	diff = diff < 0 ? -diff : diff;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int d = a[i] - a[j];
			d = d < 0 ? -d : d;
			if (d < diff)	diff = d;
		}
	}
	cout << diff;
	return 0;
}
