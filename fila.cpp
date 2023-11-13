#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
       No* fim;
} Fila;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
     if (!fila) {
            perror("Erro ao alocar memória para a fila");
        exit(EXIT_FAILURE);
    }


    fila->inicio = NULL;


    fila->fim = NULL;
    return fila;
}

int estaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila* fila, int item) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = item;
    novoNo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Erro: A fila está vazia.\n");
        return -1;
    }

    No* temp = fila->inicio;
    int item = temp->dado;

    if (fila->inicio == fila->fim) {
        fila->inicio = fila->fim = NULL;
    } else {


            fila->inicio = fila->inicio->proximo;
    }


    free(temp);

    return item;
}

void imprimirFila(Fila* fila) {
    if (estaVazia(fila)) {
            printf("A fila está vazia.\n");
        return;
    }

          No* atual = fila->inicio;
    while (atual) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void destruirFila(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }

    free(fila);
}

int main() {

    Fila* fila = criarFila();

    enfileirar(fila, 1220);
    enfileirar(fila, 210);
    enfileirar(fila, 330);
    enfileirar(fila, 330);
      enfileirar(fila, 330);
      enfileirar(fila, 91330);
    printf("Fila: ");
    imprimirFila(fila);

    printf("Elemento removido da fila: %d\n", desenfileirar(fila));

    printf("Fila após elemento removido: ");
    imprimirFila(fila);

    destruirFila(fila);

    return 0;
}
