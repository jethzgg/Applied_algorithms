#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 1000000

using namespace std;

int n;
vector<int> a(MAX + 1);
vector<int> prefix_sum(MAX + 1, 0);
vector<vector<int>> f(MAX, vector<int>(2));
int max_even_sum = INT_MIN;

int main()
{
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = a[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }

    f[0][0] = 0;
    f[0][1] = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        max_even_sum = max(max_even_sum, prefix_sum[i] - f[i - 1][prefix_sum[i] % 2]);
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][1];
        f[i][prefix_sum[i] % 2] = min(prefix_sum[i], f[i - 1][prefix_sum[i] % 2]);
    }

    cout << max_even_sum << "\n";

    return 0;
}