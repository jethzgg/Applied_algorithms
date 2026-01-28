#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl  '\n'


using ll = long long;
using ii = pair<int, int>;
int n, K, Q;
int d[1005], load[1005];
int c[1005][1005], cmin = INT_MAX;
int y[1005], x[1005], visited[1005];
int nbR, segments;
int f, fopt = INT_MAX;
bool check(int custom, int bus) {
  if (custom == 0) return true;
  if (visited[custom]) return false;
  if (load[bus] + d[custom] > Q) return false;
  return true;
}
void TryX(int u, int k) {
  if (u == 0) {
    if (k < K) TryX(y[k + 1], k + 1);
    return ;
  }
  for (int i = 0; i <= n; ++i) {
    if (check(i, k)) {
      x[u] = i;
      visited[i] = true;
      load[k] += d[i];
      f += c[u][i];
      ++segments;
      if (i == 0) {
        if (n + nbR == segments) fopt = min(fopt, f);
        else if (f + (n + nbR - segments) * cmin < fopt) 
            TryX(y[k + 1], k + 1);
      }
      else {
        if (f + (n + nbR -segments) * cmin < fopt) 
            TryX(i, k);
      }
      visited[i] = false;
      load[k] -= d[i];
      f -= c[u][i];
      --segments;
    }
  }
}
void TryY(int k) {
  int st = 0;
  if (y[k - 1]) st = y[k - 1] + 1;
  for (int i = st; i <= n; ++i) {
    if (check(i, k)) {
      y[k] = i;
      visited[i] = true;
      if (i) ++segments;
      load[k] += d[i];
      f += c[0][y[k]];
      if (k == K) {
        nbR = segments;
        TryX(y[1], 1);
      }
      else TryY(k + 1);
      visited[i] = false;
      if (i) --segments;
      load[k] -= d[i];
      f -= c[0][y[k]];
    }
  }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        cin >> c[i][j];
        if (c[i][j]) cmin = min(cmin, c[i][j]);
      }
    }
    TryY(1);
    cout << fopt;
    return 0;
}
