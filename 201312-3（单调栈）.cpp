#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int h[n];
    int left[n];
    int right[n];
    stack<int> s;
    // ����ջ����ͳ��left��right����
    // left[i]��¼i����h[i]�͵�����±�+1
    // right[i]��¼i�Ҳ��h[i]�͵�����±�
    // ��h[i]Ϊ���ֵ�ľ������ = h[i] * (right[i] - left[i])
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        while (!s.empty() && h[i] <= h[s.top()])
        {
            right[s.top()] = i;    // ��ǰiΪջ��Ԫ���Ҳ�����ı����͵��±�
            s.pop();
        }
        // ��ջ���ջ��ʣ��Ԫ�ر�h[i]��
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
    {
        right[s.top()] = n;    // ʣ��Ԫ���Ҳ�û�и��͵�
        s.pop();
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, h[i] *(right[i] - left[i]));
    }
    cout << ans << endl;
    return 0;
}
