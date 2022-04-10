//#include <bits/stdc++.h>

//using namespace std;

//int v[100000];

//int main() {
//    int T;

//    scanf("%d", &T);
//    for (int i = 0; i < T; ++i) {
//        set<int> r;
//        int N, K, R, P;
//        uint64_t E = 0;

//        scanf(" %d %d", &N, &K);

//        for (int j = 0; j < N; ++j) r.insert(j+1);

//        int examined = 0;
//        while (K >= 0 && examined < N) {
//            printf("K = %d, examined = %d\n", K, examined);
//            fflush(stdout);
//            scanf(" %d", &R); if (R == -1) exit(1);
//            scanf(" %d", &P);
//            printf("%d %d\n", R, P);
//            fflush(stdout);

//            if (!v[R-1]) {
//                v[R-1] = 1;
//                E += P;
//                r.erase(R);
//                if (K) {
//                    printf("W\n");
//                    fflush(stdout);
//                }
//            } else {
//                --E;
//                if (K) {
//                    auto it = r.begin();
//                    printf("T %d\n", *it);
//                    fflush(stdout);
//                    r.erase(it);
//                }
//            }

//            --K;
//            examined = E;

//            printf("E = %" PRIu64 "\n", E);
//            fflush(stdout);
//        }

//        printf("E %" PRIu64 "\n", E);
//        fflush(stdout);

//        if (i < T - 1) {
//            memset(v, 0, N * sizeof(int));
//        }
//    }
//}


#include <bits/stdc++.h>

using namespace std;

int v[100000];

int main() {
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        set<int> r;
        int N, K, R, P;
        uint64_t E = 0;

        scanf(" %d %d", &N, &K);

        for (int j = 0; j < N; ++j) r.insert(j+1);

        int examined = 0;
        while (K >= 0 && examined < N && !r.empty()) {
            scanf(" %d", &R); if (R == -1) return 0;
            scanf(" %d", &P);

            if (!v[R-1]) {
                v[R-1] = 1;
                E += P;
                ++examined;
                r.erase(R);
                if (K) {
                    printf("W\n");
                    fflush(stdout);
                }
            } else {
                --E;
                if (K) {
                    auto it = r.begin();
                    printf("T %d\n", *it);
                    fflush(stdout);
                    r.erase(it);
                }
            }

            --K;

        }

        printf("E %" PRIu64 "\n", E);
        fflush(stdout);

        if (i < T - 1) {
            memset(v, 0, N * sizeof(int));
        }
    }
}
