#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
string s1, s2;

int lcs(int i, int j)
{
    if (i == s1.size() || j == s2.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        dp[i][j] = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
    }
    return dp[i][j];
} 

int main()
{
    cin >> s1;
    cin >> s2;
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << lcs(0, 0) << "\n";
    return 0;
}