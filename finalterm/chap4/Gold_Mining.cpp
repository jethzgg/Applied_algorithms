#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, L1, L2;
    vector<int> a, res;

    cin >> n >> L1 >> L2;

    a.resize(n, 0);
    res.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && 
            q.front() < (i - L2))
        {
            q.pop_front();
        }
        if (i - L1 >= 0)
        {
            while (!q.empty() && 
                res[q.back()] <= res[(i - L1)])
            {
                q.pop_back();
            }
            q.push_back(i - L1);
        }
        if (q.empty()) res[i] = a[i];
        else res[i] = res[q.front()] + a[i];
    }
    cout << *max_element(res.begin(), 
            res.end()) << "\n";
    return 0;
}