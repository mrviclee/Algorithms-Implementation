#include "Graph.hpp"

Graph::Graph(int vertices) : _vertices(vertices)
{
}

Graph::~Graph()
{
}

void Graph::AddEdge(int source, int destination, int weight)
{
    _edges.emplace_back(source, destination, weight);
}

std::vector<Edge> Graph::GetEdges() const
{
    return _edges;
}

unsigned int Graph::GetVertices() const
{
    return _vertices;
}

void Graph::ExportToDot(const std::string& fileName) const{
    std::ofstream dotFile(fileName);

    if (!dotFile.is_open())
    {
        throw std::ios_base::failure("Failed to open file" + fileName);
    }

    dotFile << "graph G {\n";

    for (const auto& edge : _edges)
    {
        dotFile << " " << edge.source << "--" << edge.destination << "[label=\"" << edge.weight << "\"]\n";
    }

    dotFile << "}\n";
    dotFile.close();
}