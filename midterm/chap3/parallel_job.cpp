#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> times(MAX);
    int T = 0, timepoint = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    sort(times.begin(), times.begin() + n, [](int a, int b){
        return a > b;
    });
    for (int i = 0; i < n; i++)
    {
        T = max(T, timepoint + times[i]);
        timepoint++;
    }
    cout << T << "\n";
    return 0;
}