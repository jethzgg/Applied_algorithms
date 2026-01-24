#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<vector<int>> sets;
    cin >> n;
    sets.resize(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> sets[i][0] >> sets[i][1];
    }
    sort(sets.begin(), sets.end(), [](vector<int>& a, vector<int>& b){
        return (a[1] == b[1]) ? (a[0] < b[0]) : (a[1] < b[1]);
    }); 
    int end = sets[0][1];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (sets[i][0] > end)
        {
            cnt++;
            end = sets[i][1];
        }
    }
    cout << cnt << "\n";
    return 0;
}