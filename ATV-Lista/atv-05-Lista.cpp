#include <iostream>

using namespace std;

struct No {
    int valor;
    No* prox;

    No(int n) {
        valor = n;
        prox = NULL;
    }
};

struct Lista {
    No* inicio;
    No* fim;
    int n;

    Lista(){
        inicio = NULL;
        fim = NULL;
    }

    void inserirInicio(int n) {
        No* novo = new No(n);

        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirPenultima(int n) {
        if (n <= 1) return;

        No* novo = new No(n);

        if (n == 2) { // Se a lista tem exatamente 2 elementos
            novo->prox = fim;
            inicio->prox = novo;
        } else {
            No* aux = inicio;
            while (aux->prox != fim) {
                aux = aux->prox;
            }
            novo->prox = fim;
            aux->prox = novo;
        }
        n++;
    }

    void imprimir() {
            No* aux = inicio;
            //printf("%d %d\n", aux, aux->valor);
            while(aux != NULL) {
                printf("%d\n", aux->valor);
                //printf("%d %d\n", aux->prox, aux->valor);
                aux = aux->prox;
            }

    }
};

int main(){
    //5. Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    Lista l;

    // Exemplo de uso
    l.inserirInicio(3);
    l.inserirInicio(2);
    l.inserirInicio(1);

    cout << "Lista original:" << endl;
    l.imprimir();

    l.inserirPenultima(99);

    cout << "Lista apos inserir na penultima posicao:" << endl;
    l.imprimir();

    return 0;
}
