/**
 * 201403-4 无线网络
 * 类似SPFA算法结合动态规划
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 0x1fffffff

struct point {
    long long x, y;
};

struct state {
    int index, kcnt;    // 记录节点序号和已经使用的补充路由器个数
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


    int dp[vec.size()][k + 1];  // dp[i][j]表示节点i经过j个补充点（包括自身）的路径长度
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 1;
    bool inQueue[n + m][k + 1]; // 是否在队列中标记数组，避免重复入队
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
        for (int j = 0; j < n + m; j++) // 遍历所有能够达到的节点
        {
            if (i == j) continue;
            if (reach(vec[i], vec[j], r))
            {
                if (j >= n && tk < k)
                {
                    int flag = 1;
                    // 进一步减枝，若j点能通过更少的k个补充点并且更早的到达，则跳过
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
                    // 进一步减枝，若j点能通过更少的k个补充点并且更早的到达，则跳过
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

// 单纯的广搜有bug，测试用例：
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

