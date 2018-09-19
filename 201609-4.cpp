#include <bits/stdc++.h>
using namespace std;

int dis[10001];		// ��Դ�㵽�õ�ľ��� 
int pre[10001];		// ǰ��·������ 
int visited[10001];	// ���ʱ�־���� 

//map<int, map<int, int> > edge;

// ��  ������������У�����֮�����ڶ���· 
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
	
	// ������ 
	node d;
	d.v = 1;
	d.cost = 0;
	q.push(d);
	
	while (!q.empty())
	{
		// ��ȡ����ĵ� 
		node f = q.top();
		q.pop();
		
		int t = f.v;
		if (!visited[t])
		{
			visited[t] = 1;		// ����t 
			total += pre[t]; 	// ������t��ʹ�õı߼ӵ����� 
			int len = edge[t].size();
			for (int k = 0; k < len; k++)
			{
				// ���ݽ��t����dis 
				int t2 = edge[t][k].v;
				if (visited[t2])
					continue;
					
				// ͨ��t��㵽����һ������
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

