#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 23

using namespace std;

int n, cmin = INT_MAX, MIN = INT_MAX;
int cost = 0;
vector<int> visited(MAX, 0);
vector<int> path(MAX, 0);
vector<vector<int>> c(MAX, vector<int>(MAX, 0));

int check(int i, int k)
{
    if (visited[i]) return 0;
    if (i > n)
    {
        if (visited[i - n] == 0) return 0;
    }
    else
    {
        if ((k - 1) > 0 && path[k - 1] <= n) return 0;
    }
    return 1;
}

void backtrack(int k)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(i, k))
        {
            path[k] = i;
            visited[i] = 1;
            cost += c[path[k - 1]][i];
            if (k == 2 * n)
            {
                if (MIN > (cost + c[i][0]))
                {
                    MIN = cost + c[i][0];
                }
            }
            else
            {
                int g = cost + cmin * (2 * n - k + 1);
                if (g < MIN) backtrack(k + 1);
            }
            visited[i] = 0;
            cost -= c[path[k - 1]][i];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i <= (2 * n); i++)
    {
        visited[i] = 0;
        for (int j = 0; j <= (2 * n); j++)
        {
            cin >> c[i][j];
            if (0 < c[i][j] && c[i][j] < cmin) cmin = c[i][j]; // must be <> 0
        }
    }
    backtrack(1);
    cout << MIN << "\n";
    return 0;
}