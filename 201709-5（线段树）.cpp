#include <bits/stdc++.h>
using namespace std;

struct node {
    int left, right;
    long long val;
};
int a[100001];
node smt[262144];

int n, m;

void updateNum(int cur, int index, int val)
{
    smt[cur].val += val;
    if (smt[cur].left == smt[cur].right && smt[cur].left == index)
    {
        return;
    }

    int mid = (smt[cur].left + smt[cur].right) / 2;
    if (index <= mid)
    {
        updateNum(2 * cur + 1, index, val);
    }
    else
    {
        updateNum(2 * cur + 2, index, val);
    }
}

long long getSum(int cur, int l, int r)
{
    if (l == smt[cur].left && r == smt[cur].right)
    {
        return smt[cur].val;
    }

    int mid = (smt[cur].left + smt[cur].right) / 2;
    if (l <= mid)
    {
        if (r <= mid)
        {
            return getSum(2 * cur + 1, l, r);
        }
        else
        {
            long long leftsum = getSum(2 * cur + 1, l, mid);
            long long rightsum = getSum(2 * cur + 2, mid + 1, r);
            return leftsum + rightsum;
        }
    }
    else
    {
        return getSum(2 * cur + 2, l, r);
    }
}

void init(int cur, int l, int r)
{
    smt[cur].left = l;
    smt[cur].right = r;
    smt[cur].val = 0;
    if (l == r)
        return;

    int mid = (l + r) / 2;
    init(2 * cur + 1, l, mid);
    init(2 * cur + 2, mid + 1, r);
}

int main()
{
    cin >> n >> m;
    init(0, 1, n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        updateNum(0, i + 1, a[i + 1]);
    }
    for (int i = 0; i < m; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            if (v == 1) continue;
            for (int j = l; j <= r; j++)
            {
                if (a[j] >= v && a[j] % v == 0)
                {
                    updateNum(0, j, (a[j] / v) - a[j]);
                    a[j] /= v;
                }
            }
        }
        else if (opt == 2)
        {
            int l, r;
            cin >> l >> r;
            printf("%lld\n", getSum(0, l, r));
        }
    }


    return 0;
}
