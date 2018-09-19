#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> res;
    string S;
    int mode, n;
    cin >> S >> mode >> n;
    if (!mode)
    {
        transform(S.begin(), S.end(), S.begin(), ::toupper);
    }
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        string tmp = str;
        if (!mode)
        {
            transform(str.begin(), str.end(), tmp.begin(), ::toupper);
        }
        if (tmp.find(S) != string::npos)
            res.push_back(str);
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}
