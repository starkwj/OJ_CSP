/**
 * 201412-3 集合竞价
 * 对buy和sell的有效交易根据价格排序后，遍历查找
 */
#include <bits/stdc++.h>
using namespace std;

struct node {
    bool kind;
    double cost;
    long long num;
    bool cancel;
};

bool cmp(node &a, node &b)
{
    return a.cost < b.cost;
}

int main()
{
    char str[10];
    vector<node> vec;
    while (scanf("%s", str) != EOF)
    {
        if (!strcmp(str, "buy"))
        {
            double cost;
            long long num;
            scanf("%lf %lld", &cost, &num);
            vec.push_back({false, cost, num, false});
        }
        else if (!strcmp(str, "sell"))
        {
            double cost;
            long long num;
            scanf("%lf %lld", &cost, &num);
            vec.push_back({true, cost, num, false});
        }
        else if (!strcmp(str, "cancel"))
        {
            int index;
            scanf("%d", &index);
            vec[index - 1].cancel = true;
            vec.push_back({false, 0, 0, true}); // 注意取消第i行的记录，cancel也占一行，添加个无效的占位记录
        }
    }

    vector<node> buy;
    vector<node> sell;
    for (int i = 0; i < vec.size(); i++)
    {
        if (!vec[i].cancel)
        {
            if (!vec[i].kind)
                buy.push_back(vec[i]);
            else
                sell.push_back(vec[i]);
        }
    }

    sort(buy.begin(), buy.end(), cmp);
    sort(sell.begin(), sell.end(), cmp);
    for (int i = buy.size() - 2; i >= 0; i--)
    {
        buy[i].num += buy[i + 1].num;
    }
    for (int i = 1; i < sell.size(); i++)
    {
        sell[i].num += sell[i - 1].num;
    }

    int j = 0;
    long long sum = 0;
    double curcost = 0.0;
    for (int i = 0; i < buy.size(); i++)
    {
        if (sell[j].cost > buy[i].cost) continue;

        while (j < sell.size() - 1 && sell[j + 1].cost <= buy[i].cost)
        {
            j++;
        }
        long long tmp = min(buy[i].num, sell[j].num);
        if (tmp >= sum)
        {
            sum = tmp;
            curcost = buy[i].cost;
        }
    }
    printf("%.2f %lld\n", curcost, sum);

    return 0;
}
