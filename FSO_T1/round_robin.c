#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
    int pid;
    int tempoexec; // Tempo de execução em segundos
    int tempo_restante; // Tempo restante para execução
    struct processo* prox;
} processo;

int main() {
    int num_processos, janela_tempo;
    float tempo_atual = 0.0; // Usar float para o tempo atual
    processo *head = NULL, *tail = NULL, *temp = NULL;

    // Ler o número de processos que vão executar
    scanf("%d", &num_processos);
    // Ler a janela de tempo (em milissegundos)
    scanf("%d", &janela_tempo);

    // Ler os processos e armazenar em uma lista encadeada
    for(int i = 0; i < num_processos; i++) {
        processo *novo_proc = malloc(sizeof(processo));
        scanf("%d", &novo_proc->pid);
        scanf("%d", &novo_proc->tempoexec);
        novo_proc->tempo_restante = novo_proc->tempoexec * 1000; // Converter para milissegundos
        novo_proc->prox = NULL;

        if(head == NULL) {
            head = novo_proc;
            tail = novo_proc;
        } else {
            tail->prox = novo_proc;
            tail = novo_proc;
        }
    }
    // Aponta a cauda para a cabeça da lista para formar uma lista circular
    tail->prox = head;

    // Executar o escalonamento Round Robin
    temp = head;
    while(num_processos > 0) {
        if(temp->tempo_restante > 0) {
            int tempo_executado = (temp->tempo_restante < janela_tempo) ? temp->tempo_restante : janela_tempo;
            temp->tempo_restante -= tempo_executado;
            tempo_atual += (float)tempo_executado; // Manter em milissegundos

            if(temp->tempo_restante == 0) {
                printf("%d (%.0f)\n", temp->pid, tempo_atual); // Imprimir o tempo em milissegundos
                num_processos--;
            }
        }
        temp = temp->prox;
    }

    // Liberar a memória alocada
    temp = head;
    while(temp != NULL) {
        processo *prox = temp->prox;
        free(temp);
        if(prox == head) break; // Se completou um ciclo na lista circular
        temp = prox;
    }

    return 0;
}
