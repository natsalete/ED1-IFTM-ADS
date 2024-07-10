#include <iostream>
#include <string>

using namespace std;

struct No {
    string valor;
    No* prox;

    No(string n) {
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

    void inserirFinal(string n) {
        No* novo = new No(n);
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            fim->prox = novo;
            fim = novo;
        }
    }

    void etiqueta(string lingua){
        No* aux = inicio;
        while (aux != NULL) {
            if (aux->valor.compare(lingua) == 0) {
                if (aux->prox != NULL) {
                    cout << aux->prox->valor << endl;
                }
                break;
            }
            aux = aux->prox;
        }
    }
};

int main(){
    Lista l;

    int n;

    cin >> n;
    cin.ignore();
    n *= 2;

    string nomeLingua;
    while(n--){
        getline(cin,nomeLingua);
        l.inserirFinal(nomeLingua);
    }

    int x;

    cin >> x;
    cin.ignore();

    string nome;
    string lingua;
    while(x--){
        getline(cin, nome);
        getline(cin, lingua);
        cout << nome << endl;
        l.etiqueta(lingua);
        cout << endl;
    }


    return 0;
}


