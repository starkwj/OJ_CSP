#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int p;
	cin >> p;
	string cur;
	cin >> cur;
	cin.ignore(1000, '\n');
	string::size_type pos;
	vector<string> vec;
	for (int i = 0; i < p; i++)
	{
		string s;
		getline(cin, s);
		if (s[0] != '/')
		{
			s.insert(0, cur + '/');
		}
		while ((pos = s.find("/../")) != string::npos)
		{
			if (pos == 0)
			{
				s.erase(pos + 1, 2);
			}
			else
			{
				string::size_type next = s.rfind('/', pos - 1);
				s.erase(next, pos - next + 3);
			}
		}
		while ((pos = s.find("/./")) != string::npos)
		{
			s.erase(pos + 1, 1);
		}
		while ((pos = s.find("//")) != string::npos)
		{
			s.erase(pos, 1);
		}
		if (s.size() > 1 && s[s.size() - 1] == '/')
			s.erase(s.size() - 1, 1);
		
		vec.push_back(s);
	}
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
