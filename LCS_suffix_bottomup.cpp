#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
string s1, s2;

int main()
{
    cin >> s1;
    cin >> s2;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[0][0] << "\n";
    return 0;
}