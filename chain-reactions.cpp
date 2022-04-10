//#include <bits/stdc++.h>

//using namespace std;


//uint64_t sum;

//int contract(const vector<vector<int>> &graph, int v, const vector<int> &F) {
////    cout << "v = " << v << endl;
////    cout << "go here" << endl;
//    vector<int> mf;
//    for (auto w: graph[v]) {
////        cout << "w = " << w << endl;
//        int ss = contract(graph, w, F);
////        printf("ss = %d\n", ss);
//        mf.push_back(ss);
//    }
//    if (mf.empty()) return F[v];

//    auto it = min_element(mf.begin(), mf.end());

//    sum = accumulate(mf.begin(), it, sum);
//    sum = accumulate(it + 1, mf.end(), sum);

//    if (*it < F[v]) *it = F[v];

//    return *it;
//}


//int main() {
//    int T;
//    scanf("%d", &T);

//    for (int i = 0; i < T; ++i) {
//        int N;
//        scanf("%d", &N);

////        printf("N = %d\n", N);

//        vector<vector<int>> graph(N);
//        vector<int> F(N);
//        vector<int> roots;
////        vector<int> MF;

//        for (int j = 0; j < N; ++j) {
//            scanf(" %d", &F[j]);
//        }

//        for (int j = 0; j < N; ++j) {
//            int p;
//            scanf(" %d", &p);
//            if (p) graph[p-1].push_back(j);
//            else roots.push_back(j);
//        }

////        for (int j = 0; j < N; ++j) {
////            cout << j << ": ";
////            for (auto w: graph[j]) {
////                cout << w << ' ';
////            }
////            cout << endl;
////        }

////        uint64_t sum = 0;
////        cout << "root size = " << roots.size() << ": ";
//        for (auto r: roots) {
//            sum += contract(graph, r, F);
////            sum = accumulate(MF.begin(), MF.end(), sum);
////            MF.clear();
////            cout << r << ' ';
//        }
////        cout << endl;
////        memset(marked, 0, N*sizeof(int));
//        printf("Case #%d: %" PRIu64 "\n", i + 1, sum);
//        sum = 0;
//    }

//    return 0;
//}


#include <bits/stdc++.h>

using namespace std;


uint64_t sum;

int contract(const vector<vector<int>> &graph, int v, const vector<int> &F) {
    vector<int> mf;
    for (auto w: graph[v]) {
        int ss = contract(graph, w, F);
        mf.push_back(ss);
    }
    if (mf.empty()) return F[v];

    auto it = min_element(mf.begin(), mf.end());

    sum = accumulate(mf.begin(), it, sum);
    sum = accumulate(it + 1, mf.end(), sum);

    if (*it < F[v]) *it = F[v];

    return *it;
}


int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d", &N);

        vector<vector<int>> graph(N);
        vector<int> F(N);
        vector<int> roots;

        for (int j = 0; j < N; ++j) {
            scanf(" %d", &F[j]);
        }

        for (int j = 0; j < N; ++j) {
            int p;
            scanf(" %d", &p);
            if (p) graph[p-1].push_back(j);
            else roots.push_back(j);
        }

        for (auto r: roots) {
            sum += contract(graph, r, F);
        }

        printf("Case #%d: %" PRIu64 "\n", i + 1, sum);
        sum = 0;
    }

    return 0;
}

