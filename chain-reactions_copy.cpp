#include <bits/stdc++.h>

using namespace std;


int marked[100000];

void contract(const vector<vector<int>> &graph, int v, const vector<int> &F, vector<int> &MF) {
    if (marked[v]) return;

    int anchor = MF.size();
//    printf("anchor = %d\n", anchor);
    for (auto w: graph[v]) {
        contract(graph, w, F, MF);
    }
    marked[v] = 1;

    if (!graph[v].size()) {
        MF.push_back(F[v]);
    } else {
        auto it = min_element(MF.begin()+anchor, MF.end());
        if (*it < F[v]) *it = F[v];
    }
}


int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d", &N);

//        printf("N = %d\n", N);

        vector<vector<int>> graph(N);
        vector<int> F(N);
        vector<int> roots;
        vector<int> MF;

        for (int j = 0; j < N; ++j) {
            scanf(" %d", &F[j]);
        }

        for (int j = 0; j < N; ++j) {
            int p;
            scanf(" %d", &p);
            if (p) graph[p-1].push_back(j);
            else roots.push_back(j);
        }

//        for (int j = 0; j < N; ++j) {
//            cout << j << ": ";
//            for (auto w: graph[j]) {
//                cout << w << ' ';
//            }
//            cout << endl;
//        }

        uint64_t sum = 0;
//        cout << "root size = " << roots.size() << ": ";
        for (auto r: roots) {
            contract(graph, r, F, MF);
            sum = accumulate(MF.begin(), MF.end(), sum);
            MF.clear();
//            cout << r << ' ';
        }
//        cout << endl;
        memset(marked, 0, N*sizeof(int));
        printf("Case #%d: %" PRIu64 "\n", i + 1, sum);
    }

    return 0;
}
