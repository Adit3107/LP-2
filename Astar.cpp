#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Node {

    char vertex;
    int cost;

    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {

    map<char, vector<pair<char, int>>> graph;

    graph['A'] = {{'B', 1}, {'C', 3}};
    graph['B'] = {{'D', 3}, {'E', 6}};
    graph['C'] = {{'F', 5}};
    graph['D'] = {{'G', 2}};
    graph['E'] = {{'G', 1}};
    graph['F'] = {{'G', 2}};

    map<char, int> h;

    h['A'] = 7;
    h['B'] = 6;
    h['C'] = 4;
    h['D'] = 2;
    h['E'] = 1;
    h['F'] = 2;
    h['G'] = 0;

    priority_queue<Node> pq;

    pq.push({'A', h['A']});

    map<char, int> gCost;
    map<char, char> parent;

    gCost['A'] = 0;
    parent['A'] = '-';

    char goal = 'G';

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        char u = current.vertex;

        if (u == goal)
            break;

        for (auto neighbor : graph[u]) {

            char v = neighbor.first;
            int edgeCost = neighbor.second;

            int newCost = gCost[u] + edgeCost;

            if (!gCost.count(v) || newCost < gCost[v]) {

                gCost[v] = newCost;

                int fCost = newCost + h[v];

                pq.push({v, fCost});

                parent[v] = u;
            }
        }
    }

    vector<char> path;

    char current = goal;

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