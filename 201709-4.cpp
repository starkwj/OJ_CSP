#include <iostream>
#include <vector>
#include <set>
using namespace std;

int know[1001][1001];

void dfs(int s, int i, vector<int> vec[], int visited[])
{
	visited[i] = 1;
	know[s][i] = know[i][s] = 1;
	for (vector<int>::iterator it = vec[i].begin(); it != vec[i].end(); it++)
	{
		
		if (!visited[*it]) {
			dfs(s, *it, vec, visited);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec[n + 1];
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
	}
	
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			know[i][j] = i == j;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int visited[n + 1];
		for (int k = 1; k <= n; k++)
		{
			visited[k] = 0;
		}
		visited[i] = 1;
		dfs(i, i, vec, visited);
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int j;
		for (j = 1; j <= n; j++)
		{
			if (know[i][j] == 0) {
				break;
			}
		}
		if (j == n + 1) {
			cnt++;
		}
	}
	cout << cnt;
	
	return 0; 
}

