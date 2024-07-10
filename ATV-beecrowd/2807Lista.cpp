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
    }

    void imprimir() {
        No* aux = inicio;
        while (aux != fim) {
            cout << aux->valor << " ";
            aux = aux->prox;
        }
        cout << aux->valor << endl;
    }
};

int main(){
    Lista l;

    int n;

    cin >> n;

    if (n > 0) {
        l.inserirInicio(1);
    }
    if(n > 1){
        l.inserirInicio(1);
    }

    int a = 1, b = 1;
    for(int i = 2; i < n; i++){
        int novoValor = a + b;
        l.inserirInicio(novoValor);
        a = b;
        b = novoValor;
    }

    l.imprimir();

    return 0;
}
