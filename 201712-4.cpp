/* 此题有bug，必须用Dijkstra算法，且中间结果用int会出错，应该是计算溢出成负数 */

#include <bits/stdc++.h>
using namespace std;

#define MAXTIRE 1000000

long long ds[501][501], db[501][501];
long long ts[501], tb[501];
long long ss[501];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		ts[i] = tb[i] = MAXTIRE;
		for (int j = 1; j <= n; j++)
		{
			ds[i][j] = db[i][j] = MAXTIRE;
		}
	}

	while (m--)
	{
		int t, a, b;
		long long c;
		cin >> t >> a >> b >> c;
		if (t)
		{
			ds[a][b] = ds[b][a] = min(c, ds[a][b]);
		}
		else
		{
			db[a][b] = db[b][a] = min(c, db[a][b]);
		}
	}
	
	// init
	ts[1] = tb[1] = 0;
	for (int j = 1; j <= n; j++)
	{
		ss[j] = MAXTIRE;
		if (ds[1][j] < MAXTIRE)
		{
			ts[j] = ds[1][j] * ds[1][j];
			ss[j] = ds[1][j];
		}
		if (db[1][j] < MAXTIRE)
		{
			tb[j] = db[1][j];
		}
	}
	ss[1] = 0;
	
	// dijkstra
	bool visiteds[n + 1] = {0}, visitedb[n + 1] = {0};
	visiteds[1] = visitedb[1] = true;
	while (true)
	{
		int u = 0, flag = 0;
		long long minval = MAXTIRE;
		for (int i = 2; i <= n; i++)
		{
			if (!visitedb[i] && tb[i] < minval) {
				minval = tb[i];
				u = i;
				flag = 0;
			}
			if (!visiteds[i] && ts[i] < minval) {
				minval = ts[i];
				u = i;
				flag = 1;
			}
		}
		
		if (u == 0) {
			break;
		}
		
		if (flag) {
			visiteds[u] = true;
		} else {
			visitedb[u] = true;
		}
		
		// 以u为起点扩散 
		for (int i = 1; i <= n; i++)
		{
			// s[i]未访问，且存在u到i的小路 
			if (!visiteds[i] && ds[u][i] < MAXTIRE)
			{
				if (flag) {
					// u前驱为小路 
					long long temp = ts[u] + ds[u][i] * (ds[u][i] + 2 * ss[u]);
					if (temp < ts[i] || (temp == ts[i] && ss[i] > ss[u] + ds[u][i])) {
						ts[i] = temp;
						ss[i] = ss[u] + ds[u][i];
					}
				} else {
					// u前驱为大路
					long long temp = tb[u] + ds[u][i] * ds[u][i];
					if (temp < ts[i] || (temp == ts[i] && ss[i] > ds[u][i])) {
						ts[i] = temp;
						ss[i] = ds[u][i];
					}
				}
			}
			if (!visitedb[i] && db[u][i] < MAXTIRE)
			{
				if (flag) {
					tb[i] = min(tb[i], ts[u] + db[u][i]);
				} else {
					tb[i] = min(tb[i], tb[u] + db[u][i]);
				}
			}
		}
	}
	
	cout << min(ts[n], tb[n]) << endl;
	return 0;
}

