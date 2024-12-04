#include <stdio.h>

int verifica(char *a, char *b, int i){
    if (a[i] != b[i]){
        return 0;
    } else if ( i<sizeof(a) && (a[i] == b[i])){   
    verifica(a, b, ++i);
    }
    return 1;
}

int main(){
    int i = 0;
    char a[20], b[20];
    printf("Digite a primeira string:\n");
    fgets(a, 20, stdin);
    printf("Digite a segunda string:\n");
    fgets(b, 20, stdin);
    int igual = verifica(a, b, i);
    if (igual == 1){printf("As strings são iguais.\n");}
    else if (igual == 0){printf("As strings NÃO são iguais.\n");}
    return 0;
}