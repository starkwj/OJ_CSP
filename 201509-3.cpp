#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	cin.ignore();
	vector<string> vec;
	map<string, string> smap;
	for (int i = 0; i < m; i++)
	{
		string s;
		getline(cin, s);
		vec.push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		string key, value;
		cin >> key;
		getline(cin, value);
		value.erase(0, 2);
		value.erase(value.end() - 1);
		smap[key] = value;
	}
	
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		string::size_type pos, next = 0;
		while ((pos = it->find("{{ ", next)) != string::npos)
		{
			next = it->find(" }}", pos + 3);
			string temp = it->substr(pos + 3, next - pos - 3);
			if (smap.find(temp) != smap.end())
			{
				it->replace(pos, next - pos + 3, smap[temp]);
				next = pos + smap[temp].size();
			}
			else
			{
				it->erase(pos, next - pos + 3);
				next = pos;
			}
		}	
	}
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
