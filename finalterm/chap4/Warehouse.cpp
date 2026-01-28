#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, T, D;
    vector<int> a, t;
    vector<vector<int>> dp;
    cin >> N >> T >> D;
    a.resize(N + 1, 0);
    t.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }
    dp.resize(N + 1, vector<int>(T + 1, 0));
    for (int i = 1; i <= N; i++)
    { //warehouse (conditional knapsack)
        for (int j = 1; j <= T; j++)
        {
            for (int d = 1; d <= D; d++)
            {
                if (i - d >= 0)
                {
                    if (j >= t[i])
                    {
                        dp[i][j] = max(dp[i][j], 
                                dp[i - d][j - t[i]] + a[i]);
                    }
                }
            }
        }
    }
    int MAX = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            MAX = max(MAX, dp[i][j]);
        }
    }
    cout << MAX << "\n";
    return 0;
}