
#include "liste.h"
#include <iostream>

using namespace std;

Node_t *creaLista() {

    return nullptr;
}

Node_t *creaNodo( int info ) {

    // Creo il nodo
    Node_t *aux = new Node_t;

    // Compilo i campi
    aux->info = info;
    aux->next = nullptr;

    return aux;
}