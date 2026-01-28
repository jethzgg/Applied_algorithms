#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, X;
vector<int> d;
vector<vector<int>> amount;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> X;
    d.resize(n, 0);

    for (int i = 0; i < n; i++) cin >> d[i];

    amount.resize(n, vector<int>(X + 1, INT_MAX - 1));
    for (int i = 0; i < n; i++) amount[i][0] = 0;
    //base case i = 0, Money-exchange
    //knapsack inf
    for (int j = 1; j <= X; j++)
    {
        if ((j / d[0]) * d[0] == j)
        {
            amount[0][j] = j / d[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            amount[i][j] = amount[i - 1][j];
            if (j >= d[i])
            {
                amount[i][j] = min(amount[i][j], 
                    amount[i][j - d[i]] + 1);
            }
        }
    }
    cout << (amount[n - 1][X] != INT_MAX - 1 ? 
        amount[n - 1][X] : -1) << "\n";
    return 0;
}
