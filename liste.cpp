
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
    
    Node_t *newHead = creaLista();
    Node_t *pTmp = pListaDaCopiare;

    while ( pTmp != nullptr ) {
        
    }
}

bool rimuoviDuplicati( Node_t **phead ) {

    if ( ( *phead ) == nullptr ) {
        return false;
    }

    Node_t *pCurr = ( *phead );
    Node_t *pCheck = pCurr;

    while ( pCurr != nullptr ) {
        while ( pCheck->next != nullptr ) {
            if ( pCheck->next->info == pCurr->info ) {
                // Duplicato
                Node_t *pDaCancellare = pCheck->next;
                pCheck->next = pDaCancellare->next;
                delete pDaCancellare;
            }
            else {
                pCheck = pCheck->next;
            }
        }

        pCurr = pCurr->next;
        pCheck = pCurr;
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
    else if ( posizione == 0 ) {
        aggiungiNodoInTesta( phead, pAux );
    }
    else {
        Node_t *pTmp = trovaNodoPrecedente( ( *phead ), posizione );

        pAux->next = pTmp->next;
        pTmp->next = pAux;
    }
}

void inserimentoOrdinato( Node_t **phead, Node_t *pAux ) {

    if ( ( *phead ) == nullptr || ( *phead )->info >= pAux->info ) {
        aggiungiNodoInTesta( phead, pAux );
    }
    else {
        // Se due nodi hanno lo stesso valore il nodo da inserire lo inserisco prima

        Node_t *pTmp = ( *phead );

        while ( pTmp->next != nullptr && pTmp->next->info < pAux->info ) {
            pTmp = pTmp->next;
        }

        pAux->next = pTmp->next;
        pTmp->next = pAux;
    }
}

Node_t *rimuoviNodoInTesta( Node_t **phead, Node_t *pAux ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = ( *phead );
    ( *phead ) = ( *phead )->next;

    return pTmp;
}

Node_t *rimuoviNodoInCoda( Node_t **phead, Node_t *pAux ) {

    // Lista vuota
        if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = trovaUltimoNodo( ( *phead ) );
    Node_t *pPenultimo = trovaPenultimoNodo( ( *phead ) );

    pPenultimo->next = nullptr;

    return pTmp;
}