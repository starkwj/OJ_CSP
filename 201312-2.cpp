#include <iostream>
#include <string>
using namespace std;

int main()
{
	string isbn;
	cin >> isbn;
	int a[9];
	int i = 0;
	for (string::iterator it = isbn.begin(); it != isbn.end(); it++)
	{
		if (*it != '-')
		{
			a[i++] = (*it) - '0';
		}
	}
	int x = 0;
	char c;
	for (int i = 0; i < 9; i++)
	{
		x += a[i] * (i + 1);
	}
	x = x % 11;
	if (x == 10)
	{
		c = 'X';
	}
	else
	{
		c = '0' + x;
	}
	if (isbn[12] == c)
	{
		cout << "Right";
	}
	else
	{
		isbn[12] = c;
		cout << isbn;
	}
	
	return 0;
}
