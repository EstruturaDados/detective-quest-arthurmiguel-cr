
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de uma sala da mansão (nó da árvore binária)
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

/*
 * criarSala()
 * Cria dinamicamente uma sala com o nome informado.
 */
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/*
 * explorarSalas()
 * Permite ao jogador navegar pela árvore.
 * Enquanto houver caminhos, segue explorando pelos comandos:
 *   e - esquerda
 *   d - direita
 *   s - sair
 */
void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVoce entrou na sala: %s\n", atual->nome);

        // Se for sala sem caminhos → fim da exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Nao ha mais caminhos. Fim da exploracao!\n");
            return;
        }

        printf("Escolha o caminho (e = esquerda | d = direita | s = sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Nao ha sala a esquerda!\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Nao ha sala a direita!\n");
            }
        }
        else if (opcao == 's') {
            printf("Exploracao encerrada pelo jogador.\n");
            return;
        }
        else {
            printf("Opcao invalida, tente novamente.\n");
        }
    }
}

/*
 * main()
 * Monta o mapa da mansão manualmente em forma de árvore binária
 * e inicia a exploração.
 */
int main() {
    // Criando as salas
    Sala* hall = criarSala("Hall de Entrada");

    // Nivel 1
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita  = criarSala("Cozinha");

    // Nivel 2
    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita  = criarSala("Jardim de Inverno");

    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita  = criarSala("Salao de Jantar");

    // Começa o jogo
    printf("=== DETECTIVE QUEST ===\n");
    printf("Exploracao iniciada...\n");

    explorarSalas(hall);

    return 0;
}

