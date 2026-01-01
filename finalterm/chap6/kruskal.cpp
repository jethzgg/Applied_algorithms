#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    int totalWeight = 0;
    for (const auto& edge : edges) {
        if (find(edge.u, parent) != find(edge.v, parent)) {
            unionSets(edge.u, edge.v, parent, rank);
            totalWeight += edge.w;
        }
    }
    
    cout << totalWeight << endl;
    return 0;
}
