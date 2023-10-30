#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a == b) && (b == c) && ( a== c)){
        printf("%s\n", "empate");
    } else if ((a != b) && (b == c) && (a != c)){
        printf("%s\n", "A");
    }else if ((a != b) && (b != c) && (a == c)){
        printf("%s\n", "B");
    }else if ((a == b) && (b != c) && (a != c)){
        printf("%s\n", "C");
    }
    return 0;
}