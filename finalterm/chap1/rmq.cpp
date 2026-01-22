#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> a;
int treeSize;
vector<int> segment_tree;

void buildTree(int low, int high, int pos)
{
    if (low == high)
    {
        segment_tree[pos] = a[low];
        return;
    }
    int mid = low + (high - low) / 2;
    buildTree(low, mid, 2 * pos + 1);
    buildTree(mid + 1, high, 2 * pos + 2);
    segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2]);
}

int rmq(int qlow, int qhigh, int low, int high, int pos)
{
    if (qlow <= low && qhigh >= high)
    {
        return segment_tree[pos];
    }
    if (qlow > high || qhigh < low)
    {
        return INT_MAX;
    }
    int mid = low + (high - low) / 2;
    return min(rmq(qlow, qhigh, low, mid, 2 * pos + 1),
                rmq(qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

int main()
{
    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    treeSize = 4 * n;
    segment_tree.resize(treeSize, INT_MAX);
    buildTree(0, n - 1, 0);
    int T, Q = 0;
    cin >> T;
    while (T--)
    {
        int i, j;
        cin >> i >> j;
        Q += rmq(i, j, 0, n - 1, 0);
    }
    cout << Q << "\n";
    return 0;
}
