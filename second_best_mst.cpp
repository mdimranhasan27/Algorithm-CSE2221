#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;
vector<int> mstEdges;

struct Edge {
    int u, v, w;
};

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

bool cmp(Edge &a, Edge &b) {
    return a.w < b.w;
}

int kruskal(int V, vector<Edge> &edges, int skip = -1) {

    parent.assign(V, 0);
    sz.assign(V, 1);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    mstEdges.clear();

    int cost = 0;
    int edgeCount = 0;

    for (int i = 0; i < edges.size(); i++) {

        if (i == skip)
            continue;

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            unite(u, v);

            cost += w;
            edgeCount++;

            mstEdges.push_back(i);
        }
    }

    // Graph is disconnected.
    if (edgeCount != V - 1)
        return INT_MAX;

    return cost;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
             >> edges[i].v
             >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    // Find the first MST.
    int mstCost = kruskal(V, edges);

    vector<int> firstMST = mstEdges;

    int secondBest = INT_MAX;

    // Remove one MST edge at a time.
    for (int idx : firstMST) {
        int cost = kruskal(V, edges, idx);

        secondBest = min(secondBest, cost);
    }

    cout << "MST Cost = " << mstCost << '\n';

    if (secondBest == INT_MAX)
        cout << "No Second Best MST exists\n";
    else
        cout << "Second Best MST = " << secondBest << '\n';

    return 0;
}