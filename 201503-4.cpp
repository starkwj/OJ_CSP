/**
 * 201503-4 ������ʱ
 * �����������ն˾���Ϊ�ڵ㣨���ڵ�Ϊ1��·������
 * �Ӹ��ڵ㿪ʼѰ�ң�ͨ���ø��ڵ����󳤶�Ϊ�����Ⱥ��ӵ���Ⱥ�
 * �������Ⱥ��ӵ����h����(h-1)*2 > ans��������ɸú��Ӳ�������ĳ���
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> node[20001];
int depth[20001];

int getdepth(int i)
{
    if (depth[i] != -1)
        return depth[i];
    int d = 0;
    for (int j = 0; j < node[i].size(); j++)
    {
        d = max(d, getdepth(node[i][j]));
    }
    depth[i] = d + 1;
    return d + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        node[x].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        node[x].push_back(i + n);
    }
    for (int i = 1; i <= n + m; i++)
    {
        depth[i] = -1;
    }

    for (int i = 1; i <= n + m; i++)
    {
        if (depth[i] == -1)
            getdepth(i);
    }
    int ans = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        if (node[k].size() == 0)
        {
            break;
        }
        else if (node[k].size() == 1)
        {
            if (depth[node[k][0]] > ans)
            {
                ans = depth[node[k][0]] + 1;
                q.push(node[k][0]);
            }
        }
        else
        {
            int a = depth[node[k][0]];
            int ai = node[k][0];
            int b = depth[node[k][1]];
            int bi = node[k][1];
            if (a < b)
                swap(a, b);
            for (int i = 2; i < node[k].size(); i++)
            {
                if (depth[node[k][i]] > b)
                {
                    bi = node[k][i];
                    b = depth[bi];
                    if (a < b)
                    {
                        swap(a, b);
                        swap(ai, bi);
                    }
                }
            }
            if (a + b > ans)
            {
                ans = a + b;
                if ((a - 1) * 2 > ans)
                    q.push(ai);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
