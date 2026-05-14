// A* Algorithm Implementation in C++
// A* algorithm is a popular pathfinding and graph traversal algorithm used in various applications, such as navigation systems, game development, and artificial intelligence. It combines the advantages of Dijkstra's algorithm and greedy best-first search to efficiently find the shortest path from a start node to a goal node in a weighted graph.

//working- The A* algorithm uses a priority queue to explore nodes based on their estimated total cost (g(n) + h(n)), where g(n) is the actual cost from the start node to the current node, and h(n) is the heuristic estimate of the cost from the current node to the goal node. The algorithm continues to explore nodes until it reaches the goal node, at which point it reconstructs the path taken and calculates the total cost.

//example - In this implementation, we define a graph using an adjacency list and a heuristic function that estimates the cost to reach the goal node. The algorithm starts from the initial node 'A' and explores neighboring nodes while keeping track of the costs and parent nodes to reconstruct the path once the goal is reached. Finally, it prints the shortest path and its total cost.

#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Structure for graph node
struct Node { // Node structure to represent each vertex in the graph for A* algorithm
    char vertex; // Character representing the vertex (e.g., 'A', 'B', etc.)
    int cost; // Cost associated with the node (g(n) + h(n)) used for priority in the A* algorithm

    // For priority queue
    bool operator<(const Node& other) const { // Overloading the less-than operator to compare nodes based on their cost for priority queue ordering
        return cost > other.cost; // Return true if this node's cost is greater than the other node's cost (for min-heap behavior in priority queue)
    }
};

int main() {

    // Graph representation
    map<char, vector<pair<char, int>>> graph; // Graph represented as an adjacency list using a map, where each key is a vertex and the value is a vector of pairs (neighbor vertex and edge cost)

    graph['A'] = {{'B', 1}, {'C', 3}}; // Define edges and their costs for vertex 'A' (connected to 'B' with cost 1 and 'C' with cost 3)
    graph['B'] = {{'D', 3}, {'E', 6}};
    graph['C'] = {{'F', 5}};
    graph['D'] = {{'G', 2}};
    graph['E'] = {{'G', 1}};
    graph['F'] = {{'G', 2}};

    // Heuristic values
    map<char, int> h;  // Heuristic values representing the estimated cost from each vertex to the goal vertex 'G'

    h['A'] = 7; // Heuristic value for vertex 'A' (estimated cost to reach 'G')
    h['B'] = 6;
    h['C'] = 4;
    h['D'] = 2;
    h['E'] = 1;
    h['F'] = 2;
    h['G'] = 0;

    priority_queue<Node> pq;   // Priority queue to store nodes based on their estimated total cost (g(n) + h(n)) for the A* algorithm

    // Start node
    pq.push({'A', h['A']}); // Push the start node 'A' into the priority queue with its heuristic cost as the initial cost (g(n) = 0, so f(n) = h(n))

    map<char, int> gCost; // Map to store the actual cost from the start node to each vertex (g(n) values) for the A* algorithm
    map<char, char> parent; // Map to store the parent of each vertex for path reconstruction once the goal is reached in the A* algorithm

    gCost['A'] = 0; // Cost from start node 'A' to itself is 0 (g(n) = 0 for the start node)
    parent['A'] = '-'; // Parent of the start node is set to '-' to indicate that it has no parent (used for path reconstruction)

    char goal = 'G'; // Define the goal vertex 'G' that we want to reach using the A* algorithm

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        char u = current.vertex; // Get the vertex with the lowest estimated total cost (f(n)) from the priority queue

        // Goal reached
        if (u == goal)
            break;

        // Visit neighbors
        for (auto neighbor : graph[u]) { // Iterate through the neighbors of the current vertex 'u' in the graph, where each neighbor is represented as a pair (neighbor vertex and edge cost)

            char v = neighbor.first; // Get the neighboring vertex 'v' from the pair (neighbor.first) for the current vertex 'u'
            int edgeCost = neighbor.second; // Get the cost of the edge from vertex 'u' to its neighbor 'v' from the pair (neighbor.second) for the current vertex 'u'

            int newCost = gCost[u] + edgeCost; // Calculate the new cost to reach neighbor 'v' from the start node through vertex 'u' by adding the actual cost to reach 'u' (gCost[u]) and the cost of the edge from 'u' to 'v' (edgeCost)

            if (!gCost.count(v) || newCost < gCost[v]) { // 

                gCost[v] = newCost;

                int fCost = newCost + h[v];

                pq.push({v, fCost});

                parent[v] = u;
            }
        }
    }

    // Print path
    vector<char> path;

    char current = goal; // Start from the goal vertex and backtrack to the start vertex using the parent map to reconstruct the path taken by the A* algorithm

    while (current != '-') {
        path.push_back(current);
        current = parent[current];
    }

    cout << "Shortest Path: ";

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];

        if (i != 0)
            cout << " -> ";
    }

    cout << endl;

    cout << "Total Cost: " << gCost[goal];

    return 0;
}