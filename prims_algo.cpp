#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Returns total weight of the Minimum Spanning Tree
int spanningTree(int V, vector<vector<pair<int, int>>> &adj)
{
    // Min-heap storing {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Marks vertices already taken in MST
    vector<bool> visited(V, false);

    int res = 0;

    // Start from node 0 with weight 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        // Skip if the vertex is already in the MST
        if (visited[u])
            continue;

        // Include vertex in MST
        res += wt;
        visited[u] = true;

        // ONLY loop through neighbors of the current vertex 'u'
        // v.first = neighbor node, v.second = edge weight
        for (auto &v : adj[u])
        {
            int neighbor = v.first;
            int edgeWeight = v.second;

            if (!visited[neighbor])
            {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    return res;
}

int main()
{
    int V, E;
    cin >> V >> E;

    // Array of vectors: adj[u] will store pairs of {neighbor, weight}
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; 

        // Graph must be undirected: add both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Total MST Weight: " << spanningTree(V, adj) << endl;

    return 0;
}
