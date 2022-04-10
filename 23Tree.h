#ifndef TWO_THREE_TREE
#define TWO_THREE_TREE

#include <bits/stdc++.h>

using namespace std;


struct node_t {
    node_t *left;
    node_t *mid;
    node_t *right;
    pair<bool,int> first;
    pair<bool,int> second;
};


class T3Tree {
public:
    T3Tree()
        : node(nullptr) {
    }

    ~T3Tree() {
    }

    void insert(int k);

private:
    node_t *node;
};


void T3Tree::insert(int k) {
    if (!node) {
        node_t *n = new node_t;
        n->first = {true, k};
        node = n;

        return;
    } else if (!node->second.first) {
        node->second = {true, k};
        if (k < node->first.second) swap(node->first, node->second);

        return;
    }

    node_t *cur = node;
    while (true) {
        if (k < cur->first.second) {
            if (!cur->left) break;
        }
    }
}

#endif // TWO_THREE_TREE
