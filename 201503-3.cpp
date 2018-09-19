/**
 * 201503-3 ½ÚÈÕ
 */
#include <bits/stdc++.h>
using namespace std;

int isleapyear(int y)
{
    return (!(y % 4) && y % 100) || !(y % 400);
}

int mday[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

int main()
{
    int a, b, c, y1, y2;
    scanf("%d %d %d %d %d", &a, &b, &c, &y1, &y2);

    int day = 2;
    for (int i = 1850; i < y1; i++)
    {
        if (isleapyear(i))
            day += 366;
        else
            day += 365;
        day %= 7;
    }
    for (int i = y1; i <= y2; i++)
    {
        int leap = isleapyear(i);
        int tmp = day;
        for (int j = 1; j < a; j++)
        {
            tmp = (tmp + mday[j][leap]) % 7;
        }
        int d = (7 + c - tmp) % 7 + 1;
        d += 7 * (b - 1);
        if (d <= mday[a][leap])
            printf("%04d/%02d/%02d\n", i, a, d);
        else
            printf("none\n");
        day = (day + 365 + leap) % 7;
    }

    return 0;
}
