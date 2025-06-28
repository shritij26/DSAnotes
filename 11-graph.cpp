#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class graph
{
    public:
        unordered_map<int, list<int>> adj;
        // we could also use vector<vector<int>> adj

        void addEdge(int u, int v, bool direction)
        {
            //direction 0 -> undirected
            //direction 1 -> directed

            //create an edge from u to v

            adj[u].push_back(v);

            if(direction == 0)
                adj[v].push_back(u); //for undirected graph
        }

        void printAdjList()
        {
            for(auto i:adj)
            {
                cout << i.first << " -> ";
                for(auto j:i.second)
                    cout << j << ", ";
                cout << endl;
            }
        }
};

vector<int> bfs(int start, graph &g)
{
    vector<int> bfsTraversal;
    unordered_map<int, bool> visited;
    list<int> queue;

    visited[start] = true;
    queue.push_back(start);

    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();
        bfsTraversal.push_back(node);

        for(auto neighbour : g.adj[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                queue.push_back(neighbour);
            }
        }
    }
    return bfsTraversal;
}




vector<int> dfs(int start, graph &g)
{
    vector<int> dfsTraversal;
    unordered_map<int, bool> visited;
    stack<int> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        dfsTraversal.push_back(node);

        for (auto neighbour : g.adj[node])
        {
            if (!visited[neighbour])
            {
                s.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return dfsTraversal;
}

int main()
{
    int n;
    cout << "Enter the no. nodes ";
    cin >> n;

    int m;
    cout << "Enter the no. edges ";
    cin >> m;

    graph g;
    cout << "Enter the edges with space separated nodes (u v):" << endl;
    for(int i= 0; i<m; i++)
    {
        int u,v;
        cin>> u >> v;
        g.addEdge(u,v,0); //creating undirected graph
    }
    g.printAdjList();
    // Enter the no. nodes 5
    // Enter the no. edges 6
    // Enter the edges with space separated nodes (u v):
    // 0 1
    // 1 2
    // 2 3
    // 3 1
    // 3 4
    // 0 4
    // 4 -> 3, 0, 
    // 0 -> 1, 4,
    // 1 -> 0, 2, 3,
    // 2 -> 1, 3,
    // 3 -> 2, 1, 4, we get in random order because of unordered_map
    int startNode;
    cout << "Enter starting node for BFS: ";
    cin >> startNode;

    vector<int> result = bfs(startNode, g);

    cout << "BFS Traversal starting from node " << startNode << " : ";
    for(int node : result)
        cout << node << " "; 
    cout << endl;

    vector<int> dfsResult = dfs(startNode, g);
    cout << "DFS Traversal starting from node " << startNode << " : ";
    for (int node : dfsResult)
        cout << node << " "; 
    cout << endl;
}  


                    