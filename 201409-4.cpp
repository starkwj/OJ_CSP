/**
 * 201409-4 最优配餐
 * 网格中，多个起点的最短路径
 * 广搜+动态规划
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 0x1fffffff

struct point {
    int x, y;
};

struct cust {
    int x, y, c;
};

bool block[1001][1001];
int dp[1001][1001];

int dir[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, d;
    cin >> n >> m >> k >> d;
    memset(block, false, sizeof(block));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = INF;
    }
    queue<point> q;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x][y] = 0;
        q.push({x, y});
    }
    vector<cust> customers;
    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        customers.push_back({x, y, c});
    }
    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        block[x][y] = true;
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx > 0 && nx <= n && ny > 0 && ny <= n && !block[nx][ny])
            {
                if (dp[nx][ny] > dp[x][y] + 1)
                {
                    dp[nx][ny] = dp[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    long long ans = 0;  // 注意会溢出
    for (int i = 0; i < k; i++)
    {
        int x = customers[i].x;
        int y = customers[i].y;
        int c = customers[i].c;
        ans += dp[x][y] * c;
    }
    cout << ans << endl;

    return 0;
}
