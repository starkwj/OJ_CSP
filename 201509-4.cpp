/**
 * CSP 201509-4 ���ٹ�·
 * ��������ͼ�У��ж��ٶԵ��ܻ�����ͨ
 * tarjan�㷨�����ǿ��ͨ����
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> edge[10001];

// ����״̬��¼���飺dfn��low
int dfn[10001]; // dfn��¼tarjan�������õ�Ĵ���Ϊ0��ʾδ���ʹ�
int low[10001]; // low��¼�õ�������ͨ�����ĸ��ڵ��dfnֵ�����Ʋ��鼯
stack<int> s;   // tarjan�㷨���õ���ջ
int cnt = 0;    // dfn��¼�Ĵ���
bool inStack[10001];    // �������飬�ж�ĳ���Ƿ���ջ��
int ans = 0;    // ����Ĵ�


void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    inStack[u] = true;
    // �Ըõ������ÿ���߽��б���
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
    // �������ڽӵĵ㣨�ӽڵ㣩������ǰ�ڵ�Ϊ�������ҵ�һ����ͨ����
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
