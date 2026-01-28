#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int s, e;

int calWeight()
{
    int num = e - s + 1;
    return ((s + e) * num) / 2;
}

int main()
{
    int n;
    vector<int> a, b, res;
    deque<int> window;
    cin >> n;
    a.resize(n, 0);
    b.resize(n, 0);
    res.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    s = a[0];
    e = b[0];
    res[0] = calWeight();
    for (int i = 1; i < n; i++)
    {
        s = a[i];
        e = b[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] > b[i] || a[i] > b[j])
            {
                res[i] = max(res[i], res[j] + calWeight());
            }
        }
    }
    cout << *max_element(res.begin(), res.end()) << "\n";
    return 0;
}