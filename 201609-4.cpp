#include <bits/stdc++.h>
using namespace std;

int dis[10001];		// 从源点到该点的距离 
int pre[10001];		// 前驱路径长度 
int visited[10001];	// 访问标志数组 

//map<int, map<int, int> > edge;

// 边  此题测试样例中，两点之间会存在多条路 
struct e {
	int v;
	int d;
};
vector<e> edge[10001];

struct node {
	int v;
	int cost; 
	bool operator<(const node& d) const
	{
		return cost > d.cost;
	}
};

priority_queue<node> q;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	dis[1] = 0;
	pre[1] = 0;
	visited[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dis[i] = INT_MAX;
		pre[i] = INT_MAX;
		visited[i] = 0;
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e e1;
		e1.v = b;
		e1.d = c;
		edge[a].push_back(e1);
		e1.v = a;
		edge[b].push_back(e1);
	}
	
	int total = 0;
	
	// 添加起点 
	node d;
	d.v = 1;
	d.cost = 0;
	q.push(d);
	
	while (!q.empty())
	{
		// 获取最近的点 
		node f = q.top();
		q.pop();
		
		int t = f.v;
		if (!visited[t])
		{
			visited[t] = 1;		// 访问t 
			total += pre[t]; 	// 将访问t所使用的边加到总数 
			int len = edge[t].size();
			for (int k = 0; k < len; k++)
			{
				// 根据结点t更新dis 
				int t2 = edge[t][k].v;
				if (visited[t2])
					continue;
					
				// 通过t结点到达另一结点更短
				int div = edge[t][k].d;
				if (dis[t2] > dis[t] + div)
				{
					dis[t2] = dis[t] + div;
					pre[t2] = div;
					node temp;
					temp.v = t2;
					temp.cost = dis[t2];
					q.push(temp);
				} else if (dis[t2] == dis[t] + div) {
					pre[t2] = min(pre[t2], div);
				}
			}		
		}		
	}

	printf("%d", total);
	return 0;
}

