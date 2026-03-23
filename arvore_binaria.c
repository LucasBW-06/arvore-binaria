#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esquerda, *direita, *raiz;
} No;

typedef struct
{
    No *raiz;
} Avb;

void inserir_esquerda();

void inserir_direita();

void inserir_novo_no(Avb *arv, int valor) {
    if(arv->raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        arv->raiz = novoNo;
    } else {
        if(valor < arv->raiz->dado) {
            inserir_esquerda(arv->raiz, valor);
        }

        if(valor > arv->raiz->dado) {
            inserir_direita(arv->raiz, valor);
        }
    }
}

void inserir_esquerda(No *no, int valor) {
    if(no->esquerda == NULL) {
        No *novoNo;
        novoNo = (No*)malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        no->esquerda = novoNo;
    } else {
        if(valor < no->esquerda->dado) {
            inserir_esquerda(no->esquerda, valor);
        }
        if(valor > no->esquerda->dado) {
            inserir_direita(no->esquerda, valor);
        }
    }
}

void inserir_direita(No *no, int valor) {
    if(no->direita == NULL) {
        No *novoNo;
        novoNo = (No*)malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        no->direita = novoNo;
    } else {
        if(valor > no->direita->dado) {
            inserir_direita(no->direita, valor);
        }
        if(valor < no->direita->dado) {
            inserir_esquerda(no->direita, valor);
        }
    }
}

void imprimir(No *raiz) {
    if(raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d",raiz->dado);
        imprimir(raiz->direita);
    }
}

No* inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->dado = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(valor < raiz->dado) {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        if(valor > raiz->dado) {
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}

int tamanho(No *raiz) {
    if(raiz == NULL) {
        return 0;
    } else {
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

No* buscar(No *raiz, int chave) {
    if(raiz == NULL) {
        return NULL;
    } else {
        if(chave == raiz->dado) {
            return raiz;
        } else {
            if(chave < raiz->dado) {
                return buscar(raiz->esquerda, chave);
            } else {
                return buscar(raiz->direita, chave);
            }
        }
    }
}

No* remover_elemento(No *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    
    if (valor < raiz->dado) {
        raiz->esquerda = remover_elemento(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = remover_elemento(raiz->direita, valor);
    } else {
        if (raiz->direita == NULL && raiz->esquerda == NULL) {
            free(raiz);
            return NULL;
        }

        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        }

        if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* substituto = raiz->esquerda;

        while (substituto->direita != NULL) {
            substituto = substituto->direita;
        }

        raiz->dado = substituto->dado;

        raiz->esquerda = remover_elemento(raiz->esquerda, substituto->dado);
    }

    return raiz;
}

int main() {
    return 0;
}