#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> a, prefix, dp;
    cin >> n;
    a.resize(n + 1, 0);
    prefix.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    int MIN = prefix[0];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = prefix[i] - MIN;
        MIN = min(MIN, prefix[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}