#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> a;

int maxCrossingSum(int left, int mid, int right)
{
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; i--)
    {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}

int maxSum(int left, int right)
{
    if (left == right)
    {
        return a[left];
    }
    int mid = left + (right - left) / 2;
    return max(max(maxSum(left, mid), 
                    maxSum(mid + 1, right)), 
                    maxCrossingSum(left, mid, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxSum(0, n - 1) << "\n";
    return 0;
}