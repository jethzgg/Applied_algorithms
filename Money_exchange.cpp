#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int X;
    cin >> X;

    vector<int> a = {1, 5, 10, 25, 100};
    vector<int> result(5);

    for (int i = 4; i >= 0; i--)
    {
        if (X >= a[i])
        {
            result[i] = X / a[i];
            X -= (X / a[i]) * a[i];
        }
    }

    if (X == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << result[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}