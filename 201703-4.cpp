#include <bits/stdc++.h>
using namespace std;

typedef struct edge {
	int a;
	int b;
	int v;
} Edge;

bool Comp(Edge &x, Edge &y)
{
	return x.v < y.v;
}

int *pre;

// 并查集搜索 
int find(int x)
{
	if (pre[x] == x) {
		return x;
	} else {
		int y = find(pre[x]);
		pre[x] = y;
		return y;
	}
}

void connect(int x, int y)
{
	if (x != y)
	{
		pre[y] = x;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	pre = (int *)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i;
	}
	
	vector<Edge> vec;
	for (int i = 0; i < m; i++)
	{
		Edge e;
		cin >> e.a >> e.b >> e.v;
		vec.push_back(e);
	}
	
	sort(vec.begin(), vec.end(), Comp);

	int cur = 0;
	int i = 0;
	
	// 结束条件应为1号与n号连通 
	while (i < m)
	{
		int fa = find(vec[i].a);
		int fb = find(vec[i].b);
		if (fa != fb)	// 不形成环路
		{
			if (cur < vec[i].v) {
				cur = vec[i].v;
			}
			connect(fa, fb);
			if (find(1) == find(n)) {
				break;
			}
		}
		i++;
	}
	
	printf("%d", cur);
}

