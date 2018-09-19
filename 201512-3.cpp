#include <iostream>
#include <stdlib.h>
using namespace std;

void fillch(int x, int y, char c, char **map, int m, int n)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return;
	
	if (*(*(map + y) + x) == '|' || *(*(map + y) + x) == '-' || *(*(map + y) + x) == '+' || *(*(map + y) + x) == c)
		return;
	else
	{
		*(*(map + y) + x) = c;
	}
	fillch(x - 1, y, c, map, m, n);
	fillch(x + 1, y, c, map, m, n);
	fillch(x, y - 1, c, map, m, n);
	fillch(x, y + 1, c, map, m, n);
}

void drawline(int x1, int y1, int x2, int y2, char **map)
{
	if (x1 == x2)
	{
		if (y1 > y2)
		{
			y2 += y1;
			y1 = y2 - y1;
			y2 = y2 - y1;
		}
		for (int i = y1; i <= y2; i++)
		{
			if (*(*(map + i) + x1) == '+')
				continue;
			else if (*(*(map + i) + x1) == '-')
				*(*(map + i) + x1) = '+';
			else
				*(*(map + i) + x1) = '|';
		}
	}
	else
	{
		if (x1 > x2)
		{
			x2 += x1;
			x1 = x2 - x1;
			x2 = x2 - x1;
		}
		for (int i = x1; i <= x2; i++)
		{
			if (*(*(map + y1) + i) == '+')
				continue;
			else if (*(*(map + y1) + i) == '|')
				*(*(map + y1) + i) = '+';
			else
				*(*(map + y1) + i) = '-';
		}
	}
}

int main()
{
	int m, n, q;
	cin >> m >> n >> q;
	char **map;
	map = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++)
	{
		*(map + i) = (char *)malloc(sizeof(char) * m);
		for (int j = 0; j < m; j++)
		{
			*(*(map + i) + j) = '.';
		}
	}
	for (int i = 0; i < q; i++)
	{
		int mode;
		cin >> mode;
		if (mode)
		{
			int x, y;
			char c;
			cin >> x >> y >> c;
			fillch(x, y, c, map, m, n);
		}
		else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			drawline(x1, y1, x2, y2, map);
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			cout << *(*(map + i) + j);
		}
		cout << endl;
	}
	
	return 0;
}
