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
    // 单调栈用于统计left、right数组
    // left[i]记录i左侧比h[i]低的最近下标+1
    // right[i]记录i右侧比h[i]低的最近下标
    // 以h[i]为最低值的矩形面积 = h[i] * (right[i] - left[i])
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        while (!s.empty() && h[i] <= h[s.top()])
        {
            right[s.top()] = i;    // 当前i为栈顶元素右侧最近的比它低的下标
            s.pop();
        }
        // 出栈完后，栈顶剩余元素比h[i]低
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
    {
        right[s.top()] = n;    // 剩余元素右侧没有更低的
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
