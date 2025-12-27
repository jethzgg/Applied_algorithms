#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, L, cmin = INT_MAX, cnt = 0, vertex, cost = 0;
vector<vector<int>> c, a;
vector<int> visited, path;

void backtrack(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            cost += c[path[k - 1]][i];
            path[k] = i;
            if (k == n - 1)
            {
                if (cost + c[path[k]][vertex] <= L)
                {
                    cnt++;
                }
            }
            else
            {
                int g = cost + cmin * (n - 1 - k);
                if (g <= L) backtrack(k + 1);
            }
            visited[i] = 0;
            cost -= c[path[k - 1]][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    c.resize(n, vector<int>(n, 0));
    a.resize(n, vector<int>(2, 0));
    visited.resize(n, 0);
    path.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    cin >> L;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int distance = fabs(a[i][0] - a[j][0]) + fabs(a[i][1] - a[j][1]);
            c[i][j] = distance;
            c[j][i] = distance;
            cmin = min(cmin, c[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        vertex = i;
        path[0] = i;
        visited[i] = 1;
        backtrack(1);
        visited[i] = 0;
        cost = 0;
    }
    cout << cnt / n << "\n";
    return 0;
}