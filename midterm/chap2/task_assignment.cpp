#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 40

using namespace std;

int n, m, D;
vector<vector<int>> c(MAX, vector<int>(MAX, 0));
vector<int> assigneds(MAX, -1);
vector<int> loads(MAX, 0);
int cmin = INT_MAX, cost = 0, MIN = INT_MAX;

int check(int task, int staff)
{
    if (assigneds[task] == -1 && loads[staff] < D)
    {
        return 1;
    }
    return 0;
}

void backtrack(int task)
{
    for (int staff = 0; staff < m; staff++)
    {
        if (check(task, staff))
        {
            assigneds[task] = staff;
            loads[staff]++;
            cost += c[staff][task];
            if (task == (n - 1))
            {
                MIN = min(MIN, cost);
            }
            else
            {
                int g = cost + cmin * (n - 1 - task);
                if (g < MIN) backtrack(task + 1);
            }
            loads[staff]--;
            assigneds[task] = -1;
            cost -= c[staff][task];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> D; 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0) cmin = min(cmin, c[i][j]);
        }
    }
    if (m * D < n)
    {
        cout << -1 << "\n";
    }
    else 
    {
        backtrack(0);
        cout << MIN << "\n";
    }
    return 0;
}