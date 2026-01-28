#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int n;
vector<int> times(MAX);
int T = 0, timepoint = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    sort(times.begin(), times.begin() + n, 
    [](int a, int b){
        return a > b;
    }); //Job planning (Greedy)
    for (int i = 0; i < n; i++)
    {
        T = max(T, timepoint + times[i]);
        timepoint++;
    }
    cout << T << "\n";
    return 0;
}
