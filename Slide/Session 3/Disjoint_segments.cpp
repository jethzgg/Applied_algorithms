#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
#define ii pair<int, int>

using namespace std;

int n;
vector<ii> a(MAX);

int main()
{
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    sort(a.begin(), a.begin() + n, [](ii x, ii y)
    {
        return (x.second < y.second);
    });
    int cnt = 1;
    int endTime = a[0].second;
    int i = 1;
    while (i < n)
    {
        if (a[i].first > endTime)
        {
            cnt++;
            endTime = a[i].second;
        }
        i++;
    }
    cout << cnt << endl;
    return 0;
}