#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k1, k2;
    vector<vector<int>> res;

    cin >> n >> k1 >> k2;

    res.resize(2, vector<int>(n + 1, 0));
    res[1][k1] = 1;
    res[0][1] = 1;
    res[0][0] = 1;
    res[1][0] = 1;

    for (int i = k1 + 1; i <= n; i++)
    {
        res[0][i] = res[1][i - 1];
        for (int k = k1; k <= k2; k++)
        {
            if (i - k >= 0)
                res[1][i] += res[0][i - k];
        }
    }
    cout << res[0][n] + res[1][n] << "\n";
    return 0;
}