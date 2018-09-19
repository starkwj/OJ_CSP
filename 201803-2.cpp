#include <bits/stdc++.h>
using namespace std;

struct Ball {
    int x;
    int dir;
    int index;
};

bool cmp1(Ball &a, Ball &b)
{
    return a.x < b.x;
}

bool cmp2(Ball &a, Ball &b)
{
    return a.index < b.index;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L, t;
    cin >> n >> L >> t;
    Ball ball[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ball[i].x;
        ball[i].dir = 1;
        ball[i].index = i;
    }

    sort(ball, ball + n, cmp1);
    while (t--)
    {
        ball[0].x += ball[0].dir;
        if (ball[0].x == 0 || ball[0].x == L)
        {
            ball[0].dir = -ball[0].dir;
        }
        for (int i = 1; i < n; i++)
        {
            ball[i].x += ball[i].dir;
            if (ball[i].x == ball[i - 1].x)
            {
                ball[i - 1].dir = -ball[i - 1].dir;
                ball[i].dir = -ball[i].dir;
            }

        }
        if (n > 1 && (ball[n - 1].x == 0 || ball[n - 1].x == L))
            ball[n - 1].dir = -ball[n - 1].dir;
    }
    sort(ball, ball + n, cmp2);
    cout << ball[0].x;
    for (int i = 1; i < n; i++)
    {
        cout << " " << ball[i].x;
    }
    cout << endl;
    return 0;
}
