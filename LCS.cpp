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
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << "\n";
    return 0;
}