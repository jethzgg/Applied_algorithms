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

    int N, T, D;
    cin >> N >> T >> D;
    vector<int> a(N + 1, 0), t(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0)); //profit
    for (int item = 1; item <= N; item++)
    {
        for (int time = 1; time <= T; time++)
        {
            
            if (t[item] <= time)
            {
                for (int distance = D; distance >= 1; distance--)
                {
                    if (item - distance >= 0)
                        dp[item][time] = max(dp[item][time], dp[item - distance][time - t[item]] + a[item]);
                }
            }
            else
            {
                dp[item][time] = 0;
            }
        }
    }

    int MAX = INT_MIN;

    for (int item = 1; item <= N; item++)
    {
        for (int time = 1; time <= T; time++)
        {
            MAX = max(MAX, dp[item][time]);
        }
    }
    cout << MAX << "\n";
    return 0;
}