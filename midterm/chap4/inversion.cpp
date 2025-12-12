#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Q = 1e9 + 7;
int n, cnt = 0;
vector<int> a;

void merge(int low, int mid, int high)
{
    int size1 = mid - low + 1, size2 = high - mid;
    vector<int> left(size1);
    vector<int> right(size2);
    for (int i = 0; i < size1; i++) left[i] = a[i + low];
    for (int i = 0; i < size2; i++) right[i] = a[i + mid + 1];

    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (left[i] > right[j])
        {
            a[low] = right[j];
            cnt = (cnt + size1 - i) % Q;
            low++;
            j++;
        }
        else
        {
            a[low] = left[i];
            low++;
            i++;
        }
    }
    while (i < size1)
    {
        a[low] = left[i];
        low++;
        i++;
    }
    while (j < size2)
    {
        a[low] = right[j];
        low++;
        j++;
    }
}

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
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
    mergesort(0, n - 1);
    cout << cnt << "\n";
    return 0;
}