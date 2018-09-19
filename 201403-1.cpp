#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    memset(a, 0, sizeof(int));
    int ans = 0;
    while (n--)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            if (a[x] == 2)
                ans++;
            else
                a[x] = 1;
        }
        else
        {
            if (a[-x] == 1)
                ans++;
            else
                a[-x] = 2;
        }
    }
    cout << ans << endl;

    return 0;
}
