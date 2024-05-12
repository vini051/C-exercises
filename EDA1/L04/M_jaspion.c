#include <stdio.h>
#include <string.h>

int main() {
    int T, M, N;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %d\n", &M, &N);
        char japones[1000000][21], portugues[1000000][81], linha[81], *palavra;
        
        for(int i = 0; i < M; i++) {
            fgets(japones[i], 21, stdin);
            japones[i][strcspn(japones[i], "\n")] = 0; // Remove newline
            fgets(portugues[i], 81, stdin);
            portugues[i][strcspn(portugues[i], "\n")] = 0; // Remove newline
        }
        
        for(int i = 0; i < N; i++) {
            fgets(linha, 81, stdin);
            linha[strcspn(linha, "\n")] = 0; // Remove newline
            palavra = strtok(linha, " ");
            
            while(palavra) {
                int encontrado = 0;
                for(int j = 0; j < M; j++) {
                    if(strcmp(palavra, japones[j]) == 0) {
                        printf("%s ", portugues[j]);
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) {
                    printf("%s ", palavra);
                }
                palavra = strtok(NULL, " ");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
