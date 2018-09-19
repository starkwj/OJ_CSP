#include <bits/stdc++.h>
using namespace std;

int task[41][3];
struct ut {
    int i, c0, c1, g0;
};

char dp[401][401][401];


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int b, d;
        cin >> task[i][0] >> b >> task[i][1] >> d;
        task[i][2] = min(b, d);
    }

    stack<ut> q;
    q.push({0, 0, 0, 0});
    dp[0][0][0] = -1;
    int ans = 0x1fffffff;
    while (!q.empty())
    {
        int i = q.top().i;
        int c0 = q.top().c0;
        int c1 = q.top().c1;
        int g0 = q.top().g0;
        q.pop();
        if (dp[c0][c1][g0] >= i)
            continue;

        dp[c0][c1][g0] = i;

        int f = max(c0, max(c1, g0));
        if (f >= ans)
            continue;
        if (i == n)
        {
            ans = f;
            continue;
        }

        i++;
        q.push({i, c0 + task[i][0], c1, g0});
        q.push({i, c0, c1 + task[i][0], g0});
        if (task[i][1] < task[i][0])
        {
            q.push({i, c0 + task[i][1], c1, g0 + task[i][1]});
            q.push({i, c0, c1 + task[i][1], g0 + task[i][1]});
        }
        if (task[i][2] < task[i][0] && task[i][2] < task[i][1])
        {
            q.push({i, c0 + task[i][2], c1 + task[i][2], g0 + task[i][2]});
        }
    }
    cout << ans << endl;

    return 0;
}
