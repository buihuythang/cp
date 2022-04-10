#ifndef PATHS_H
#define PATHS_H

#include "Graph.h"

#include <vector>


class Paths {
public:
    /**
     * @brief Find paths in G from source s
     */
    Paths(Graph g, int s);

    /**
     * @brief Is there path from s to v
     */
    bool hasPathTo(int v);

    /**
     * @brief Path from s to v or empty if no such path
     */
    std::vector<int> pathTo(int v);
private:
};

#endif // PATHS_H
