#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> count(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    deque<pair<int, int>> d;
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, -1, 0, 1};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    d.push_back({x - 1, y - 1});
    count[x - 1][y - 1] = 1;
    visited[x - 1][y - 1] = 1;
    int found = 0;

    while (d.empty() != 1)
    {
        int i1 = d.front().first, j1 = d.front().second;
        if (i1 == 0 || j1 == 0 || i1 == (N - 1) || j1 == (M - 1))
        {
            cout << count[i1][j1] << endl;
            found = 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int i2 = i1 + a[i];
            int j2 = j1 + b[i];
            if (0 <= i2 && i2 < N && 0 <= j2 && j2 < M)
            {
                if (A[i2][j2] == 0 && visited[i2][j2] == 0)
                {
                    count[i2][j2] = count[i1][j1] + 1;
                    d.push_back({i2, j2});
                    visited[i2][j2] = 1;
                }
            }
        }
        d.pop_front();
    }
    if (!found) cout << -1 << endl;
    return 0;
}