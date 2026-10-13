#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    const int V = 5;

    // Adjacency matrix
    int g[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> used(V, false);

    // Start from vertex 0
    key[0] = 0;

    // Prim's Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        // Find vertex with minimum key value
        for (int v = 0; v < V; v++)
        {
            if (!used[v] && (u == -1 || key[v] < key[u]))
            {
                u = v;
            }
        }

        used[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (g[u][v] && !used[v] && g[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    // Print MST and calculate total cost
    int cost = 0;

    cout << "Edges in Minimum Spanning Tree:" << endl;

    for (int v = 1; v < V; v++)
    {
        cout << parent[v] << " - " << v
             << " : " << g[v][parent[v]] << endl;

        cost += g[v][parent[v]];
    }

    cout << "MST cost = " << cost << endl;

    return 0;
}
