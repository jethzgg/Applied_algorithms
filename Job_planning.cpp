#include <iostream>
#include <vector>
#include <algorithm>
#define ii pair<int, int>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ii> j(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        j[i] = make_pair(a, b);
    }
    sort(j.begin(), j.end(), [](ii a, ii b){
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return (a.second > b.second);
        }
        return false;
    });

    int profits = 0;
    int t = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (t < j[i].first)
        {
            t++;
            profits += j[i].second;
        }
    }

    cout << profits << "\n";
    return 0;
}