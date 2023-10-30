#include <stdio.h>
#include <string.h>

void movex(char *a, int n){
    if(n == 0){
    return;
    }
    int i;
    for(i = 0; i < n-1; i++){
        if(a[i] == 'x'){
            a[i+1] = a[i];
        }
    }
        movex(a, n);
}

int main(){
    char entrada[101];
    scanf("%s", entrada);
    //printf("%ld\n", strlen(entrada));
    movex(entrada, strlen(entrada));
    printf("%s", entrada);
    return 0;
}