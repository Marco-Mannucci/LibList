
#include "liste.h"
#include <iostream>

using namespace std;

Node_t *creaLista() {

    return nullptr;
}

Node_t *creaNodo( int info ) {

    // Creo il nodo
    Node_t *pAux = new Node_t;

    // Compilo i campi
    pAux->info = info;
    pAux->next = nullptr;

    return pAux;
}

bool checkListaVuota( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return true;
    }

    // Lista non vuota
    return false;
}

Node_t *copiaLista( Node_t *pListaDaCopiare ) {
    
    return pListaDaCopiare;
}