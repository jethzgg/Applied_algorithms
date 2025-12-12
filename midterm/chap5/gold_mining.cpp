#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, L1, L2;
vector<int> a, dp;
deque<int> maximum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L1 >> L2;
    a.resize(n, 0);
    dp.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!maximum.empty() && maximum.front() < i - L2)
        {
            maximum.pop_front();
        }
        if (i - L1 >= 0)
        {
            while (!maximum.empty() &&
            dp[maximum.back()] <= dp[i - L1])
            {
                maximum.pop_back();
            }
            maximum.push_back(i - L1);
        }
        if (!maximum.empty() && 
        maximum.front() >= i - L2 && 
        maximum.front() <= i - L1)
        {
            dp[i] = a[i] + dp[maximum.front()];
        }
        else
        {
            dp[i] = a[i];
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}