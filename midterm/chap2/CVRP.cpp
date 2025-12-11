#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, K, Q, cmin = INT_MAX, MIN = INT_MAX, cost = 0;
vector<int> d, path, visited;
vector<vector<int>> c;

void backtrack(int k, int nBox, int nCus)
{
    if (k > K)
    {
        if (nCus == n)
        {
            MIN = min(MIN, cost + c[path.back()][0]);
        }
        return;
    }

    if (nBox > 0) 
    {
        cost += c[path.back()][0];
        path.push_back(0);
        backtrack(k + 1, 0, nCus);
        path.pop_back();
        cost -= c[path.back()][0];
    }

    else if (k < K)
    {
        backtrack(k + 1, 0, nCus);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && nBox + d[i] <= Q)
        {
            visited[i] = 1;
            nBox += d[i];
            nCus += 1;
            cost += c[path.back()][i];
            path.push_back(i);
            int g = cost + cmin * (n - nCus);
            if (g < MIN) backtrack(k, nBox, nCus);
            path.pop_back();
            cost -= c[path.back()][i];
            nCus -= 1;
            nBox -= d[i];
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K >> Q;

    d.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    path.push_back(0);
    visited[0] = 1;

    for (int i = 1; i <= n; i++) cin >> d[i];

    c.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0) cmin = min(cmin, c[i][j]);
        }
    }

    backtrack(1, 0, 0);
    cout << MIN << "\n";
    return 0;
}