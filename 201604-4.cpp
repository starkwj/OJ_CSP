#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

int forbid[101][101][2];

struct Node {
    int x, y, t;
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {};
};

bool visited[101][101][101];

int n, m, t;

bool isLegal(int x, int y, int t)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (visited[x][y][t])
        return false;
    if (t >= forbid[x][y][0] && t <= forbid[x][y][1])
        return false;

    return true;
}

int main()
{
    queue<Node> q;
    cin >> n >> m >> t;
    for (int i = 0; i < t; i++)
    {
        int r, c;
        cin >> r >> c;
        cin >> forbid[r][c][0] >> forbid[r][c][1];
    }
    if (n == 1 && m == 1)
    {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= 100; k++)
            {
                visited[i][j][k] = false;
            }
        }
    }

    q.push(Node(1, 1, 0));
    visited[1][1][0] = true;
    while (!q.empty())
    {
        int curx = q.front().x;
        int cury = q.front().y;
        int curt = q.front().t;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dir[i][0];
            int ny = cury + dir[i][1];
            int nt = curt + 1;
            if (isLegal(nx, ny, nt))
            {
                if (nx == n && ny == m)
                {
                    printf("%d\n", nt);
                    return 0;
                }
                q.push(Node(nx, ny, nt));
                visited[nx][ny][nt] = true;
            }
        }
    }
    printf("-1\n");

    return 0;
}
