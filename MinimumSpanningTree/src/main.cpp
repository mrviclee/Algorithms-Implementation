#include "Graph.hpp"
#include "Prim.hpp"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.AddEdge(0, 1, 2);
    graph.AddEdge(0, 3, 6);
    graph.AddEdge(1, 2, 3);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 5);
    graph.AddEdge(2, 4, 7);

    graph.ExportToDot("graph.dot");

    // Compute MST using Prim's Algorithm
    MSTResults result = Prim(graph);

    result.ExportToDot("mst.dot");

    // Print the result
    std::cout << "Total Weight of MST: " << result.totalWeight << "\n";
    std::cout << "Edges in MST:\n";
    for (const Edge& edge : result.mstEdges) {
        std::cout << edge.source << " -- " << edge.destination << " (Weight: " << edge.weight << ")\n";
    }

    return 0;
}
