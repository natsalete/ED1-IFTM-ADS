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
    int n;

    Lista(){
        inicio = NULL;
        fim = NULL;
    }

    void inserirInicio(string n) {
        No* novo = new No(n);

        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            novo->prox = inicio;
            inicio = novo;
        }
        //n++;
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
        //n++;
    }

    void imprimir() {
            No* aux = inicio;
            //printf("%d %d\n", aux, aux->valor);
            while(aux != NULL) {
                //printf("%c\n", aux->valor);
                cout << aux->valor << endl;
                //printf("%d %d\n", aux->prox, aux->valor);
                aux = aux->prox;
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


    //l.imprimir();

    return 0;
}


