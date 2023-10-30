#include <stdio.h>

int main () {
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    int max = ((x/a)*(y/b)*(z/c));
    if (a >= 1 && b >= 1 && c >= 1 && x >= 1 && y >= 1 && z >= 1 &&
        a <= 1e6 && b <= 1e6 && c <= 1e6 && x <= 1e6 && y <= 1e6 && z <= 1e6) {
            
        printf("%d", max);

    }

    return 0;
}