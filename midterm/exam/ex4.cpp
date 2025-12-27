#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M, N;
    cin >> M >> N;
    vector<vector<int>> tube(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tube[i][j];
        }
    }
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++)
    {
        dp[i][0] = tube[i][0];
    }
    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            int f = (i - 1 < 0) ? (M - 1) : (i - 1);
            int s = i;
            int t = (i + 1 >= M) ? (0) : (i + 1);
            dp[i][j] = max(dp[f][j - 1], 
                max(dp[s][j - 1], 
                    dp[t][j - 1])) + tube[i][j];
        }
    }
    int MAX = 0;
    for (int i = 0; i < M; i++)
    {
        MAX = max(MAX, dp[i][N - 1]);
    }
    cout << MAX << "\n";
    return 0;
}