#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int n;
vector<pair<int, int>> J(MAX);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int deadline, profit;
        cin >> deadline >> profit;
        J[i] = make_pair(deadline, profit);
    }

    sort(J.begin(), J.begin() + n, [&](pair<int, int> &a, pair<int, int> &b){
        return (a.second > b.second);
    });
    int profit = 0;
    vector<int> slot(MAX, 0);
    for (int job = 0; job < n; job++)
    {
        for (int t = J[job].first; t >= 1; t --)
        {
            if (slot[t] == 0)
            {
                slot[t] = 1;
                profit += J[job].second;
                break;
            }
        }
    }
    cout << profit << "\n";
    return 0;
}