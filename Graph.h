#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>


class Graph {
public:
    Graph(int v);
    void addEdge(int v, int w);
    std::vector<int> adj(int v) const;
    int V() const;
    int E() const;

private:
    int numOfVertices;
    std::vector<std::vector<int>> vertices;

};

#endif // GRAPH_H
