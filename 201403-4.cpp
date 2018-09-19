/**
 * 201403-4 ��������
 * ����SPFA�㷨��϶�̬�滮
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 0x1fffffff

struct point {
    long long x, y;
};

struct state {
    int index, kcnt;    // ��¼�ڵ���ź��Ѿ�ʹ�õĲ���·��������
};

bool reach(point &a, point &b, long long r)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    long long r;
    cin >> n >> m >> k >> r;
    r *= r;
    vector<point> vec;
    for (int i = 0; i < n + m; i++)
    {
        long long x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }


    int dp[vec.size()][k + 1];  // dp[i][j]��ʾ�ڵ�i����j������㣨����������·������
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 1;
    bool inQueue[n + m][k + 1]; // �Ƿ��ڶ����б�����飬�����ظ����
    memset(inQueue, false, sizeof(inQueue));
    queue<state> q;
    q.push({0, 0});
    inQueue[0][0] = true;
    while (!q.empty())
    {
        int i = q.front().index;
        int tk = q.front().kcnt;
        q.pop();
        inQueue[i][tk] = false;
        for (int j = 0; j < n + m; j++) // ���������ܹ��ﵽ�Ľڵ�
        {
            if (i == j) continue;
            if (reach(vec[i], vec[j], r))
            {
                if (j >= n && tk < k)
                {
                    int flag = 1;
                    // ��һ����֦����j����ͨ�����ٵ�k������㲢�Ҹ���ĵ��������
                    for (int p = tk + 1; p >= 0; p--)
                    {
                        if (dp[j][p] <= dp[i][tk] + 1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        dp[j][tk + 1] = dp[i][tk] + 1;
                        if (!inQueue[j][tk + 1])
                        {
                            q.push({j, tk + 1});
                            inQueue[j][tk + 1] = true;
                        }
                    }
                }
                else if (j < n)
                {
                    int flag = 1;
                    // ��һ����֦����j����ͨ�����ٵ�k������㲢�Ҹ���ĵ��������
                    for (int p = tk; p >= 0; p--)
                    {
                        if (dp[j][p] <= dp[i][tk] + 1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        dp[j][tk] = dp[i][tk] + 1;
                        if (!inQueue[j][tk])
                        {
                            q.push({j, tk});
                            inQueue[j][tk] = true;
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[1][i]);
    }
    cout << (ans - 2) << endl;


    return 0;
}

// �����Ĺ�����bug������������
//8 5 3 2
//0 0
//0 10
//2 0
//4 0
//4 2
//3 3
//2 4
//0 4
//-2 0
//-2 2
//-2 4
//0 6
//0 8

