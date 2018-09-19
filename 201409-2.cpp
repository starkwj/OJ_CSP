#include <bits/stdc++.h>
using namespace std;

int mark[101][101];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(mark, 0, sizeof(mark));

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            if (!mark[i][j])
            {
                mark[i][j] = 1;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
