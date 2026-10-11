
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

    if ( ( *phead ) == nullptr ) {
        return false;
    }

    // Puntano al primo nodo
    Node_t *pCurr = ( *phead );
    Node_t *pCheck = ( *phead );
    int posizione = 0;

    while ( pCurr != nullptr ) {
        while ( pCheck != nullptr ) {
            pCheck = pCheck->next;      // Sposto Check sul successivo
            posizione++;

            if ( pCheck->info == pCurr->info ) {
                cancellaNodoInPosizione( phead, pCheck, posizione );
            }
        }

        pCurr = pCurr->next;            // Sposto Curr sul successivo
    }

    return true;
}

void aggiungiNodoInTesta( Node_t **phead, Node_t *pAux ) {

    if ( ( *phead ) != nullptr ) {
        pAux->next = ( *phead );
    }

    ( *phead ) = pAux;
}

void aggiungiNodoInCoda( Node_t **phead, Node_t *pAux ) {
    
    if ( ( *phead ) == nullptr ) {
        ( *phead ) = pAux;
    }
    else {
        Node_t *pTmp = trovaUltimoNodo( ( *phead ) );
        pTmp->next = pAux;
    }
}

void aggiungiNodoInPosizione( Node_t **phead, Node_t *pAux, int posizione ) {

    if ( ( *phead ) == nullptr ) {
        ( *phead ) = pAux;
    }
    else {
        Node_t *pTmp = trovaNodoPrecedente( ( *phead ), posizione );

        // Posizione accettabile
        if ( ( pTmp->next) != nullptr) {
            pAux = pTmp->next;
        }

        pTmp->next = pAux;
    }
}

void inserimentoOrdinato( Node_t **phead, Node_t *pAux ) {

    if ( ( *phead ) == nullptr ) {
        ( *phead ) = pAux;
    }
    else {
        // Se due nodi hanno lo stesso valore il nodo da inserire lo inserisco prima
        Node_t *pTmp = ( *phead );

        // Primo nodo gia maggiore del nodo da inserire
        if ( ( pTmp->info ) <= ( pAux->info ) ) {
            aggiungiNodoInTesta( phead, pAux );
        }
        else {
            while ( pTmp != nullptr ) {
                // Ultimo Nodo
                if ( ( pTmp->next ) == nullptr ) {
                    aggiungiNodoInCoda( phead, pAux );
                }
                else if ( ( pTmp->next->info ) >= ( pAux->info ) ) {
                    pAux = pTmp->next;
                    pTmp->next = pAux;
                }
            } 
        }
    }
}