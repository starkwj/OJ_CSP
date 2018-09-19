#include <bits/stdc++.h>
using namespace std;

int mark[10002];

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
        int x;
        cin >> x;
        mark[x] = 1;
        if ((x > 0 && mark[x - 1]))
            ans++;
        if (mark[x + 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
