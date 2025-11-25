#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;

int n;
vector<int> a(MAX + 1, 0);
vector<int> dp(MAX + 1, 0);
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}