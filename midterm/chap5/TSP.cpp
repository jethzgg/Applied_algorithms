#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    vector<vector<int>> c;
    vector<int> visited;
    vector<vector<int>> dp;
    cin >> n;

    visited.resize(n + 1, 0);
    visited[0] = 1;
    c.resize(n + 1, vector<int>(n + 1));

    dp.resize(n + 1, vector<int>((1 << n), INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][1 << i] = 0;
        dp[i][1 << i + 1] = c[0][i];
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 << i; j <= (1 << n - 1 << i); j++)
        {
            
        }
    }

    return 0;
}