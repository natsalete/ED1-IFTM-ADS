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
    int cont = 0;

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

    void menorValor(){
        No* aux = inicio;
        int menor = aux->valor;
        int posicao;
        while(aux != NULL){
            if(aux->valor < menor){
                menor = aux->valor;
                posicao = cont;
            }
            aux = aux->prox;
            cont++;
        }

        cout << "Menor valor: " << menor << endl;
        cout << "Posicao: " << posicao << endl;
    }

};

int main(){
    Lista l;

    int n;

    cin >> n;

    while(n--){
        int x;
        cin >> x;
        l.inserirFinal(x);
    }

    l.menorValor();

    return 0;
}
