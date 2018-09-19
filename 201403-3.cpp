/**
 * 201403-3 命令行选项
 * 字符串处理
 * 运用map实现多个需求
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string opts;
    cin >> opts;

    map<char, bool> optmap;

    for (int i = 0; i < opts.length(); i++)
    {
        if (i < opts.length() - 1 && opts[i + 1] == ':')
        {
            optmap[opts[i]] = true;
            i++;
        }
        else
            optmap[opts[i]] = false;
    }

    int n;
    cin >> n;
    string str;
    getline(cin, str);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, str);
        istringstream in(str);
        string tmp;
        in >> tmp;
        map<char, string> opt;
        while (in >> tmp)
        {
            if (tmp.length() < 2 || tmp[0] != '-' || optmap.count(tmp[1]) == 0)
                break;
            if (optmap[tmp[1]])
            {
                string optstr;
                in >> optstr;
                // 注意判断后面是否还有参数
                if (optstr.empty())
                    break;
                else
                    opt[tmp[1]] = string(optstr);
            }
            else
            {
                opt[tmp[1]] = "";
            }
        }
        cout << "Case " << i << ":";
        for (map<char, string>::iterator it = opt.begin(); it != opt.end(); it++)
        {
            cout << " -" << it->first;
            if (optmap[it->first])
                cout << " " << it->second;
        }
        cout << endl;
    }

    return 0;
}
