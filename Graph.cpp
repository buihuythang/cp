#include "Graph.h"

using std::vector;
using std::string;


Graph::Graph(int v)
    : numOfVertices(v)
    , vertices(v) {
}


void Graph::addEdge(int v, int w) {
    if (v > numOfVertices || w > numOfVertices) return;

    vertices[v].push_back(w);
    vertices[w].push_back(v);
}


vector<int> Graph::adj(int v) const {
    if (v > numOfVertices) return {};

    return vertices[v];
}


int Graph::V() const {
    return numOfVertices;
}


int Graph::E() const {
    int ne = 0;
    for (const auto &v: vertices) ne += (int)v.size();

    return ne>>1;
}


