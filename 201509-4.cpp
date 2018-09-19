/**
 * CSP 201509-4 高速公路
 * 计算有向图中，有多少对点能互相连通
 * tarjan算法，解决强连通分量
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> edge[10001];

// 两个状态记录数组：dfn、low
int dfn[10001]; // dfn记录tarjan遍历到该点的次序，为0表示未访问过
int low[10001]; // low记录该点所在连通分量的根节点的dfn值，类似并查集
stack<int> s;   // tarjan算法所用到的栈
int cnt = 0;    // dfn记录的次序
bool inStack[10001];    // 辅助数组，判断某点是否在栈中
int ans = 0;    // 本题的答案


void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    inStack[u] = true;
    // 对该点出发的每条边进行遍历
    for (int i = 0; i < edge[u].size(); i++)
    {
        int t = edge[u][i];
        if (dfn[t] == 0)
        {
            tarjan(t);
            low[u] = min(low[u], low[t]);
        }
        else if (inStack[t])
        {
            low[u] = min(low[u], dfn[t]);
        }
    }
    // 访问完邻接的点（子节点）后，若当前节点为根，则找到一个连通分量
    if (dfn[u] == low[u])
    {
        int k;
        int tmp = 1;
        while (!s.empty() && (k = s.top()) != u)
        {
            s.pop();
            inStack[k] = false;
            ans += tmp;
            tmp++;
        }
        if (!s.empty())
        {
            s.pop();
            inStack[u] = false;
        }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(dfn));
    memset(inStack, false, sizeof(inStack));

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    cout << ans << endl;
    return 0;
}
