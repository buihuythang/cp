#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H

#include "Edge.h"

#include <vector>


class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(int v);
    void addEdge(const Edge &e);
    std::vector<Edge> adj(int v);
    std::vector<Edge> allEdges();
    int V();
    int E();

private:
    int numOfVertices;
    std::vector<std::vector<Edge>> vertices;
    std::vector<Edge> edges;
};

#endif // EDGEWEIGHTEDGRAPH_H
