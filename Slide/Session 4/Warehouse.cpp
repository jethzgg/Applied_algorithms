#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

int n, D, T;
vector<int> a(MAX + 1), t(MAX + 1);
vector<vector<int>> dp(MAX + 1, vector<int>(101, 0));

int main()
{
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            dp[i][j] = 0;
            for (int k = i - D; k <= i - 1; k++)
            {
                if (k >= 0)
                {
                    if (j < t[i])
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = max(dp[k][j - t[i]] + a[i], dp[i][j]);
                    }
                }
            }
        }
    }
    int MaxAmount = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            MaxAmount = max(MaxAmount, dp[i][j]);
        }
    }
    cout << MaxAmount << "\n";
    return 0;
}