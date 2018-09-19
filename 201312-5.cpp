/**
 * 201312-5 I'm stuck!
 * 两次广搜，先从终点反向搜索，若起点不能达到终点，则输出I'm stuck!
 * 再从起点正向搜索，若遇到的点反向搜索不能达到，则计数加1
 */
#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

struct point {
    int x, y;
};

int r, c;
int sx, sy, tx, ty;
char graph[50][50];
bool sreach[50][50];
bool treach[50][50];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (graph[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }
    memset(sreach, false, sizeof(sreach));
    memset(treach, false, sizeof(treach));

    queue<point> q;
    q.push({tx, ty});
    treach[tx][ty] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        int nx = x - 1, ny = y;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !treach[nx][ny])
        {
            if (graph[nx][ny] == '+' || graph[nx][ny] == '|' || graph[nx][ny] == 'S' || graph[nx][ny] == '.')
            {
                treach[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        nx = x + 1;
        ny = y;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !treach[nx][ny])
        {
            if (graph[nx][ny] == '+' || graph[nx][ny] == '|' || graph[nx][ny] == 'S')
            {
                treach[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        nx = x;
        ny = y - 1;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !treach[nx][ny])
        {
            if (graph[nx][ny] == '+' || graph[nx][ny] == '-' || graph[nx][ny] == 'S')
            {
                treach[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        nx = x;
        ny = y + 1;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !treach[nx][ny])
        {
            if (graph[nx][ny] == '+' || graph[nx][ny] == '-' || graph[nx][ny] == 'S')
            {
                treach[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if (!treach[sx][sy])
    {
        cout << "I'm stuck!" << endl;
        return 0;
    }

    int ans = 0;
    q.push({sx, sy});
    sreach[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        int b, e;
        if (graph[x][y] == 'S' || graph[x][y] == '+' || graph[x][y] == 'T')
        {
            b = 0;
            e = 4;
        }
        else if (graph[x][y] == '|')
        {
            b = 0;
            e = 2;
        }
        else if (graph[x][y] == '-')
        {
            b = 2;
            e = 4;
        }
        else
        {
            b = 1;
            e = 2;
        }
        for (int i = b; i < e; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !sreach[nx][ny] && graph[nx][ny] != '#')
            {
                sreach[nx][ny] = true;
                if (!treach[nx][ny])
                    ans++;
                q.push({nx, ny});
            }
        }
    }
    cout << ans << endl;

    return 0;
}
