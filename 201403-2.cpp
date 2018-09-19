#include <bits/stdc++.h>
using namespace std;

struct window {
    int no;
    int x1, y1;
    int x2, y2;
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    list<window> wins;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        wins.push_back({i, x1, y1, x2, y2});
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int flag = 0;
        for (list<window>::reverse_iterator it = wins.rbegin(); it != wins.rend(); it++)
        {
            if (it->x1 <= x && it->y1 <= y && x <= it->x2 && y <= it->y2)
            {
                cout << it->no << endl;
                window w = *it;
                wins.erase((++it).base());
                wins.push_back(w);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "IGNORED" << endl;
        }
    }

    return 0;
}
