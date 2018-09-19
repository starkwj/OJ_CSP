#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp = 1;
    int ans = 0;
    int x;
    while (cin >> x && x != 0)
    {
        if (x == 1)
        {
            tmp = 1;
            ans += 1;
        }
        else if (x == 2)
        {
            if (tmp == 1 || ans == 0)
                tmp = 2;
            else
                tmp += 2;
            ans += tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
