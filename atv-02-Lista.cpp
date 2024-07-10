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

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int n) {
        No* novo = new No(n);

        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        this->n++;
    }

    void inserirFinal(int n) {
        No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerSegundoElemento() {
        if (n <= 1) return;
        No* aux = inicio->prox;
        inicio->prox = aux->prox;
        if (aux == fim) {
            fim = inicio;
        }
        delete aux;
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete inicio;
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete fim;
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
};

int main() {
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

    l.imprimir();

    l.removerSegundoElemento();

    l.imprimir();

    return 0;
}
