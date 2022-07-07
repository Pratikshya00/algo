#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int src, dest;
};
class Graph
{
public:

    vector<vector<int>> adjList;
     Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

void DFS(Graph const &graph, int v, vector<bool>
    &discovered, vector<int> &departure, int &time)
{
    discovered[v] = true;
     time++;

    for (int u: graph.adjList[v])
    {

        if (!discovered[u]) {
            DFS(graph, u, discovered, departure, time);
        }
    }
     departure[time] = v;
    time++;
}
 void doTopologicalSort(Graph const &graph, int n)
{
    vector<int> departure(2*n, -1);

    vector<bool> discovered(n);
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (!discovered[i]) {
            DFS(graph, i, discovered, departure, time);
        }
    }
     for (int i = 2*n - 1; i >= 0; i--)
    {
        if (departure[i] != -1) {
            cout << departure[i] << " ";
        }
    }
}
 int main()
{
       vector<Edge> edges =
    {
        {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}
    };

    int n = 8;
     Graph graph(edges, n);
    doTopologicalSort(graph, n);
    return 0;
}
