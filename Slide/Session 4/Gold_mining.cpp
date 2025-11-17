#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 1000000

using namespace std;

int n, L1, L2, Max = 0;
vector<int> a(MAX);
vector<int> p(MAX);
deque<int> maximum;  

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = a[i];
    }

    for (int i = 1; i < n; i++)
    {   
        while (!maximum.empty() && (maximum.front() < (i - L2)))
        {
            maximum.pop_front();
        }
        if ((i - L1) >= 0)
        {
            while (!maximum.empty() && (p[maximum.back()] <= p[i - L1]))
            {
                maximum.pop_back();
            }
            maximum.push_back(i - L1);
        }
        if (!maximum.empty() && (maximum.front() <= (i - L1)))
        {
            p[i] = a[i] + p[maximum.front()];
        }
    }

    cout << *max_element(p.begin(), p.end()) << "\n";

    return 0;
}