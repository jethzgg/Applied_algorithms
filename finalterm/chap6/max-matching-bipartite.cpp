#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> adj;  
// adj[task] = list of staffs 
// that can do this task
vector<int> matchTask;    
// matchTask[staff] = task 
// assigned to this staff (0 if none)
vector<bool> visited;
// Kuhn's algorithm 
// (DFS to find augmenting path)
bool dfs(int task)
{
    for (int staff : adj[task])
    {
        if (visited[staff]) continue;
        visited[staff] = true;
        // If staff is free or we can
        // reassign their current task
        if (matchTask[staff] == 0 
            || dfs(matchTask[staff]))
        {
            matchTask[staff] = task;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    
    adj.resize(n + 1);
    matchTask.resize(m + 1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int staff;
            cin >> staff;
            adj[i].push_back(staff);
        }
    }
    
    int result = 0;
    for (int task = 1; task <= n; task++)
    {
        visited.assign(m + 1, false);
        if (dfs(task))
        {
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
