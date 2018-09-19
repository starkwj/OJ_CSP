#include <bits/stdc++.h>
using namespace std;

int mark[1001];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    memset(mark, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mark[x]++;
        cout << mark[x] << " ";
    }

    return 0;
}
