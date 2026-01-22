#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<int>> cost;
vector<int> lx, ly;
vector<int> matchX;
vector<int> matchY;
vector<bool> visitedX, visitedY;

bool dfs(int u)
{
    visitedX[u] = true;
    for (int v = 1; v <= m; v++)
    {
        if (visitedY[v]) continue;
        
        if (lx[u] + ly[v] == cost[u][v])
        {
            visitedY[v] = true;
            if (matchY[v] == 0 || dfs(matchY[v]))
            {
                matchX[u] = v;
                matchY[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    lx.resize(n + 1, 0);
    ly.resize(m + 1, 0);
    matchX.resize(n + 1, 0);
    matchY.resize(m + 1, 0);

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= m; v++)
        {
            lx[u] = max(lx[u], cost[u][v]);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        while (true)
        {
            visitedX.assign(n + 1, false);
            visitedY.assign(m + 1, false);

            if (dfs(u)) break;

            int delta = INT_MAX;
            for (int i = 1; i <= n; i++)
            {
                if (!visitedX[i]) continue;
                for (int j = 1; j <= m; j++)
                {
                    if (visitedY[j]) continue;
                    delta = min(delta, lx[i] + ly[j] - cost[i][j]);
                }
            }

            for (int i = 1; i <= n; i++)
            {
                if (visitedX[i]) lx[i] -= delta;
            }
            for (int j = 1; j <= m; j++)
            {
                if (visitedY[j]) ly[j] += delta;
            }
        }
    }

    int total_weight = 0;
    for (int u = 1; u <= n; u++)
    {
        if (matchX[u] != 0)
        {
            total_weight += cost[u][matchX[u]];
        }
    }
    return total_weight;
}

int main()
{
    cin >> n >> m >> k;
    
    cost.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
    }

    int max_weight = hungary();
    cout << max_weight << "\n";

    for (int u = 1; u <= n; u++)
    {
        if (matchX[u] != 0 && cost[u][matchX[u]] > 0)
        {
            cout << u << " - " << matchX[u] << " (w = " << cost[u][matchX[u]] << ")\n";
        }
    }

    return 0;
}
