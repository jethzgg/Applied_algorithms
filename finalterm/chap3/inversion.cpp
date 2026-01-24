#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int modulo = 1e9 + 7;

int n, Q = 0;
vector<int> a;

void merge(int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<int> l(leftSize, 0), r(rightSize, 0);
    for (int i = 0; i < leftSize; i++) l[i] = a[i + left];
    for (int i = 0; i < rightSize; i++) r[i] = a[i + mid + 1];
    int i = 0, j = 0;
    while (i < leftSize && j < rightSize)
    {
        if (l[i] > r[j])
        {
            a[left++] = r[j++];
            Q = (Q + leftSize - i) % modulo;
        }
        else
        {
            a[left++] = l[i++];
        }
    }
    while (i < leftSize) a[left++] = l[i++];
    while (j < rightSize) a[left++] = r[j++];
}

void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(0, n - 1);
    cout << Q << "\n";
    return 0;
}