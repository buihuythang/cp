#ifndef QUICKUF_H
#define QUICKUF_H

#include <iostream>
#include <cstdint>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


struct quf_t {
    vector<int> id;
    vector<int> sz;

    quf_t(int n)
        : id(n)
        , sz(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }

    quf_t()
        : id(13)
        , sz(13) {
        id[0] = 0;
        id[1] = 0;
        id[2] = 0;
        id[3] = 1;
        id[4] = 1;
        id[5] = 1;
        id[6] = 3;
        id[7] = 3;
        id[8] = 6;
        id[9] = 6;
        id[10] = 8;
        id[11] = 9;
        id[12] = 9;

        sz[0] = 13;
        sz[1] = 11;
        sz[2] = 1;
        sz[3] = 8;
        sz[4] = 1;
        sz[5] = 1;
        sz[6] = 6;
        sz[7] = 1;
        sz[8] = 2;
        sz[9] = 3;
        sz[10] = 1;
        sz[11] = 1;
        sz[12] = 1;
    }

    int root(int p) {
        vector<int> inter;
        while (p != id[p]) {
            inter.push_back(p);
            p = id[p];
        }

        for (auto i: inter) {
            id[i] = p;
        }

        return p;
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void unite(int p, int q) {
        int rp = root(p);
        int rq = root(q);

        if (rp != rq) {
            if (sz[rp] < sz[rq]) { id[rp] = id[rq]; sz[rq] += sz[rp]; }
            else                 { id[rq] = id[rp]; sz[rp] += sz[rq]; }
        }
    }

    void print() {
        cout << "ID:" << endl;
        cout << '\t';
        for (auto i: id) {
            cout << i << ' ';
        }
        cout << endl;

        cout << "SIZE:" << endl;
        cout << '\t';
        for (auto s: sz) {
            cout << s << ' ';
        }
        cout << endl;
    }
};

#endif // QUICKUF_H
