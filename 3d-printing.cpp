#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;

    constexpr int total = 1000000;


    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int c[3], m[3], y[3], k[3];

        scanf(" %d %d %d %d", &c[0], &m[0], &y[0], &k[0]);
        scanf(" %d %d %d %d", &c[1], &m[1], &y[1], &k[1]);
        scanf(" %d %d %d %d", &c[2], &m[2], &y[2], &k[2]);


        int cm = min(min(c[0], c[1]), c[2]);
        int mm = min(min(m[0], m[1]), m[2]);
        int ym = min(min(y[0], y[1]), y[2]);
        int km = min(min(k[0], k[1]), k[2]);

        printf("Case #%d: ", i + 1);
        if (cm + mm + ym + km < total) {
            printf("IMPOSSIBLE\n");
        } else {
            int remaining = total;
            printf("%d", cm);

            remaining = remaining - cm > 0 ? remaining - cm : 0;
            if (remaining <= mm ) {
                printf(" %d 0 0\n", remaining);
                continue;
            }

            remaining = remaining - mm > 0 ? remaining - mm : 0;
            if (remaining <= ym ) {
                printf(" %d %d 0\n", mm, remaining);
                continue;
            }

            remaining = remaining - ym > 0 ? remaining - ym : 0;
            if (remaining <= km ) {
                printf(" %d %d %d\n", mm, ym, remaining);
                continue;
            }
        }
    }

    return 0;
}
