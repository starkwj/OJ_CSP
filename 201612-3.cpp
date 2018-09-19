#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int p, r, u, q;
	cin >> p;
	string sfalse = "false";
	string strue = "true"; 
	map<string, int> primap;
	for (int i = 0; i < p; i++)
	{
		string s;
		cin >> s;
		string::size_type pos = s.find(':');
		if (pos == string::npos)
		{
			primap[s] = -1;
		}
		else
		{
			primap[string(s, 0, pos)] = s[pos + 1] - '0';
		}
		
	}
	cin >> r;
	map<string, map<string, int> > rolemap;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			string pri;
			cin >> pri;
			string::size_type pos = pri.find(':');
			if (pos == string::npos)
			{
				rolemap[s][pri] = -1;
			}
			else
			{
				string priname = pri.substr(0, pos);
				int level = pri[pos + 1] - '0';
				map<string, int>::iterator it = rolemap[s].find(priname);
				if (it != rolemap[s].end())
				{
					if (it->second < level)
						rolemap[s][priname] = level;
				}
				else
				{
					rolemap[s][priname] = level;
				}
			}
		}
	}
	cin >> u;
	map<string, map<string, int> > usermap;
	for (int i = 0; i < u; i++)
	{
		string s;
		cin >> s;
		map<string, int> m;
		usermap.insert(map<string, map<string, int> >::value_type(s, m));
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			string rol;
			cin >> rol;
			for (map<string, int>::iterator mit = rolemap[rol].begin(); mit != rolemap[rol].end(); mit++)
			{
				map<string, int>::iterator umit = usermap[s].find(mit->first);
				if (umit != usermap[s].end())
				{
					if (usermap[s][mit->first] < mit->second)
						usermap[s][mit->first] = mit->second;
				}
				else
				{
					usermap[s][mit->first] = mit->second;
				}
			}
		}
	}
	
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string name, pri;
		string priname;
		int level;
		cin >> name >> pri;
		string::size_type pos = pri.find(':');
		if (pos == string::npos)
		{
			priname = pri;
			level = -1;
		}
		else
		{
			priname = pri.substr(0, pos);
			level = pri[pos + 1] - '0';
		}
		map<string, map<string, int> >::iterator umit = usermap.find(name);
		if (umit == usermap.end())
		{
			cout << sfalse << endl;
			continue;
		}
		
		map<string, int>::iterator mit = (umit->second).find(priname);
		if (mit == (umit->second).end())
		{
			cout << sfalse << endl;
			continue;
		}
		
		if (level == -1)
		{
			if (mit->second == -1)
			{
				cout << strue << endl;
			}
			else
			{
				cout << mit->second << endl;
			}
		}
		else
		{
			if (level <= mit->second)
			{
				cout << strue << endl;
			}
			else
			{
				cout << sfalse << endl;
			}
		}
	}
	
	return 0;
}
