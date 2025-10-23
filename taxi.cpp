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

void backtrack(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            cost += c[path[k - 1]][i];
            cost += c[i][i + n];
            path[k] = i;
            if (k == n)
            {
                if (MIN > (cost + c[path[k]][0]))
                {
                    MIN = cost + c[path[k]][0];
                }
            }
            else
            {
                int g = cost + cmin * (2 * (n - k) + 1);
                if (g < MIN) backtrack(k + 1);
            }
            visited[i] = 0;
            cost -= c[path[k - 1]][i];
            cost -= c[i][i + n];
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
            if (c[i][j] < cmin) cmin = c[i][j];
        }
    }
    backtrack(1);
    cout << MIN;
    return 0;
}