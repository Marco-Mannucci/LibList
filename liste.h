
#ifndef LISTE_H
#define LISTE_H

#include "listeTypes.h"

/*
Le funzioni che servono per gestire una lista:

- Creazione e controllo:
Crea lista vuota
Crea nodo
Check lista vuota

- Ricerca:
Trova nodo precedente
Trova ultimo nodo
Trova penultimo nodo
Cerca elemento

- Inserimento:
Aggiungi nodo in testa
Aggiungi nodo in coda
Aggiungi nodo in posizione x
Inserimento ordinato

- Rimozione ( il nodo viene scollegato dalla lista ma non eliminato ):
Rimuovi nodo in testa
Rimuovi nodo in coda
Rimuovi nodo in posizione x

- Cancellazione ( il nodo viene scollegato ed eliminato ):
Cancella nodo in testa
Cancella nodo in coda
Cancella nodo in posizione x

Distruggi lista

- Copia:
Copia lista
Rimuovi duplicati

- Stampa:
Stampa lista, dal primo elemento
Stampa lista, dall'ultimo elemento ( ricorsiva poiché, per la versione iterativa avrei dovuto 
                                    invertire temporaneamente i collegamenti dei nodi, stampare la lista e poi ripristinarla.)

- Statistiche:
Conta nodi
Somma contenuto nodi

- Ordinamento e inversione:
Ordina lista ( in base hai valori del campo info ( dal più piccolo al più grande ) )
Inverti lista

- Operazioni fra liste:
Unione lista NRD ( restituisce una lista che unisce due liste, concatenazione ( non rimuove i duplicati ) )
Unione lista RD ( come NRD ma rimuove i duplicati )
Intersezione fra liste ( restituisce una lista con i nodi in comune fra due liste )

*/

// ##################### LISTE SEMPLICI #####################
// ===== Creazione e controllo =====
Node_t *creaLista();
Node_t *creaNodo( int info );
bool checkListaVuota( Node_t *head );

// ===== Ricerca =====
Node_t *trovaNodoPrecedente( Node_t *head, int posizione );
Node_t *trovaUltimoNodo( Node_t *head );
Node_t *trovaPenultimoNodo( Node_t *head );
bool cercaElemento( Node_t *head, int elemento );

// ===== Inserimento =====
void aggiungiNodoInTesta( Node_t **phead, Node_t *pAux );
void aggiungiNodoInCoda( Node_t **phead, Node_t *pAux );
void aggiungiNodoInPosizione( Node_t **phead, Node_t *pAux, int posizione );
void inserimentoOrdinato( Node_t **phead, Node_t *pAux );

// ===== Rimozione =====
// Restituiscono il nodo rimosso
Node_t *rimuoviNodoInTesta( Node_t **phead );
Node_t *rimuoviNodoInCoda( Node_t **phead );
Node_t *rimuoviNodoInPosizione( Node_t **phead, int posizione );

// ===== Cancellazione =====
void cancellaNodoInTesta( Node_t **phead );
void cancellaNodoInCoda( Node_t **phead );
void cancellaNodoInPosizione( Node_t **phead, int posizione );

void distruggiLista( Node_t **phead );

// ===== Copia =====
Node_t *copiaLista( Node_t *pListaDaCopiare );
bool rimuoviDuplicati( Node_t **phead );

// ===== Stampa =====
void stampaListaTesta_Fine( Node_t *head );
void stampaListaFine_Testa( Node_t *head );

// ===== Statistiche =====
int contaNodi( Node_t *head );
int sommaNodi( Node_t *head );

// ===== Ordinamento e inversione =====
void ordinaLista( Node_t **phead );
void invertiLista( Node_t **phead );

// ===== Operazioni fra liste =====
Node_t *unioneListaNRD( Node_t *head1, Node_t *head2 );
Node_t *unioneListaRD( Node_t *head1, Node_t *head2 );
Node_t *intersezioneListe( Node_t *head1, Node_t *head2 );


// ##################### LISTE CIRCOLARI #####################
// ( creaLista, creaNodo e checkListaVuota sono le stesse delle liste semplici )

// ===== Ricerca =====
Node_t *trovaNodoPrecedenteCirc( Node_t *head, int posizione );
Node_t *trovaUltimoNodoCirc( Node_t *head );
Node_t *trovaPenultimoNodoCirc( Node_t *head );
bool cercaElementoCirc( Node_t *head, int elemento );

// ===== Inserimento =====
void aggiungiNodoInTestaCirc( Node_t **phead, Node_t *pAux );
void aggiungiNodoInCodaCirc( Node_t **phead, Node_t *pAux );
void aggiungiNodoInPosizioneCirc( Node_t **phead, Node_t *pAux, int posizione );
void inserimentoOrdinatoCirc( Node_t **phead, Node_t *pAux );

// ===== Rimozione =====
// Restituiscono il nodo rimosso
Node_t *rimuoviNodoInTestaCirc( Node_t **phead );
Node_t *rimuoviNodoInCodaCirc( Node_t **phead );
Node_t *rimuoviNodoInPosizioneCirc( Node_t **phead, int posizione );

// ===== Cancellazione =====
void cancellaNodoInTestaCirc( Node_t **phead );
void cancellaNodoInCodaCirc( Node_t **phead );
void cancellaNodoInPosizioneCirc( Node_t **phead, int posizione );

void distruggiListaCirc( Node_t **phead );

// ===== Copia =====
Node_t *copiaListaCirc( Node_t *pListaDaCopiare );
bool rimuoviDuplicatiCirc( Node_t **phead );

// ===== Stampa =====
void stampaListaTesta_FineCirc( Node_t *head );
void stampaListaFine_TestaCirc( Node_t *head );
void stampaListaFine_TestaRicCirc( Node_t *pCurr, Node_t *head );

// ===== Statistiche =====
int contaNodiCirc( Node_t *head );
int sommaNodiCirc( Node_t *head );

// ===== Ordinamento e inversione =====
void ordinaListaCirc( Node_t **phead );
void invertiListaCirc( Node_t **phead );

// ===== Operazioni fra liste =====
Node_t *unioneListaNRDCirc( Node_t *head1, Node_t *head2 );
Node_t *unioneListaRDCirc( Node_t *head1, Node_t *head2 );
Node_t *intersezioneListeCirc( Node_t *head1, Node_t *head2 );

#endif // LISTE_H