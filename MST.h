#ifndef MST_H
#define MST_H

#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include <vector>


class MST {
public:
    MST(const EdgeWeightedGraph &g);
    std::vector<Edge> edges();
    double minWeight();

private:
    EdgeWeightedGraph graph;
};

#endif // MST_H
