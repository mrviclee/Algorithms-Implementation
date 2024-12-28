#ifndef EDGE_HPP
#define EDGE_HPP

class Edge
{
public:
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight);
    ~Edge();
};

#endif