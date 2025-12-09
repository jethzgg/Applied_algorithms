#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 23

using namespace std;

int n, k, cost = 0, MIN = INT_MAX, load = 0, cmin = INT_MAX;
vector<vector<int>> a(MAX, vector<int>(MAX, 0));
vector<int> visited(MAX, 0);
vector<int> path(MAX, 0);

int check(int i)
{
    if ((i <= n) && (visited[i] == 0) && (load < k))
    {
        return 1;
    }
    if (i > n && visited[i] == 0 && visited[i - n] == 1)
    {
        return 1;
    }
    return 0;
}

void backtrack(int x)
{
    for (int i = 1; i <= (2 * n); i++)
    {
        if (check(i))
        {
            cost += a[path[x - 1]][i];
            path[x] = i;
            visited[i] = 1;
            if (i <= n) load++;
            else load--;
            if (x == (2 * n))
            {
                MIN = min(MIN, cost + a[path[x]][0]);
            }
            else
            {
                int g = cost + cmin * (2 * n - x + 1);
                if (g < MIN) backtrack(x + 1);
            }
            if (i <= n) load--;
            else load++;
            visited[i] = 0;
            cost -= a[path[x - 1]][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i <= (2 * n); i++)
    {
        for (int j = 0; j <= (2 * n); j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
            {
                cmin = min(cmin, a[i][j]);
            }
        }
    }
    backtrack(1);
    cout << MIN << "\n";
    return 0;
}