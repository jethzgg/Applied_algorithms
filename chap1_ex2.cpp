#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int a, b, c;
    double cost = 0;
    while (pq.size() > 1)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = a + b;
        pq.push(c);
        cost += 0.05 * c; 
    }
    cout << static_cast<int>(cost) << endl;
    return 0;
}