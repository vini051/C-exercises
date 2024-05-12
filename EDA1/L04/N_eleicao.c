#include <stdio.h>
#include <stdlib.h>

// Defina o número máximo de candidatos para cada cargo
#define MAX_PRESIDENTES 100
#define MAX_SENADORES 1000
#define MAX_DEPFEDS 10000
#define MAX_DEPESTS 100000

// Estrutura para armazenar os votos de cada candidato
typedef struct {
    int codigo;
    int votos;
} Candidato;

// Função para comparar candidatos (usada no qsort)
int compararCandidatos(const void *a, const void *b) {
    Candidato *candidatoA = (Candidato *)a;
    Candidato *candidatoB = (Candidato *)b;
    if (candidatoB->votos != candidatoA->votos) {
        return candidatoB->votos - candidatoA->votos;
    } else {
        return candidatoA->codigo - candidatoB->codigo;
    }
}

// Função para encontrar um candidato no array
int encontrarCandidato(Candidato candidatos[], int totalCandidatos, int codigo) {
    for (int i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Função para imprimir os vencedores
void imprimirVencedores(Candidato candidatos[], int totalVagas) {
    for (int i = 0; i < totalVagas; i++) {
        printf("%d ", candidatos[i].codigo);
    }
    printf("\n");
}

int main() {
    int S, F, E; // Quantidade de Senadores, dep.Fed e dep.Est
    int voto, index;
    int votosValidos = 0, votosInvalidos = 0;
    Candidato presidentes[MAX_PRESIDENTES] = {0};
    Candidato senadores[MAX_SENADORES] = {0};
    Candidato depFeds[MAX_DEPFEDS] = {0};
    Candidato depEsts[MAX_DEPESTS] = {0};
    int totalPresidentes = 0, totalSenadores = 0, totalDepFeds = 0, totalDepEsts = 0;

    // Leitura da quantidade de cargos a serem eleitos
    scanf("%d %d %d", &S, &F, &E);

    // Leitura e processamento dos votos
    while (scanf("%d", &voto) != EOF) {
        if (voto < 0) {
            votosInvalidos++;
        } else {
            votosValidos++;
            // Processamento dos votos para presidente
            if (voto < 100) {
                index = encontrarCandidato(presidentes, totalPresidentes, voto);
                if (index == -1) {
                    presidentes[totalPresidentes].codigo = voto;
                    presidentes[totalPresidentes].votos = 1;
                    totalPresidentes++;
                } else {
                    presidentes[index].votos++;
                }
            }
            // Processamento dos votos para senadores
            else if (voto < 1000) {
                index = encontrarCandidato(senadores, totalSenadores, voto);
                if (index == -1) {
                    senadores[totalSenadores].codigo = voto;
                    senadores[totalSenadores].votos = 1;
                    totalSenadores++;
                } else {
                    senadores[index].votos++;
                }
            }
            // Processamento dos votos para dep.Fed
            else if (voto < 10000) {
                index = encontrarCandidato(depFeds, totalDepFeds, voto);
                if (index == -1) {
                    depFeds[totalDepFeds].codigo = voto;
                    depFeds[totalDepFeds].votos = 1;
                    totalDepFeds++;
                } else {
                    depFeds[index].votos++;
                }
            }
            // Processamento dos votos para dep.Est
            else {
                index = encontrarCandidato(depEsts, totalDepEsts, voto);
                if (index == -1) {
                    depEsts[totalDepEsts].codigo = voto;
                    depEsts[totalDepEsts].votos = 1;
                    totalDepEsts++;
                } else {
                    depEsts[index].votos++;
                }
            }
        }
    }

    // Ordenação e impressão dos resultados
    qsort(presidentes, totalPresidentes, sizeof(Candidato), compararCandidatos);
    qsort(senadores, totalSenadores, sizeof(Candidato), compararCandidatos);
    qsort(depFeds, totalDepFeds, sizeof(Candidato), compararCandidatos);
    qsort(depEsts, totalDepEsts, sizeof(Candidato), compararCandidatos);

    // Imprimir a contagem de votos válidos e inválidos
    printf("%d %d\n", votosValidos, votosInvalidos);

    // Verificar se o presidente foi eleito no primeiro turno
    if (presidentes[0].votos > (votosValidos / 2)) {
        printf("%d\n", presidentes[0].codigo);
    } else {
        printf("Segundo Turno\n");
    }

    // Imprimir os vencedores dos outros cargos
    imprimirVencedores(senadores, S);
    imprimirVencedores(depFeds, F);
    imprimirVencedores(depEsts, E);

    return 0;
}
