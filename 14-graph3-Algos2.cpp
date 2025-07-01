
/*
✅ Tarjan’s Algorithm (for Articulation Points):
-----------------------------------------------
Time Complexity:    O(V + E)  
Space Complexity:   O(V + E)

- **Used to find articulation points (or cut vertices) in an undirected graph using DFS and discovery/low times.**
- **Articulation Point: A vertex whose removal increases the number of connected components in the graph.**
- Uses DFS traversal with `disc[]` (discovery time) and `low[]` (lowest reachable ancestor).
- Root node is an articulation point **only** if it has more than one child in DFS tree.
- Non-root nodes are articulation points if `low[child] >= disc[parent]`.
- Efficient for large and sparse graphs.
- Handles disconnected graphs by running DFS from all unvisited nodes. 


✅ Kosaraju’s Algorithm (for Strongly Connected Components - SCCs):
------------------------------------------------------------------
Time Complexity:    O(V + E)  
Space Complexity:   O(V + E)

- **Used to find all Strongly Connected Components (SCCs) in a directed graph.**
- **SCC: A group of nodes where each node is reachable from every other node in that group.**
- Works in 3 steps:
  1. **First DFS** to store vertices in a stack according to their finishing time.
  2. **Transpose the graph** (reverse the direction of all edges).
  3. **Second DFS** using the stack on the transposed graph to find SCCs.
- Stack ensures we always process the "last finishing" node first.
- Transpose ensures we can reach all members of the SCC in reverse as well.
- Clean, elegant, and efficient for SCC detection in directed graphs.

---------------------------------------------------------------------------------------------------------
*/





#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
using namespace std;

// DFS function to explore the graph and identify articulation points
void dfs(int node, int parent,
         vector<int>& disc, vector<int>& low,
         unordered_map<int, bool>& vis,
         unordered_map<int, list<int>>& adj,
         vector<int>& ap, int& timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++; // Assign discovery time and low value
    int childCount = 0; // Count children of the node in DFS tree

    for (int nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);

            // After visiting child, update current node's low
            low[node] = min(low[node], low[nbr]);

            // Check if current node is an articulation point (non-root case)
            if (low[nbr] >= disc[node] && parent != -1)
                ap[node] = 1;

            childCount++;
        }
        else
        {
            // Update low value using back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Special case: if current node is root and has 2+ children
    if (parent == -1 && childCount > 1)
        ap[node] = 1;
}

// TARJAN wrapper: initializes all arrays and handles articulation point logic
void TARJAN(int n, unordered_map<int, list<int>>& adj)
{
    // Stores discovery time of each node (first time visited in DFS)
    vector<int> disc(n, -1);

    // Stores the lowest discovery time reachable from the subtree rooted at the node
    vector<int> low(n, -1);

    // Array to mark articulation points: ap[i] = 1 means node i is an articulation point
    vector<int> ap(n, 0);

    // Visited map to track which nodes have been visited
    unordered_map<int, bool> vis;

    // Timer to simulate discovery time stamps
    int timer = 0;

    // Run DFS on all unvisited nodes (handles disconnected graphs)
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    // Print all articulation points
    cout << "\nArticulation points:\n";
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (ap[i])
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";
    cout << endl;
}

// ========== KOSARAJU ALGORITHM ==========

// Step 1: DFS to fill stack with finish time order
void topoDFS(int node, unordered_map<int, list<int>>& adj, 
             unordered_map<int, bool>& vis, stack<int>& st)
{
    vis[node] = true;
    for (int nbr : adj[node])
        if (!vis[nbr])
            topoDFS(nbr, adj, vis, st);

    st.push(node);  // push after all descendants are visited (post-order)
}

// Step 2: DFS on the transposed graph to collect components
void revDFS(int node, unordered_map<int, list<int>>& transposed, 
            unordered_map<int, bool>& vis, vector<int>& component)
{
    vis[node] = true;
    component.push_back(node);
    for (int nbr : transposed[node])
        if (!vis[nbr])
            revDFS(nbr, transposed, vis, component);
}

// Kosaraju's Algorithm
void KOSARAJU(int n, unordered_map<int, list<int>>& adj)
{
    stack<int> st;
    unordered_map<int, bool> vis;

    // Step 1: Topological sort based on finish time
    for (int i = 0; i < n; ++i)
        if (!vis[i])
            topoDFS(i, adj, vis, st);

    // Step 2: Transpose the graph (reverse all edges)
    unordered_map<int, list<int>> transposed;
    for (int u = 0; u < n; ++u)
    {
        for (int v : adj[u])
        {
            transposed[v].push_back(u);
        }
    }

    // Step 3: Do DFS in order of topological sort on transposed graph
    vis.clear();
    cout << "\nStrongly Connected Components:\n";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            vector<int> component;
            revDFS(node, transposed, vis, component);

            // Print one SCC
            for (int x : component)
                cout << x << " ";
            cout << endl;
        }
    }
}


int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    unordered_map<int, list<int>> adj;
    cout << "Enter edges (u v) one per line:\n";
    /*  0 3
        3 4
        0 4
        0 1
        1 2   for tarjan */
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

        /************************************************
        For Tarjan: make this line bi-directional
        ************************************************/

        // adj[v].push_back(u);
    }

    //TARJAN(n, adj); // Run articulation point detection
    KOSARAJU(n, adj); // For SCC in directed graph
    return 0;
}
