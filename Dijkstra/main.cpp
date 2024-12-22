#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

/// @brief 
/// @param sourceNode the starting node
/// @param graph an adjacency list representing the graph. each row index represents the node
///             and the vector in that row represents the nodes that are connected to the row index node
///             the pair<int, int> reprsents {distance/weight, neighbor-vertex}
/// @return 
std::vector<int> Dijkstra(const int& sourceNode, std::vector<std::vector<std::pair<int, int>>>& graph)
{
    const int NODES = graph.size();
    std::vector<int> distances(NODES, INT_MAX);
    distances[sourceNode] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<>> minHeap;
    minHeap.push({ 0, sourceNode });

    while (!minHeap.empty())
    {
        auto [currentDistance, currentNode] = minHeap.top();
        minHeap.pop();

        if (currentDistance > distances[currentNode])
        {
            continue;
        }

        for (const auto& [weight, neighbor] : graph[currentNode])
        {
            int newDistance = currentDistance + weight;
            if (newDistance < distances[neighbor])
            {
                distances[neighbor] = newDistance;
                minHeap.push({ newDistance, neighbor });
            }
        }
    }

    return distances;
}

int main()
{
    // Example Graph (nodes 0 to 3)
    // 0 --1--> 1
    // 0 --4--> 2
    // 1 --2--> 2
    // 1 --6--> 3
    // 2 --3--> 3

    int n = 4; // Number of nodes
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Add edges
    graph[0].push_back({ 1, 1 });
    graph[0].push_back({ 2, 4 });
    graph[1].push_back({ 2, 2 });
    graph[1].push_back({ 3, 6 });
    graph[2].push_back({ 3, 3 });

    // Run Dijkstra's Algorithm
    int source = 0;
    std::vector<int> shortest_distances = Dijkstra(source, graph);

    // Output the results
    std::cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Node " << i << ": ";
        if (shortest_distances[i] == std::numeric_limits<int>::max())
        {
            std::cout << "Infinity\n";
        }
        else
        {
            std::cout << shortest_distances[i] << "\n";
        }
    }

    return 0;
}
