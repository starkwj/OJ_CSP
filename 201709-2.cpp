#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct A {
	int x;
	int y;
} A;

bool comp(const A &a, const A &b)
{
	if (a.x == b.x) {
		return a.y <= b.y;
	}
	else
		return a.x < b.x;
}

int main()
{
	vector<A> start;
	vector<A> end;
	
	int n, k;
	cin >> n >> k;
	int w, s, c;
	int key[n];
	for (int i = 0; i < k; i++)
	{
		cin >> w >> s >> c;
		start.push_back({s, w});
		end.push_back({s + c, w});
	}
	for (int i = 0; i < n; i++)
	{
		key[i] = i + 1;
	}
	sort(start.begin(), start.end(), comp);
	sort(end.begin(), end.end(), comp);
	vector<A>::iterator sit = start.begin();
	vector<A>::iterator eit = end.begin();
	while (sit != start.end() && eit != end.end())
	{
		if (sit->x < eit->x)
		{
			for (int i = 0; i < n; i++)
			{
				if (key[i] == sit->y)
				{
					key[i] = 0;
					break;
				}
			}
			sit = start.erase(sit);			
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (key[i] == 0)
				{
					key[i] = eit->y;
					break;
				}
			}
			eit = end.erase(eit);
		}
	}
	while (sit != start.end())
	{
		for (int i = 0; i < n; i++)
		{
			if (key[i] == sit->y)
			{
				key[i] = 0;
				break;
			}
		}
		sit = start.erase(sit);
	}
	while (eit != end.end())
	{
		for (int i = 0; i < n; i++)
		{
			if (key[i] == 0)
			{
				key[i] = eit->y;
				break;
			}
		}
		eit = end.erase(eit);
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << key[i] << " ";
	}

	return 0;
}
