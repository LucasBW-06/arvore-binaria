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

Avb* criar_arvore() {
    Avb *arv = (Avb*) malloc(sizeof(Avb));
    arv->raiz = NULL;
    return arv;
}

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
        printf("%d\n",raiz->dado);
        imprimir(raiz->direita);
    }
}

No* apagar_arvore(No* raiz) {
    if (raiz != NULL) {
        raiz->direita = apagar_arvore(raiz->direita);
        raiz->esquerda = apagar_arvore(raiz->esquerda);
        free(raiz);
    }
    return NULL;
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
    Avb *arv = criar_arvore(arv);
    inserir_novo_no(arv, 5);
    inserir_novo_no(arv, 2);
    inserir_novo_no(arv, 3);
    inserir_novo_no(arv, 4);
    inserir_novo_no(arv, 1);
    inserir_novo_no(arv, 6);
    inserir_novo_no(arv, 7);
    inserir_novo_no(arv, 8);
    inserir_novo_no(arv, 10);
    inserir_novo_no(arv, 9);

    imprimir(arv->raiz);
    printf("Tam:%d\n\n", tamanho(arv->raiz));

    arv->raiz = apagar_arvore(arv->raiz);

    imprimir(arv->raiz);
    printf("Tam:%d\n\n", tamanho(arv->raiz));

    arv->raiz = inserir(arv->raiz, 5);
    arv->raiz = inserir(arv->raiz, 2);
    arv->raiz = inserir(arv->raiz, 3);
    arv->raiz = inserir(arv->raiz, 4);
    arv->raiz = inserir(arv->raiz, 1);
    arv->raiz = inserir(arv->raiz, 6);
    arv->raiz = inserir(arv->raiz, 7);
    arv->raiz = inserir(arv->raiz, 8);
    arv->raiz = inserir(arv->raiz, 10);
    arv->raiz = inserir(arv->raiz, 9);

    imprimir(arv->raiz);
    printf("Tam:%d\n", tamanho(arv->raiz));

    printf("%d\n\n", buscar(arv->raiz, 8)->dado);
    
    arv->raiz = remover_elemento(arv->raiz, 3);
    arv->raiz = remover_elemento(arv->raiz, 6);
    arv->raiz = remover_elemento(arv->raiz, 5);

    imprimir(arv->raiz);
    printf("Tam:%d", tamanho(arv->raiz));

    return 0;
}