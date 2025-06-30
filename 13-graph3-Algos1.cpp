#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

// Dijkstra's algorithm for a weighted undirected graph (DAG or general graph)
// Finds shortest paths from a source vertex to all other vertices

void DIJSKTRA(int V, vector<vector<pair<int, int>>> &adj, int src) 
{
    // Initialize distances to all vertices as infinity
    vector<int> dist(V, numeric_limits<int>::max());

    // Min-heap priority queue to select the vertex with the smallest distance (dist., vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    dist[src] = 0; // Distance to source is 0
    pq.push({0, src}); // Push source vertex into the queue

    while (!pq.empty()) 
    {
        int u = pq.top().second; // Get vertex with smallest distance
        int d = pq.top().first;  // Current distance to u
        pq.pop();

        if (d > dist[u]) 
            continue; //to remove unecessary steps nd skip it

        // Traverse all adjacent vertices of u
        for (auto &neighbour : adj[u]) 
        {
            int v = neighbour.first;      // Adjacent vertex
            int weight = neighbour.second;// neighbour weight

            // If a shorter path to v is found
            
            if (dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight; // Update distance
                pq.push({dist[v], v});      // Push updated distance to queue
            }
        }
    }

    // Print the shortest distances from source to all vertices
    cout << "***********************************" << "\n" << "Dijsktra Algortihm Result" << endl;;
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t" << dist[i] << "\n";
    cout << "***********************************" << endl;
}

// Prim's Algorithm: Finds Minimum Spanning Tree (MST) of a graph
void PRIM(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> key(V, numeric_limits<int>::max()); // key[i] = minimum weight to connect node i to MST
    vector<int> parent(V, -1);                      // parent[i] = the node through which i is connected to MST
    vector<bool> inMST(V, false);                   // inMST[i] = true if i is already included in MST

    // Min-heap priority queue: stores pairs (key, vertex)
    // Removed min-heap usage for this version

    key[src] = 0;            // Start from source node: set key to 0

    for (int count = 0; count < V - 1; ++count)
    {
        int u = -1;
        int minKey = numeric_limits<int>::max();

        // Find the vertex with the minimum key value not yet included in MST
        for (int v = 0; v < V; ++v)
        {
            if (!inMST[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) break; // Graph might be disconnected

        inMST[u] = true; // Mark this node as included

        // Traverse all adjacent nodes of u
        for (auto &neighbour : adj[u])
        {
            int v = neighbour.first;       // Adjacent vertex
            int weight = neighbour.second; // Weight of edge u-v

            // If v is not in MST and edge u-v has smaller weight than previously known key
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;    // Update key: smaller edge found
                parent[v] = u;      // Set u as parent of v in MST
            }
        }
    }

    cout << "***********************************" << "\n" << "Prim's Algorithm Result (MST)" << endl;
    cout << "Edge\tWeight\n";
    int totalWeight = 0;
    for (int i = 0; i < V; ++i)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
            totalWeight += key[i];
        }
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
    cout << "***********************************" << endl;
}


int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Adjacency list: adj[u] contains pairs (v, w) for edge u->v with weight w
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w) where u->v with weight w:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    DIJSKTRA(V, adj, src);

    PRIM(V, adj, src);

    return 0;
}

// DIJKSTRA has aa limitation it doesnt work for negative weights...use bellman ford algo for that

/*
🧠 Time and Space Complexity Analysis
-----------------------------------------------

✅ Dijkstra’s Algorithm (Using Min-Heap):
----------------------------------------
Time Complexity:    O((V + E) * log V)  
Space Complexity:   O(V + E)

- **Used to find the shortest path from a source node to all other nodes in a weighted graph (non-negative weights).**
- Uses a priority queue (min-heap) to efficiently get the next node with the shortest distance.
- Suitable for sparse and large graphs.
- Adjacency list stores all V vertices and E edges.

✅ Prim’s Algorithm:
---------------------------------------
Time Complexity:    O(V²)  
Space Complexity:   O(V + E)

- **Used to find the Minimum Spanning Tree (MST) by growing the tree one vertex at a time from an arbitrary starting point.**
- **MST (Minimum Spanning Tree): A subset of edges that connects all vertices of the graph with the minimum total edge weight and no cycles.**
- Uses linear scan to select the next minimum-weight edge.
- No heap used.
- Works well for small or dense graphs.
- Still uses adjacency list for graph representation.

✅ Kruskal’s Algorithm:
---------------------------------------
Refer other resources for this****

- **Used to construct the Minimum Spanning Tree (MST) by sorting all edges and picking the smallest ones that don't form a cycle.**
- A greedy algorithm that builds the MST by sorting all edges and picking the smallest ones first (without forming cycles).
- Uses Disjoint Set Union (DSU) / Union-Find for cycle detection.
- Works best when edges are already sorted or the graph is edge-heavy.

Note:  
- V = number of vertices  
- E = number of edges  
----------------------------------------------- */

