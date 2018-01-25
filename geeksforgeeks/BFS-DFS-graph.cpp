
#include <vector>
#include <queue>
#include <iostream>

class Graph{
  public:
    Graph(const int V):vertex(V)
    {
        adjList.resize(V);
    }
    void addEdge(const int src, const int des)
    {
        adjList[src].push_back(des);
    }
    void BFS(const int src);
    void DFS(const int src);
  private:
    int vertex;
    std::vector<std::vector<int>> adjList;
    void DFSUtil(std::vector<bool>&, int);

};



void Graph::BFS(const int src)
{
    std::queue<int> queue;
    queue.push(src);

    std::vector<bool> visited(vertex, false);

    while(!queue.empty())
    {
        int src = queue.front();
        queue.pop();
        visited[src] = true;

        std::cout << src << "\n";

        for(const auto& des: adjList[src])
        {
            if(!visited[des])
            {
                queue.push(des);
            }
        }
    }
}

void Graph::DFSUtil(std::vector<bool>& visited, int src)
{
    visited[src] = true;
    std::cout << src << "\n";
    for(const auto& des: adjList[src])
    {
        if(!visited[des])
        {
            DFSUtil(visited, des);
        }
    }
}
void Graph::DFS(const int src)
{
    std::vector<bool> visited (vertex, false);
    visited[src] = true;
    std::cout << src << "\n";
    for(const auto& des: adjList[src])
    {
        if(!visited[des])
        {
            DFSUtil(visited, des);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);

    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    std::cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);

}
