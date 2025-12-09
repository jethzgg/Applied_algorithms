#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

const int mod = 10e9 + 7;

int n, k, q, R = 0;
vector<int> d(MAX), visited(MAX, 0);

void backtrack(int j, int nBox, int nCus)
{
    if (j > k)
    {
        if (nCus == n) R++;
        return;
    }

    if (nBox > 0) backtrack(j + 1, 0, nCus);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && (nBox + d[i]) <= q)
        {
            visited[i] = 1;
            backtrack(j, nBox + d[i], nCus + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    backtrack(1,0,0);
    int kfac = 1;
    for (int i = 2; i <= k; i++) kfac *= i;

    R = (R / kfac) % mod;

    cout << R << "\n";

    return 0;
}