#include <iostream>
using namespace std;
int main()
{
	int map[15][10];
	for (int i = 14; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
		}
	}
	
	int shape[4][4];
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> shape[i][j];
		}
	}
	
	int col;
	cin >> col;
	int a[4], b[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = 0;
		for (int j = 0; j < 15; j++)
		{
			if (map[j][col - 1 + i])
			{
				a[i] = j + 1;
			}
		}
		
		b[i] = 0;
		for (int k = 3; k >= 0; k--)
		{
			if (shape[k][i])
			{
				b[i] = k + 1;
			}
		}
	}
	int floor = -4;
	for (int i = 0; i < 4; i++)
	{
		if (b[i])
		{
			if (a[i] - b[i] > floor)
				floor = a[i] - b[i];
		}
	}
	floor++;
	for (int i = 0; i < 4; i++)
	{
		int sfloor = i + floor;
		if (sfloor >= 0 && sfloor < 15)
		{
			for (int j = 0; j < 4; j++)
			{
				map[sfloor][col - 1 + j] += shape[i][j];
			}
		}
	}
	
	for (int i = 14; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

