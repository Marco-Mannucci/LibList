
#include "liste.h"
#include <iostream>

using namespace std;

// ===== Ricerca =====

// Restituisce il nodo in posizione ( posizione - 1 ), oppure l'ultimo se la lista è più corta
Node_t *trovaNodoPrecedenteCirc( Node_t *head, int posizione ) {

    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = head;
    int indicePosizione = 0;

    while ( pTmp->next != head && indicePosizione < ( posizione - 1 ) ) {
        pTmp = pTmp->next;
        indicePosizione++;
    }

    return pTmp;
}

Node_t *trovaUltimoNodoCirc( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = head;

    // L'ultimo nodo è quello che punta a head
    while ( pTmp->next != head ) {
        pTmp = pTmp->next;
    }

    return pTmp;
}

Node_t *trovaPenultimoNodoCirc( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return nullptr;
    }

    // Lista di 1 nodo
    if ( head->next == head ) {
        return nullptr;
    }

    Node_t *pTmp = head;

    while ( pTmp->next->next != head ) {
        pTmp = pTmp->next;
    }

    return pTmp;
}

bool cercaElementoCirc( Node_t *head, int elemento ) {

    // Lista vuota
    if ( head == nullptr ) {
        return false;
    }

    Node_t *pTmp = head;

    // Do-while: il primo nodo è già head, quindi devo guardarlo prima di controllare la fine
    do {
        if ( pTmp->info == elemento ) {
            return true;
        }

        pTmp = pTmp->next;
    } while ( pTmp != head );

    return false;
}

// ===== Inserimento =====

void aggiungiNodoInTestaCirc( Node_t **phead, Node_t *pAux ) {

    // Lista vuota: l'unico nodo punta a sé stesso
    if ( ( *phead ) == nullptr ) {
        pAux->next = pAux;
    }
    else {
        // L'ultimo nodo deve puntare al nuovo head
        Node_t *pUltimo = trovaUltimoNodoCirc( ( *phead ) );

        pAux->next = ( *phead );
        pUltimo->next = pAux;
    }

    ( *phead ) = pAux;
}

void aggiungiNodoInCodaCirc( Node_t **phead, Node_t *pAux ) {

    // Lista vuota: l'unico nodo punta a sé stesso
    if ( ( *phead ) == nullptr ) {
        pAux->next = pAux;
        ( *phead ) = pAux;
    }
    else {
        Node_t *pUltimo = trovaUltimoNodoCirc( ( *phead ) );

        pUltimo->next = pAux;
        pAux->next = ( *phead );
    }
}

void aggiungiNodoInPosizioneCirc( Node_t **phead, Node_t *pAux, int posizione ) {

    // Lista vuota e posizione 0
    if ( ( *phead ) == nullptr || posizione == 0 ) {
        aggiungiNodoInTestaCirc( phead, pAux );
    }
    else {
        Node_t *pTmp = trovaNodoPrecedenteCirc( ( *phead ), posizione );

        pAux->next = pTmp->next;
        pTmp->next = pAux;
    }
}

void inserimentoOrdinatoCirc( Node_t **phead, Node_t *pAux ) {

    // Se due nodi hanno lo stesso valore il nodo da inserire lo inserisco prima
    if ( ( *phead ) == nullptr || ( *phead )->info >= pAux->info ) {
        aggiungiNodoInTestaCirc( phead, pAux );
    }
    else {
        Node_t *pTmp = ( *phead );

        while ( pTmp->next != ( *phead ) && pTmp->next->info < pAux->info ) {
            pTmp = pTmp->next;
        }

        pAux->next = pTmp->next;
        pTmp->next = pAux;
    }
}

// ===== Rimozione =====

Node_t *rimuoviNodoInTestaCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = ( *phead );

    // Lista di 1 nodo
    if ( pTmp->next == pTmp ) {
        ( *phead ) = nullptr;
    }
    else {
        // L'ultimo nodo deve puntare al nuovo head
        Node_t *pUltimo = trovaUltimoNodoCirc( ( *phead ) );

        ( *phead ) = pTmp->next;
        pUltimo->next = ( *phead );
    }

    // Il nodo rimosso non deve più puntare alla lista
    pTmp->next = nullptr;

    return pTmp;
}

Node_t *rimuoviNodoInCodaCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp;

    // Lista di 1 nodo
    if ( ( *phead )->next == ( *phead ) ) {
        pTmp = ( *phead );
        ( *phead ) = nullptr;
    }
    else {
        pTmp = trovaUltimoNodoCirc( ( *phead ) );
        Node_t *pPenultimo = trovaPenultimoNodoCirc( ( *phead ) );

        // Il penultimo diventa l'ultimo: chiude il cerchio su head
        pPenultimo->next = ( *phead );
    }

    // Il nodo rimosso non deve più puntare alla lista
    pTmp->next = nullptr;

    return pTmp;
}

Node_t *rimuoviNodoInPosizioneCirc( Node_t **phead, int posizione ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return nullptr;
    }

    Node_t *pTmp = ( *phead );
    Node_t *pNodoDaRimuovere;
    int indicePosizione = 0;

    if ( posizione == 0 ) {
        return rimuoviNodoInTestaCirc( phead );
    }

    while ( pTmp->next != ( *phead ) && indicePosizione < ( posizione - 1 ) ) {
        pTmp = pTmp->next;
        indicePosizione++;
    }

    // Se esco per posizione troppo grande rimuovo in coda
    if ( pTmp->next == ( *phead ) ) {
        pNodoDaRimuovere = rimuoviNodoInCodaCirc( phead );
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

void cancellaNodoInTestaCirc( Node_t **phead ) {

    Node_t *pTmp = rimuoviNodoInTestaCirc( phead );

    delete pTmp;
}

void cancellaNodoInCodaCirc( Node_t **phead ) {

    Node_t *pTmp = rimuoviNodoInCodaCirc( phead );

    delete pTmp;
}

void cancellaNodoInPosizioneCirc( Node_t **phead, int posizione ) {

    Node_t *pTmp = rimuoviNodoInPosizioneCirc( phead, posizione );

    delete pTmp;
}

void distruggiListaCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return;
    }

    // Spezzo il cerchio: da qui in poi è una lista semplice
    trovaUltimoNodoCirc( ( *phead ) )->next = nullptr;

    distruggiLista( phead );
}

// ===== Copia =====

Node_t *copiaListaCirc( Node_t *pListaDaCopiare ) {

    Node_t *newHead = creaLista();
    Node_t *pTmp = pListaDaCopiare;
    Node_t *nodoDaCopiare;

    // Lista vuota
    if ( pListaDaCopiare == nullptr ) {
        return newHead;
    }

    do {
        nodoDaCopiare = creaNodo( pTmp->info );

        aggiungiNodoInCodaCirc( &newHead, nodoDaCopiare );

        pTmp = pTmp->next;
    } while ( pTmp != pListaDaCopiare );

    return newHead;
}

bool rimuoviDuplicatiCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return false;
    }

    Node_t *pCurr = ( *phead );
    Node_t *pCheck;

    do {
        pCheck = pCurr;

        // Mi fermo prima di head: head non può mai essere un duplicato
        while ( pCheck->next != ( *phead ) ) {
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
    } while ( pCurr != ( *phead ) );

    return true;
}

// ===== Stampa =====

void stampaListaTesta_FineCirc( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return;
    }

    Node_t *pTmp = head;

    do {
        cout << pTmp->info << endl;

        pTmp = pTmp->next;
    } while ( pTmp != head );
}

// Serve head come secondo parametro: nella lista circolare non c'è nullptr che dice quando fermarsi
void stampaListaFine_TestaRicCirc( Node_t *pCurr, Node_t *head ) {

    // Se non sono sull'ultimo nodo scendo prima di stampare
    if ( pCurr->next != head ) {
        stampaListaFine_TestaRicCirc( pCurr->next, head );
    }

    cout << pCurr->info << endl;
}

void stampaListaFine_TestaCirc( Node_t *head ) {

    // Caso lista vuota
    if ( head == nullptr ) {
        return;
    }

    stampaListaFine_TestaRicCirc( head, head );
}

// ===== Statistiche =====

int contaNodiCirc( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return 0;
    }

    Node_t *pTmp = head;
    int contatore = 0;

    do {
        contatore++;

        pTmp = pTmp->next;
    } while ( pTmp != head );

    return contatore;
}

int sommaNodiCirc( Node_t *head ) {

    // Lista vuota
    if ( head == nullptr ) {
        return 0;
    }

    Node_t *pTmp = head;
    int somma = 0;

    do {
        somma += pTmp->info;

        pTmp = pTmp->next;
    } while ( pTmp != head );

    return somma;
}

// ===== Ordinamento e inversione =====

void ordinaListaCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return;
    }

    // Spezzo il cerchio: da qui in poi è una lista semplice
    trovaUltimoNodoCirc( ( *phead ) )->next = nullptr;

    ordinaLista( phead );

    // Richiudo il cerchio: l'head può essere cambiato, quindi cerco di nuovo l'ultimo
    trovaUltimoNodo( ( *phead ) )->next = ( *phead );
}

void invertiListaCirc( Node_t **phead ) {

    // Lista vuota
    if ( ( *phead ) == nullptr ) {
        return;
    }

    // Per ogni nodo inverto la direzione del suo next
    Node_t *curr = ( *phead );
    Node_t *prev = trovaUltimoNodoCirc( ( *phead ) );   // Il vecchio head punterà all'ultimo nodo: il cerchio resta chiuso
    Node_t *next;                                       // Punta al successivo prima di sovrascrivere next

    do {
        // Salvo il successivo
        next = curr->next;

        // Giro il collegamento
        curr->next = prev;

        // Porto avanti i puntatori
        prev = curr;
        curr = next;
    } while ( curr != ( *phead ) );

    ( *phead ) = prev;
}

// ===== Operazioni fra liste =====

Node_t *unioneListaNRDCirc( Node_t *head1, Node_t *head2 ) {

    Node_t *copia1 = copiaListaCirc( head1 );
    Node_t *copia2 = copiaListaCirc( head2 );

    // Se una delle due è vuota, l'unione è solo l'altra ( anche se vuota )
    if ( copia1 == nullptr ) {
        return copia2;
    }

    if ( copia2 == nullptr ) {
        return copia1;
    }

    Node_t *pUltimo1 = trovaUltimoNodoCirc( copia1 );
    Node_t *pUltimo2 = trovaUltimoNodoCirc( copia2 );

    // L'ultimo della prima va sulla seconda, l'ultimo della seconda chiude il cerchio sulla prima
    pUltimo1->next = copia2;
    pUltimo2->next = copia1;

    return copia1;
}

Node_t *unioneListaRDCirc( Node_t *head1, Node_t *head2 ) {

    Node_t *listaUnione = nullptr;
    Node_t *pNodoCreato;
    Node_t *p;

    if ( head1 != nullptr ) {
        p = head1;

        do {
            // Copio i valori di head1 non ancora presenti nel risultato
            if ( !cercaElementoCirc( listaUnione, p->info ) ) {
                pNodoCreato = creaNodo( p->info );

                aggiungiNodoInCodaCirc( &listaUnione, pNodoCreato );
            }

            p = p->next;
        } while ( p != head1 );
    }

    if ( head2 != nullptr ) {
        p = head2;

        do {
            // Stesso procedimento con head2
            if ( !cercaElementoCirc( listaUnione, p->info ) ) {
                pNodoCreato = creaNodo( p->info );

                aggiungiNodoInCodaCirc( &listaUnione, pNodoCreato );
            }

            p = p->next;
        } while ( p != head2 );
    }

    return listaUnione;
}

Node_t *intersezioneListeCirc( Node_t *head1, Node_t *head2 ) {

    Node_t *listaIntersezione = nullptr;
    Node_t *pNodoCreato;
    Node_t *p;

    // Se head1 è vuota l'intersezione è vuota
    if ( head1 != nullptr ) {
        p = head1;

        do {
            // Valore presente in head2 e non ancora nel risultato
            if ( !cercaElementoCirc( listaIntersezione, p->info ) && cercaElementoCirc( head2, p->info ) ) {
                pNodoCreato = creaNodo( p->info );

                aggiungiNodoInCodaCirc( &listaIntersezione, pNodoCreato );
            }

            p = p->next;
        } while ( p != head1 );
    }

    return listaIntersezione;
}