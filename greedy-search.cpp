// Implement Greedy search algorithm for any three of the following application: 
// I   Selection Sort 
// II  Prim's Minimal Spanning Tree Algorithm 
// III Job Scheduling Problem

#include <bits/stdc++.h>
using namespace std;

/* ================= Selection Sort ================= */

void selectionSort() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++) {

        int mini = i;

        for(int j = i + 1; j < n; j++) {

            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }

        swap(arr[i], arr[mini]);
    }

    cout << "Sorted Array:\n";

    for(int x : arr) {
        cout << x << " ";
    }

    cout << endl;
}

/* ================= Prim's MST ================= */

void primsMST(int V, vector<vector<pair<int,int>>> &adj) {

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    key[0] = 0;

    pq.push({0, 0});

    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;

        for(auto &edge : adj[u]) {

            int v = edge.first;
            int wt = edge.second;

            if(!inMST[v] && wt < key[v]) {

                key[v] = wt;
                parent[v] = u;

                pq.push({key[v], v});
            }
        }
    }

    int totalWeight = 0;

    cout << "\nEdges in MST:\n";

    for(int i = 1; i < V; i++) {

        cout << parent[i]
             << " - "
             << i
             << " weight: "
             << key[i]
             << endl;

        totalWeight += key[i];
    }

    cout << "Total MST Weight: "
         << totalWeight
         << endl;
}

/* ================= Job Scheduling ================= */

struct Job {

    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {

    return a.profit > b.profit;
}

void jobScheduling() {

    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID Deadline Profit:\n";

    for(int i = 0; i < n; i++) {

        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), cmp);

    vector<int> slot(n, 0);

    vector<char> result(n);

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {

        for(int j = min(n, jobs[i].deadline) - 1;
            j >= 0;
            j--) {

            if(slot[j] == 0) {

                slot[j] = 1;

                result[j] = jobs[i].id;

                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";

    for(int i = 0; i < n; i++) {

        if(slot[i]) {

            cout << result[i] << " ";
        }
    }

    cout << "\nTotal Profit: "
         << totalProfit
         << endl;
}

/* ================= Main ================= */

int main() {

    int ch;

    cout << "\n1. Selection Sort\n";
    cout << "2. Prim's MST\n";
    cout << "3. Job Scheduling\n";

    cout << "Enter choice: ";
    cin >> ch;

    if(ch == 1) {

        selectionSort();
    }

    else if(ch == 2) {

        int V, E;

        cout << "Enter number of vertices: ";
        cin >> V;

        cout << "Enter number of edges: ";
        cin >> E;

        vector<vector<pair<int,int>>> adj(V);

        cout << "Enter edges (u v weight):\n";

        for(int i = 0; i < E; i++) {

            int u, v, w;

            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        primsMST(V, adj);
    }

    else if(ch == 3) {

        jobScheduling();
    }

    else {

        cout << "Invalid Choice\n";
    }

    return 0;
}