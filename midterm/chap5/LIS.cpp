#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    a.resize(n, 0);
    dp.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}