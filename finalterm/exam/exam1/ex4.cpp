#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, sum = 0;
    vector<int> f;
    cin >> n >> k;
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int i1;
        cin >> i1 >> f[i];
        sum += f[i];
    }
    int avg = sum / k;
    vector<int> f1;
    int start = 1;
    int i;
    while (k > 0)
    {
        int a = 0;
        if (k == 1)
        {
            for (i = start; i <= (n - k + 1); i++)
            {
                a += f[i];
            }
            f1.push_back(a);
            k--;
            continue;
        }
        for (i = start; i <= (n - k + 1); i++)
        {
            if (i != start && a + f[i] > avg) 
            {
                break;
            }
            a += f[i];
        }
        start = i;
        f1.push_back(a);
        k--;
    }
    for (auto i : f1) cout << i << "\n";
    cout << *max_element(f1.begin(), f1.end()) - *min_element(f1.begin(), f1.end()) << "\n";
    return 0;
}