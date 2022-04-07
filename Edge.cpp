#include "Edge.h"



Edge::Edge(int v, int w, double weight)
    : mv(v)
    , mw(w)
    , mweight(weight) {
}


int Edge::either() const {
    return mv;
}


int Edge::other(int v) const {
    if (v == mv) return mw;
    else         return mv;
}


int Edge::compareTo(Edge that) {
    if      (mweight < that.mweight) return -1;
    else if (mweight > that.mweight) return +1;
    else                             return 0;
}


double Edge::extractWeight() {
    return mweight;
}
