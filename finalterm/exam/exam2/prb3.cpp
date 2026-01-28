#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int m, n, D;
vector<vector<int>> cost;
vector<int> loads, staffs;

int MIN = INT_MAX, c = 0, cmin = INT_MAX, cost_min = 0;

void assign(int task)
{
    for (int i = 0; i < m; i++)
    {
        if (staffs[task] == -1 && loads[i] < D)
        {
            staffs[task] = i;
            loads[i]++;
            c += cost[i][task];
            if (task == (n - 1))
            {
                MIN = min(c, MIN);
                if (MIN == cost_min) 
                {
                    cout << MIN << "\n";
                    exit(0);
                }
            }
            else
            {
                int g = c + cmin * (n - 1 - task);
                if (g <= MIN) assign(task + 1);
            }
            c -= cost[i][task];
            loads[i]--;
            staffs[task] = -1;
        }
    }
}

int main()
{
    cin >> m >> n >> D;
    cost.resize(m, vector<int>(n, 0));
    loads.resize(m, 0);
    staffs.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] != 0) cmin = min(cmin, cost[i][j]);
        }
    }
    for(int j = 0; j < n; j++)
    {
        int m1 = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            m1 = min(m1, cost[i][j]);
        }
        cost_min += m1;
    }
    assign(0);
    cout << ((MIN == INT_MAX) ? -1 : MIN) << "\n";
    return 0;
}