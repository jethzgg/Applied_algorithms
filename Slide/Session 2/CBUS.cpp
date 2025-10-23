#include <iostream>
#include <vector>
#include <climits>
#define MAX 12

using namespace std;

int n, k;
int MIN = INT_MAX, cmin = INT_MAX;
int cost = 0;
vector<vector<int>> c(2 * MAX + 1, vector<int>(2 * MAX + 1));
vector<int> visited(2 * MAX + 1, 0), path(2 * MAX + 1, 0);
int load = 0;

int available(int i)
{
    if (i <= n && visited[i] == 0 && load < k)
    {
        return 1;
    }
    if (i > n && visited[i] == 0 && visited[i - n] != 0)
    {
        return 1;
    }
    return 0;
}

void backtrack(int x)
{
    for (int i = 1; i <= (2 * n); i++)
    {
        if (available(i))
        {
            if (i <= n) load++;
            else load--;
            visited[i] = 1;
            cost += c[path[x - 1]][i];
            path[x] = i;
            if (x == (2 * n))
            {
                if (MIN > (cost + c[path[x]][0]))
                {
                    MIN = cost + c[path[x]][0];
                }
            }
            else
            {
                int g = cost + cmin * (2 * n - x + 1);
                if (g < MIN)
                {
                    backtrack(x + 1);
                }
            }
            if (i <= n) load--;
            else load++;
            visited[i] = 0;
            cost -= c[path[x - 1]][i];
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
            cin >> c[i][j];
            if (c[i][j] > 0 && cmin > c[i][j]) cmin = c[i][j];
        }
    }
    backtrack(1);
    cout << MIN << "\n";
    return 0;
}