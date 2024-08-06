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

    void inserirFinal(int n) {
        No* novo = new No(n);
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            fim->prox = novo;
            fim = novo;
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
    //4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.
    Lista l;

    int n;

    cin >> n;

    int i = 1;

    while(n--){
        l.inserirFinal(i++);
    }

    l.imprimir();
    return 0;
}
