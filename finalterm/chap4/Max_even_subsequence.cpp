#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, min_even = 0, min_odd = INT_MAX;
    vector<int> a, prefix_sum, res;

    cin >> n;
    a.resize(n + 1, 0);
    prefix_sum.resize(n + 1, 0);
    res.resize(n + 1, INT_MIN);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (prefix_sum[i] % 2 == 0)
        {
            res[i] = prefix_sum[i] - min_even;
            min_even = min(min_even, prefix_sum[i]);
        }
        else
        {
            if (min_odd != INT_MAX)
            {
                res[i] = prefix_sum[i] - min_odd;
            }
            min_odd = min(min_odd, prefix_sum[i]);
        }
    }
    cout << *max_element(res.begin(), res.end()) << "\n";
    return 0;
}