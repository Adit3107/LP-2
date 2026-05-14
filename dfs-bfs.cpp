#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited);
            }
        }
    }

    void bfs(int src, int dest)
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == dest)
                break;

            for (int nbr : adj[node])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        if (!visited[dest])
        {
            cout << "No path exists between " << src << " and " << dest << endl;
            return;
        }

        vector<int> path;

        for (int v = dest; v != -1; v = parent[v])
        {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        cout << "Shortest Path (Packet Routing): ";

        for (int node : path)
        {
            cout << node << " ";
        }

        cout << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(6, false);

    cout << "DFS: ";
    g.dfs(src, visited);

    cout << "\nBFS Shortest Path: ";
    g.bfs(src, dest);

    return 0;
}

/*
Sample Input:
0 9

Explanation:
0 = Source node
9 = Destination node

Expected Output:
DFS: 0 1 3 7 4 2 5 8 9 6
BFS Shortest Path: Shortest Path (Packet Routing): 0 2 6 9
*/