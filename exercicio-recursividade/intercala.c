#include <stdio.h>
#include <stdlib.h>

char* intercala(char *V1, char *V2, char *V3){
    if(*V1 == '\0' && *V2 == '\0'){
        *V3 = '\0';
        return V3;
    }
    if(*V1 != '\0'){
        *V3 = *V1;
        intercala(V2, V1 + 1, V3 + 1);
    }
    if(*V2 != '\0'){
        *V3 = *V2;
        intercala(V2 + 1, V1, V3 + 1);
    }
    return V3;
}

int main(){
    char *V1 = "abc", *V2 = "ABCDE";
    char *V3 = malloc(sizeof(V1) + sizeof(V2));
    printf("Intercalado: %s\n", intercala(V1, V2, V3));
    return 0;
}