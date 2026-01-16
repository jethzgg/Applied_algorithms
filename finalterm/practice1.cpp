#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, M, N, T, D;
vector<int> courses, cs, d, xd, xss, xs;
void backtrack(int course)
{
    for (int i = 1; i <= M; i++)
    {
        if (courses[i] == course)
        {
            int Class = courses[i];
            for (int j = 1; j <= N; j++)
            {
                if (cs[j] == Class)
                {
                    
                }
            }
        }
    }
}

int main()
{
    cin >> K >> M >> N >> T >> D;
    courses.resize(M + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        courses[a] = b;
    }
    cs.resize(N + 1, 0);
    d.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cs[a] = b;
        d[a] = c;
    }
    xd.resize(N + 1, 0);
    xs.resize(N + 1, 0);
    xss.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        xd[a] = b;
        xss[a] = c;
        xs[a] = d;
    }
    return 0;
}