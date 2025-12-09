#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 23

using namespace std;

int n, k, cost = 0, MIN = INT_MAX;
vector<vector<int>> a(MAX, vector<int>(MAX, 0));

int check(int i)
{
    return 0;
}

void backtrack(int x)
{
    for (int i = 1; i <= (2 * n); i++)
    {
        if (check(i))
        {
            
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i <= (2 * n); i++)
    {
        for (int j = 0; j <= (2 * n); j++)
        {
            cin >> a[i][j];
        }
    }
    return 0;
}