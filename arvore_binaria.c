#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esqueda, *direita, *raiz;
} No;

typedef struct
{
    No *raiz;
} Avb;

void inserir_novo_no(Avb *arv, int valor) {
    if(arv->raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->dreita = NULL;
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

void inserir_direita(No *no, valor) {
    if(no->direia == NULL) {
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
        print("%d",raiz->dado);
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

int buscar(No *raiz, int chave) {
    if(raiz == NULL) {
        return -1;
    } else {
        if(chave == raiz->dado) {
            return *raiz;
        } else {
            if(chave < raiz->dado) {
                return buscar(raiz->esquerda, chave);
            } else {
                return buscar(raiz->direita, chave);
            }
        }
    }
}