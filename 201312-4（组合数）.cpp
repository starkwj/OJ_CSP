/**
 * 201312-4 有趣的数
 * 组合数法
 * 第一个数一定是2
 * 设2、3共x个（共有x-1种），则0、1共n-x个
 * 即将x-1(除去第一个2)个2/3插入到0...1中，等价于将x-1个相同的球放入(n-x+1)个不同的篮子中，可以有空
 * 再等价于向x-1个球插入n-x个隔板
 * 隔板法得到，放置方法=C(x-1+n-x, x-1) = C(n-1, x-1)
 */
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long comp[1000][1000];

void initComp(int n)
{
    comp[1][0] = comp[1][1] = 1;
    for (int i = 2; i < n; i++)
    {
        comp[i][0] = 1;
        comp[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            comp[i][j] = (comp[i - 1][j - 1] + comp[i - 1][j]) % MOD;
        }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    initComp(n);
    long long ans = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        ans = (ans + comp[n - 1][i - 1] * (i - 1) * (n - i - 1)) % MOD;
    }
    cout << ans << endl;

    return 0;
}
