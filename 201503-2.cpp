#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<int, int> imap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		imap[a]++;
	}
	multimap<int, int> rmap;
	map<int, int>::iterator mapit = imap.begin();
	for (; mapit != imap.end(); mapit++)
	{
		rmap.insert({-1 * mapit->second, mapit->first});
	}
	multimap<int, int>::iterator rmapit = rmap.begin();
	for (; rmapit != rmap.end(); rmapit++)
	{
		cout << rmapit->second << " " << -1 * rmapit->first << endl;
	}
	return 0;
}
