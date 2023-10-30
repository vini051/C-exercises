#include <stdio.h>
#include <stdlib.h>

int main() {
    int m[2], r[2];
    scanf("%d %d %d %d", &m[0], &m[1], &r[0], &r[1]);
    int dist = ((r[0]-m[0])+(r[1]-m[1]));
    printf("%d\n", abs(dist));
    return 0;
}