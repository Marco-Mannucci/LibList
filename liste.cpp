
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

bool rimuoviDuplicati( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return false;
    }

    // Lista non vuota
    Node_t *pCurr = ( *phead );
    Node_t *pCheck = ( *phead );
    int posizione = 0;

    while ( pCurr != nullptr ) {
        while ( pCheck != nullptr ) {
            pCheck = pCheck->next;
            posizione++;

            if ( pCheck->info == pCurr->info ) {
                cancellaNodoInPosizione( phead, pCheck, posizione );
            }
        }

        pCurr = pCurr->next;
    }

    return true;
}

void aggiungiNodoInTesta( Node_t **phead, Node_t *pAux ) {

    if ( ( *phead ) != nullptr ) {
        pAux->next = ( *phead );
    }

    ( *phead ) = pAux;
}