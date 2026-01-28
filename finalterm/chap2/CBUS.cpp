#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> c;
vector<int> visited, path;
int load = 0, cost = 0, MIN = INT_MAX, cmin = INT_MAX;
int check(int i)
{
    if (i <= n && visited[i] == 0 && load < k)
    {
        return 1;
    }
    if (i > n && visited[i] == 0 && visited[i - n] == 1)
    {
        return 1;
    }
    return 0;
}
void travel(int step)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(i) == 1)
        {
            cost += c[path.back()][i];
            path.push_back(i);
            visited[i] = 1;
            if (i <= n) load++;
            else load--;
            if (step == (2 * n))
            {
                MIN = min(MIN, cost + c[i][0]);
            }
            else
            {
                int g = cost + cmin * (2 * n + 1 - step);
                if (g <= MIN) travel(step + 1);
            }
            if (i <= n) load--;
            else load++;
            visited[i] = 0;
            path.pop_back();
            cost -= c[path.back()][i];
        }
    }
}
int main()
{
    cin >> n >> k;
    c.resize(2 * n + 1, vector<int>(2 * n + 1, 0));
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0) cmin = min(cmin, c[i][j]);
        }
    }
    path.push_back(0);
    visited.resize(2 * n + 1, 0);
    visited[0] = 1;
    travel(1);
    cout << MIN << "\n";
    return 0;
}