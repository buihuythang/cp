#include <bits/stdc++.h>

using namespace std;

int S[100000];
int D[100000];

int main() {
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d", &N);

        memset(D, 0, N * sizeof(int));

        for (int j = 0; j < N; ++j) {
            scanf(" %d", &S[j]);
        }

        sort(S + 0, S + N);

//        for (int j = 0; j < N; ++j) {
//            printf("%d ", S[j]);
//        }
//        printf("\n");

        int k = 0;
        D[k++] = 1;
//        printf("D[%d]=%d\n", k-1, D[k-1]);
        for (int j = 1; j < N; ++j) {
//            printf("k = %d\n", k);
            if (S[j] > D[k-1]) {

                D[k] = D[k-1] + 1;
//                printf("k = %d, D[k] = %d\n", k, D[k]);
                ++k;
            }
        }

//        for (int j = 0; j < k; ++j) {
//            printf("%d ", D[j]);
//        }

//        printf("\n");
        printf("Case #%d: %d\n", i + 1, D[k-1]);

    }

    return 0;
}
