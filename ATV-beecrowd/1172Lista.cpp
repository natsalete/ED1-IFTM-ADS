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
            int i = 0;
            while(aux != NULL) {
                cout << "X[" << i++ << "] = ";
                printf("%d\n", aux->valor);
                //printf("%d %d\n", aux->prox, aux->valor);
                aux = aux->prox;
            }

    }
};


int main(){
    Lista l;

    int n = 10;
    while(n--){
        int x;
        cin >> x;
        if(x <= 0){
            x = 1;
        }
        l.inserirFinal(x);
    }

    l.imprimir();

    return 0;
}
