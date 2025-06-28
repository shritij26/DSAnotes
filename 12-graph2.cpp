#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



// Topological sort in directed acyclic graph is a ordering in
// which u always come v if there is edge directing u to v (90)

// TOPO SORT USING DFS

void topologicalsort(vector<vector<int>> &edges, int v, int e) // e is no. of edges and v vertex
{
    // creating adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    // call dfs topological sort util function for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSortUsingDFS(i, visited, s, adj);
    }
    // topo sort is stored in the stack s
}
void topoSortUsingDFS(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topoSortUsingDFS(neighbour, visited, s, adj);
    }
    s.push(node);
}




// TOPO SORT USING BFS [KAHN ALGORITHM]




vector<int> toposortUsingBFS(vector<vector<int>> &edges, int v, int e)
{
    // creating adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // preparing a array which stores indegree of each respective node
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
            indegree[j]++;
        ;
    }

    // push the the node with 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    //do bfs
    vector<int> ans;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}