#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
	}
	int val, cnt = 0;
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second > cnt)
		{
			val = it->first;
			cnt = it->second;
		}
	}
	cout << val;
	return 0;
}
