#ifndef EDGE_H
#define EDGE_H


class Edge {
public:
    Edge(int v, int w, double weight);
    int either() const;
    int other(int v) const;
    int compareTo(Edge that);
    double extractWeight();

private:
    int mv;
    int mw;
    double mweight;
};

#endif // EDGE_H
