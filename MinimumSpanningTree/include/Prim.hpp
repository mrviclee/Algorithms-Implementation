#ifndef PRIM_HPP
#define PRIM_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include "Graph.hpp"
struct MSTResults
{
    unsigned int totalWeight;
    std::vector<Edge> mstEdges;

    void ExportToDot(const std::string& filename) const
    {
        std::ofstream dotFile(filename);

        if (!dotFile.is_open())
        {
            throw std::ios_base::failure("Failed to open file for writing: " + filename);
        }

        dotFile << "graph MST {\n";

        for (const auto& edge : mstEdges)
        {
            dotFile << "  " << edge.source << " -- " << edge.destination
                << " [label=\"" << edge.weight << "\"];\n";
        }

        dotFile << "}\n";
        dotFile.close();
    }

};

struct CompareEdge
{
    bool operator()(const Edge& e1, const Edge& e2) const
    {
        return e1.weight > e2.weight; // Min-heap: smaller weight has higher priority
    }
};

MSTResults Prim(const Graph& graph)
{
    int vertices = graph.GetVertices();
    std::vector<bool> inMst(vertices, false);

    std::priority_queue <Edge, std::vector<Edge>, CompareEdge> minHeap;

    std::vector<Edge> mstEdges;
    unsigned int totalWeight;

    // start with vertex 0
    inMst[0] = true;
    for (const Edge& edge : graph.GetEdges())
    {
        if (edge.source == 0 || edge.destination == 0)
        {
            minHeap.emplace(edge);
        }
    }

    // process the priority queue
    while (!minHeap.empty() && mstEdges.size() < vertices - 1)
    {
        Edge edge = minHeap.top();
        minHeap.pop();

        int source = edge.source;
        int destination = edge.destination;

        // skip if both vertices are in the minimum spanning tree already
        if (inMst[source] && inMst[destination])
        {
            continue;
        }

        // add the top edge to the minimum spanning tree edges
        mstEdges.emplace_back(edge);
        totalWeight += edge.weight;

        int nextVertex = inMst[source] ? destination : source;
        inMst[nextVertex] = true;

        for (const Edge& edge : graph.GetEdges())
        {
            if (edge.source == nextVertex || edge.destination == nextVertex)
            {
                if (!inMst[edge.source] || !inMst[edge.destination])
                {
                    minHeap.emplace(edge);
                }
            }
        }
    }

    return { totalWeight, mstEdges };
}

#endif