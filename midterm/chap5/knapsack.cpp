#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, B;
    vector<int> w, v;
    vector<vector<int>> profits;

    cin >> n >> B;

    w.resize(n + 1, 0);
    v.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    profits.resize(n + 1, vector<int>(B + 1, 0));

    for (int item = 1; item <= n; item++)
    {
        for (int weight = 1; weight <= B; weight++)
        {
            profits[item][weight] = profits[item - 1][weight];
            if (w[item] <= weight)
            {
                profits[item][weight] = max(profits[item][weight], profits[item - 1][weight - w[item]] + v[item]);
            }
        }
    }

    cout << profits[n][B] << "\n";

    return 0;
}