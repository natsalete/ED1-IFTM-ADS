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

    void removerInicio(){
        if(n == 0) return;
        if(n == 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }

        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

     void removerFinal(){
        if(n == 0) return;
        if(n == 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while(aux->prox != fim){
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
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

    int calcularTamanho(){
        int cont = 0;
        No* aux = inicio;
        while(aux != NULL){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
};

int main(){
    //3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
    Lista l;

    int a;
    cin >> a;

    while (a--) {
        int b;
        cin >> b;
        l.inserirInicio(b);
    }

    int c;
    cin >> c;

    while (c--) {
        int d;
        cin >> d;
        l.inserirFinal(d);
    }
    
    cout << "Lista original:" << endl;
    l.imprimir();

    l.inserirFinal(l.calcularTamanho());
    
    cout << "Lista apos inserir no final o tamanho atual da lista:" << endl;
    l.imprimir();

    return 0;
}
