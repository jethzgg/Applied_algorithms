#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> X;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    X.resize(n, make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        X[i] = make_pair(a, b);
    }
    sort(X.begin(), X.end(), [&](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    });
    pair<int, int> last = X[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (X[i].first > last.second)
        {
            last = X[i];
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}