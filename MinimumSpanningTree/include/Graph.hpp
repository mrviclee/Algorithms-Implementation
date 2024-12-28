#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <fstream>
#include "Edge.hpp"

class Graph
{
private:
    unsigned int _vertices;
    std::vector<Edge> _edges;
public:
    Graph(int vertices);
    ~Graph();

    void AddEdge(int source, int destination, int wegiht);
    std::vector<Edge> GetEdges() const;
    unsigned int GetVertices() const;
    void ExportToDot(const std::string& filename) const;
};

#endif
