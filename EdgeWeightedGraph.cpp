#include "EdgeWeightedGraph.h"

using std::vector;


EdgeWeightedGraph::EdgeWeightedGraph(int v)
    : numOfVertices(v)
    , vertices(v) {
}


void EdgeWeightedGraph::addEdge(const Edge &e) {
    edges.push_back(e);
    int v = e.either();
    int w = e.other(v);

    vertices[v].push_back(e);
    vertices[w].push_back(e);
}


vector<Edge> EdgeWeightedGraph::adj(int v) {
    return vertices[v];
}


vector<Edge> EdgeWeightedGraph::allEdges() {
    return edges;
}


int EdgeWeightedGraph::V() {
    return numOfVertices;
}


int EdgeWeightedGraph::E() {
    int ne = 0;
    for (int i = 0; i < numOfVertices; ++i) {
        ne += vertices[i].size();
    }

    return ne>>1;
}
