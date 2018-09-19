// һ�ʻ���ŷ����·�����⡣����ע��໷�����
// ��ĿҪ����С����ʣ���ĳ������������������С���ڽӵ�Ϊ��һ���㡣
// ��1->2->3->4->5
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

// ģ��ݹ�ջ״̬
struct state {
    int cur;    // ��ǰ���ʵĵ�
    int i;      // �������ڼ����ڽӵ�
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
    // �ж���ͨ
    if (lt != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    // �����ȵĵ����
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


    stack<state> q; // ģ��ݹ�ջ��ֱ��ʹ�õݹ�ϵͳ���Իᱬջ
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

        // �õ�����꣬�����ѹջ
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
