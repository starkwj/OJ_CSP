/**
 * 201412-4 最优灌溉
 * 最小生成树
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 0x1fffffff

struct e {
    int n;
    int c;
};

vector<e> edge[1001];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    // prim算法
    int ans = 0;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    int dis[n + 1];
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    visited[1] = true;
    int cur = 1;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < edge[cur].size(); i++)
        {
            int t = edge[cur][i].n;
            int c = edge[cur][i].c;
            if (!visited[t] && dis[t] > c)
            {
                dis[t] = c;
            }
        }

        int tmp = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && tmp > dis[i])
            {
                tmp = dis[i];
                cur = i;
            }
        }

        visited[cur] = true;
        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}
