/**
 * 201503-5 最小花费 (30分)
 * 树 搜索
 */

#include <bits/stdc++.h>
using namespace std;

struct E {
    int next;
    int c;
};

struct status {
    int index;
    int mincost;
    unsigned long long total;
};

vector<E> edge[100001];

int w[100001];
bool visited[100001];

long long ans;

//bool dfs(int s, int t, int mincost)
//{
//    if (s == t)
//    {
//        cout << ans << endl;
//        return true;
//    }
//
//    visited[s] = true;
//    mincost = min(mincost, w[s]);
//    for (int i = 0; i < edge[s].size(); i++)
//    {
//        int next = edge[s][i].next;
//        if (!visited[next])
//        {
//            long long cost = (long long)mincost * edge[s][i].c;
//            ans += cost;
//            if (dfs(next, t, mincost))
//                return true;
//            ans -= cost;
//        }
//    }
//    return false;
//}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, e;
        cin >> u >> v >> e;
        edge[u].push_back({v, e});
        edge[v].push_back({u, e});
    }
    while (m--)
    {
        int s, t;
        cin >> s >> t;
        if (s == t)
        {
            cout << 0 << endl;
            continue;
        }
        memset(visited, false, sizeof(bool) * (n + 1));
        ans = 0;

        stack<status> q;
        q.push({s, w[s], 0});
        visited[s] = true;
        while (!visited[t])
        {
            int index = q.top().index;
            int mincost = q.top().mincost;
            long long total = q.top().total;
            q.pop();
            for (int i = 0; i < edge[index].size(); i++)
            {
                int next = edge[index][i].next;
                if (visited[next])
                    continue;

                visited[next] = true;
                int c = edge[index][i].c;
                long long tmp = total + c * (long long)mincost;
                int tmpcost = min(mincost, w[next]);
                if (next == t)
                {
                    cout << tmp << endl;
                    break;
                }
                q.push({next, tmpcost, tmp});
            }
        }

    }

    return 0;
}
