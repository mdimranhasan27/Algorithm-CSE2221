#include<bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int kruskal(int V, vector<vector<int>>& edges) {

    parent.resize(V);
    sz.resize(V, 1);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    int cost = 0;

    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (find(u) != find(v)) {
            unite(u, v);
            cost += w;
        }
    }

    return cost;
}

int main() {
    int V, E;
    cin >> V >> E; // Read number of vertices and edges

    // Declare the 2D vector
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Read source, destination, and weight
        
        // Push them as a localized vector group {u, v, w}
        edges.push_back({u, v, w});
    }

    // Now 'edges' is in the exact format: {{0,1,10}, {1,3,15}, ...}
    cout << kruskal(V, edges) << "\n";

    return 0;
}
