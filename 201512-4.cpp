// 一笔画（欧拉回路）问题。此题注意多环情况。
// 题目要求按最小序访问，从某个点出发，并非序号最小的邻接点为下一个点。
// 如1->2->3->4->5
//   1<-<-3 3<-<-5

#include <bits/stdc++.h>
using namespace std;

set<int> graph[10001];
int root[10001];
int cnt[10001];
bool visited[10001][10001];

int findRoot(int x)
{
    if (root[x] == x)
        return x;
    int tmp = findRoot(root[x]);
    root[x] = tmp;
    return tmp;
}

bool join(int x, int y)
{
    int a = findRoot(x);
    int b = findRoot(y);
    if (a != b)
    {
        if (a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        root[a] = b;
        return true;
    }
    return false;
}

// 模拟递归栈状态
struct state {
    int cur;    // 当前访问的点
    int i;      // 遍历到第几个邻接点
};

int main()
{
    int n, m;
    cin >> n >> m;
    int odd = 0;
    int lt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 0;
        root[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
        visited[x][y] = visited[y][x] = false;
        if (join(x, y))
            lt++;
        cnt[x]++;
        cnt[y]++;
    }
    // 判断连通
    if (lt != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    // 奇数度的点个数
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] % 2 == 1)
            odd++;
    }

    if (!(odd == 0 || (odd == 2 && cnt[1] % 2 == 1)))
    {
        cout << -1 << endl;
        return 0;
    }


    stack<state> q; // 模拟递归栈，直接使用递归系统测试会爆栈
    stack<int> res;
    q.push({1, 0});
    while (!q.empty())
    {
        int cur = q.top().cur;
        int i = q.top().i;
        q.pop();
        set<int>::iterator it = graph[cur].begin();
        for (int j = 0; j < i && it != graph[cur].end(); ++j)
            ++it;
        for (; it != graph[cur].end(); ++it)
        {
            if (!visited[cur][*it])
            {
                visited[cur][*it] = visited[*it][cur] = true;
                q.push({cur, i + 1});
                q.push({*it, 0});
                break;
            }
        }

        // 该点遍历完，将结果压栈
        if (it == graph[cur].end())
            res.push(cur);
    }


    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}
