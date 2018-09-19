/**
 * 201512-5 矩阵 (50分)
 * 矩阵快速幂
 * 由于需要求解多个值，故提前先将2的幂次矩阵先算出并保存
 */
#include <bits/stdc++.h>
using namespace std;

char A[31][1000][1000];
int m;
char b[1000];
char I[1000][1000];
char tmpb[1000][1000];

void mul(char x[1000][1000], char y[1000][1000], int n)
{
    char tmp[1000][1000];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                tmp[i][j] ^= x[i][k] & y[k][j];
            }
        }
    }

    memcpy(y, tmp, m * 1000);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            c -= '0';
            A[0][i][j] = c;
        }
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        c -= '0';
        b[i] = c;
    }

    int n;
    cin >> n;
    for (int i = 1; i < 31; i++)
    {
        memcpy(A[i], A[i - 1], sizeof(A[i]));
        mul(A[i - 1], A[i], m);
    }
    while (n--)
    {
        memset(I, 0, sizeof(I));
        for (int i = 0; i < m; i++)
            I[i][i] = 1;
        int k;
        cin >> k;
        int i = 0;
        while (k)
        {
            if (k & 1 == 1)
            {
                mul(A[i], I, m);
            }
            k >>= 1;
            i++;
        }
        for (int i = 0; i < m; i++)
            tmpb[i][0] = b[i];
        mul(I, tmpb, 1);
        for (int i = 0; i < m; i++)
        {
            cout << (char)(tmpb[i][0] + '0');
        }
        cout << endl;
    }

    return 0;
}
