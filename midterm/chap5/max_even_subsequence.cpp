#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int min_odd = INT_MAX;
int min_even = 0;
int MAX = INT_MIN;
int n;
vector<int> a, dp, prefix;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    prefix.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (prefix[i] % 2 == 0)
        {
            dp[i] = prefix[i] - min_even;
            min_even = min(min_even, prefix[i]);
        }
        else
        {
            if (min_odd < INT_MAX)
                dp[i] = prefix[i] - min_odd;
            else
                dp[i] = prefix[i];
            min_odd = min(min_odd, prefix[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] % 2 == 0)
        {
            MAX = max(MAX, dp[i]);
        }
    }
    cout << MAX << "\n";
    return 0;
}