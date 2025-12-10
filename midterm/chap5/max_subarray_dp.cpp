#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, prefix, sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    a.resize(n + 1, 0);
    prefix.resize(n + 1, 0);
    sum.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    int MIN = 0;

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        sum[i] = max(sum[i], prefix[i] - MIN);
        MIN = min(MIN, prefix[i]);
    }

    cout << sum[n] << "\n";

    return 0;
}