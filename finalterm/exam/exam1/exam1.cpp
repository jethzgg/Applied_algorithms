#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> A;
vector<int> used, prefix;
int LB, UB, cnt = 0, sum = 0;

void backtrack(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        used[k] = i;
        sum += i * A[k];
        if (k == (n - 1))
        {
            if (LB <= sum && sum <= UB)
            {
                cnt++;
            }
        } 
        else
        {
            int g = sum + prefix[n - 1] - prefix[k];
            if (sum <= UB) backtrack(k + 1);
        }
        sum -= i * A[k];
    }
}

int main()
{
    cin >> n;
    A.resize(n, 0);
    used.resize(n, 0);
    prefix.resize(n , 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i == 0) prefix[i] = A[i];
        else prefix[i] = A[i] + prefix[i - 1];
    }
    cin >> LB >> UB;
    backtrack(0);
    cout << cnt << "\n";
    return 0;
}