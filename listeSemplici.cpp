
#include "liste.h"
#include <iostream>

using namespace std;

// ===== Creazione e controllo =====

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

// ===== Ricerca =====

Node_t *trovaNodoPrecedente( Node_t *head, int posizione ) {

    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = head;
    int indicePosizione = 0;

    while ( pTmp->next != nullptr && indicePosizione < ( posizione - 1 ) ) {
        pTmp = pTmp->next;
        indicePosizione++;
    }

    return pTmp;
}

Node_t *trovaUltimoNodo( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = head;

    while ( pTmp->next != nullptr ) {
        pTmp = pTmp->next;
    }

    return pTmp;
}

Node_t *trovaPenultimoNodo( Node_t *head ) {
    
    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    // Lista composta da 1 nodo
    if ( head->next == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = head;

    while ( pTmp->next->next != nullptr ) {
        pTmp = pTmp->next;
    }

    return pTmp;
}

bool cercaElemento( Node_t *head, int elemento ) {

    // Lista vuota
    if ( head == nullptr ) {
        return false;
    }

    Node_t *pTmp = head;

    while ( pTmp != nullptr ) {
        if ( pTmp->info == elemento ) {
            return true;
        }

        pTmp = pTmp->next;
    }

    return false;
}

// ===== Inserimento =====

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

// ===== Rimozione =====

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

// ===== Cancellazione =====

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

    while ( ( *phead ) != nullptr ) {
        cancellaNodoInTesta( phead );
    }
}

// ===== Copia =====

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

// ===== Stampa =====

void stampaListaTesta_Fine( Node_t *head ) {

    Node_t *pTmp = head;

    while ( pTmp != nullptr ) {
        cout << pTmp->info << endl;

        pTmp = pTmp->next;
    }
}

void stampaListaFine_Testa( Node_t *head ) {
    
    // Caso lista vuota
    if ( head == nullptr ) {
        return;
    }

    stampaListaFine_Testa( head->next );
    cout << head->info << endl;
}

// ===== Statistiche =====

int contaNodi( Node_t *head ) {

    if ( head == nullptr ) {
        return 0;
    }

    Node_t *pTmp = head;
    int contatore = 0;

    while ( pTmp != nullptr ) {
        contatore++;

        pTmp = pTmp->next;
    }

    return contatore;
}

int sommaNodi( Node_t *head ) {

    if ( head == nullptr ) {
        return 0;
    }

    Node_t *pTmp = head;
    int somma = 0;

    while ( pTmp != nullptr ) {
        somma += pTmp->info;

        pTmp = pTmp->next;
    }

    return somma;
}

// ===== Ordinamento e inversione =====

void ordinaLista( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return;
    }

    // Lista composta da 1 nodo
    if ( ( *phead )->next == nullptr ) {
        return;
    }

    Node_t *a;
    Node_t *b;
    Node_t *pPrec;
    bool scambiato;

    do {
        scambiato = false;
        pPrec = nullptr;
        a = ( *phead );

        // Mi fermo sull'ultimo nodo: b = a->next deve esistere
        while ( a->next != nullptr ) {
            b = a->next; 

            if ( a->info > b->info ) {
                // Scambio
                a->next = b->next;
                b->next = a;

                if ( pPrec == nullptr ) {
                    ( *phead ) = b;
                }
                else {
                    pPrec->next = b;
                }

                scambiato = true;

                pPrec = b;
            }
            else {
                pPrec = a;
                a = a->next;
            }
        }
    } while ( scambiato );
}

void invertiLista( Node_t **phead ) {

    // Caso lista vuota e caso 1 nodo
    if ( ( *phead ) == nullptr || ( *phead )->next == nullptr ) {
        return;
    }

    // Per ogni nodo inverto la direzione del suo next
    Node_t *curr = ( *phead );
    Node_t *prev = nullptr;
    Node_t *next;                   // Punta al successivo prima di sovrascrivere next

    while ( curr != nullptr ) {
        // Salvo il successivo
        next = curr->next;

        // Giro il collegamento
        curr->next = prev;

        // Porto avanti i puntatori
        prev = curr;
        curr = next;
    }

    ( *phead ) = prev;
}

// ===== Operazioni fra liste =====

Node_t *unioneListaNRD( Node_t *head1, Node_t *head2 ) {

    Node_t *copia1 = copiaLista( head1 );
    Node_t *copia2 = copiaLista( head2 );

    // Se la prima è vuota, l'unione è solo la seconda (anche se vuota)
    if ( copia1 == nullptr ) {
        return copia2;
    }

    trovaUltimoNodo( copia1 )->next = copia2;

    return copia1;
}

Node_t *unioneListaRD( Node_t *head1, Node_t *head2 ) {
    
    Node_t *listaUnione = nullptr;
    Node_t *pNodoCreato;

    for ( Node_t *p = head1; p != nullptr; p = p->next ) {
        if ( !cercaElemento( listaUnione, p->info ) ) {
            pNodoCreato = creaNodo( p->info );

            // Accoda una copia di valore in coda, solo se non è già presente
            aggiungiNodoInCoda( &listaUnione, pNodoCreato );
        }
    }

    for ( Node_t *p = head2; p != nullptr; p = p->next ) {
        if ( !cercaElemento( listaUnione, p->info ) ) {
            pNodoCreato = creaNodo( p->info );

            aggiungiNodoInCoda( &listaUnione, pNodoCreato );
        }
    }

    return listaUnione;
}

Node_t *intersezioneListe( Node_t *head1, Node_t *head2 ) {
    
    Node_t *listaIntersezione = nullptr;
    Node_t *pNodoCreato;

    for ( Node_t *p = head1; p != nullptr; p = p->next ) {
        // Accoda una copia di valore in coda, solo se non è già presente
        if ( !cercaElemento( listaIntersezione, p->info ) && cercaElemento( head2, p->info ) ) {
            pNodoCreato = creaNodo( p->info );

            aggiungiNodoInCoda( &listaIntersezione, pNodoCreato );
        }
    }

    return listaIntersezione;
}