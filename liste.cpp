
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
    Node_t *nodoDaCopiare;

    while ( pTmp != nullptr ) {
        nodoDaCopiare = creaNodo( pTmp->info );

        aggiungiNodoInCoda( &newHead, nodoDaCopiare );

        pTmp = pTmp->next;
    }

    return newHead;
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

Node_t *rimuoviNodoInTesta( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = ( *phead );
    ( *phead ) = ( *phead )->next;

    pTmp->next = nullptr;

    return pTmp;
}

Node_t *rimuoviNodoInCoda( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp;

    // 1 Solo nodo
    if ( ( *phead )->next == nullptr ) {
        pTmp = ( *phead );
        ( *phead ) = nullptr;
    }
    else {
        pTmp = trovaUltimoNodo( ( *phead ) );
        Node_t *pPenultimo = trovaPenultimoNodo( ( *phead ) );

        pPenultimo->next = nullptr;
    }

    return pTmp;
}

Node_t *rimuoviNodoInPosizione( Node_t **phead, int posizione ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = ( *phead );
    Node_t *pNodoDaRimuovere;
    int indicePosizione = 0;
    
    if ( posizione == 0 ) {
        return rimuoviNodoInTesta( phead );
    }

    while ( pTmp->next != nullptr && indicePosizione < ( posizione - 1 ) ) {
        pTmp = pTmp->next;
        indicePosizione++;
    }
    
    // Se esco per posizione troppo grande rimuovo in coda
    if ( pTmp->next == nullptr ) {
        pNodoDaRimuovere = rimuoviNodoInCoda( phead );
    }
    else {
        // pTmp è sul precedente
        pNodoDaRimuovere = pTmp->next;
        pTmp->next = pNodoDaRimuovere->next;
        pNodoDaRimuovere->next = nullptr;
    }

    return pNodoDaRimuovere;
}

void cancellaNodoInTesta( Node_t **phead ) {

    Node_t *pTmp = rimuoviNodoInTesta( phead );

    delete pTmp;
}

void cancellaNodoInCoda( Node_t **phead ) {

    Node_t *pTmp = rimuoviNodoInCoda( phead );

    delete pTmp;
}

void cancellaNodoInPosizione( Node_t **phead, int posizione ) {

    Node_t *pTmp = rimuoviNodoInPosizione( phead, posizione );

    delete pTmp;
}

void distruggiLista( Node_t **phead ) {

    Node_t *pTmp = ( *phead );

    while ( ( *phead ) != nullptr ) {
        cancellaNodoInTesta( phead );
    }
}

Node_t *trovaNodoPrecedente( Node_t *head, int posizione );
Node_t *trovaUltimoNodo( Node_t *head );
Node_t *trovaPenultimoNodo( Node_t *head );

int cercaElemento( Node_t *head );

void ordinaLista( Node_t **phead );
void invertiLista( Node_t **phead );
Node_t *unioneLista( Node_t *head1, Node_t *head_2 );
Node_t *intersezioneListe( Node_t *head1, Node_t *head_2 );