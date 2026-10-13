#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Breadth First Search
void bfs(int start, const vector<vector<int> >& adj)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// Depth First Search
void dfs(int u, const vector<vector<int> >& adj,
         vector<bool>& visited)
{
    visited[u] = true;

    cout << u << " ";

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if (!visited[v])
        {
            dfs(v, adj, visited);
        }
    }
}

int main()
{
    // Graph represented using adjacency list
    vector<vector<int> > adj;

    adj.push_back(vector<int>());
    adj.push_back(vector<int>());
    adj.push_back(vector<int>());
    adj.push_back(vector<int>());
    adj.push_back(vector<int>());

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);

    adj[4].push_back(1);
    adj[4].push_back(2);

    // BFS
    cout << "BFS: ";
    bfs(0, adj);

    // DFS
    vector<bool> visited(adj.size(), false);

    cout << "\nDFS: ";
    dfs(0, adj, visited);

    return 0;
}
