#include <bits/stdc++.h>

using namespace std;


void draw(int R, int C) {
    printf("..");
    char border[] = "+-";
    char cell[] = "|.";

    for (int i = 1; i < C; ++i) printf("%s", border);
    printf("%c\n", border[0]);

    printf("..");
    for (int i = 1; i < C; ++i) printf("%s", cell);
    printf("%c\n", cell[0]);

    for (int i = 1; i < R; ++i) {
        for (int j = 0; j < C; ++j)
            printf("%s", border);
        printf("%c\n", border[0]);

        for (int j = 0; j < C; ++j)
            printf("%s", cell);
        printf("%c\n", cell[0]);
    }

    for (int i = 0; i < C; ++i) printf("%s", border);
    printf("%c\n", border[0]);
}

int main() {
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int R, C;

        scanf("%d %d", &R, &C);

        printf("Case #%d:\n", i + 1);
        draw(R, C);
    }

    return 0;
}
