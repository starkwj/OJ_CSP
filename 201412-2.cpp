#include <bits/stdc++.h>
using namespace std;

int dir[2][2] = {
    -1, 1,
    1, -1
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int d = 0;
    int i = 0, j = 0;
    for (int k = 0; k < n * n; k++)
    {
        cout << matrix[i][j] << " ";
        if (d == 0)
        {
            if (j == n - 1)
            {
                i++;
                d = 1;
            }
            else if (i == 0)
            {
                j++;
                d = 1;
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {
            if (i == n - 1)
            {
                j++;
                d = 0;
            }
            else if (j == 0)
            {
                i++;
                d = 0;
            }
            else
            {
                i++;
                j--;
            }
        }
    }

    return 0;
}
