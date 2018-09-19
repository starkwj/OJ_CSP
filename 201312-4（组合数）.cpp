/**
 * 201312-4 ��Ȥ����
 * �������
 * ��һ����һ����2
 * ��2��3��x��������x-1�֣�����0��1��n-x��
 * ����x-1(��ȥ��һ��2)��2/3���뵽0...1�У��ȼ��ڽ�x-1����ͬ�������(n-x+1)����ͬ�������У������п�
 * �ٵȼ�����x-1�������n-x������
 * ���巨�õ������÷���=C(x-1+n-x, x-1) = C(n-1, x-1)
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
