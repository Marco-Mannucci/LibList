
#ifndef LISTE_H
#define LISTE_H

#include "listeTypes.h"

/*
Le funzioni che servono per gestire una lista:
Crea lista vuota
Crea nodo
Check lista vuota
Copia lista
Rimuovi duplicati

Aggiungi nodo in testa
Aggiungi nodo in coda
Aggiungi nodo in posizione x
Inserimento ordinato

Rimuovi nodo in testa
Rimuovi nodo in coda
Rimuovi nodo in posizione x

Cancella nodo in testa
Cancella nodo in coda
Cancella nodo in posizione x

Distruggi lista

Stampa lista, dal primo elemento
Stampa lista, dall'ultimo elemento

Conta nodi
Somma contenuto nodi

Trova nodo precedente
Trova ultimo nodo
Trova penultimo nodo

Cerca elemento

Ordina lista ( in base hai valori del campo info ( dal più piccolo al più grande ) )
Inverti lista
Unione lista ( restituisce una lista che unisce due liste )
Intersezione fra liste ( restituisce una lista con i nodi in comune fra due liste )

e le loro ricorsive
*/

Node_t *creaLista();
Node_t *creaNodo( int info );
bool checkListaVuota( Node_t *head );
Node_t *copiaLista( Node_t *pListaDaCopiare );
bool rimuoviDuplicati( Node_t **phead );

void aggiungiNodoInTesta( Node_t **phead, Node_t *pAux );
void aggiungiNodoInCoda( Node_t **phead, Node_t *pAux );
void aggiungiNodoInPosizione( Node_t **phead, Node_t *pAux, int posizione );
void inserimentoOrdinato( Node_t **phead, Node_t *pAux );

// Restituiscono il nodo rimosso
Node_t *rimuoviNodoInTesta( Node_t **phead, Node_t *pAux );
Node_t *rimuoviNodoInCosa( Node_t **phead, Node_t *pAux );
Node_t *rimuoviNodoInPosizione( Node_t **phead, Node_t *pAux, int posizione );

void cancellaNodoInTesta( Node_t **phead, Node_t *pAux );
void cancellaNodoInCosa( Node_t **phead, Node_t *pAux );
void cancellaNodoInPosizione( Node_t **phead, Node_t *pAux, int posizione );

void distruggiLista( Node_t **phead );

void stampaListaTesta_Fine( Node_t *head );
void stampaListaFine_Testa( Node_t *head );

int contaNodi( Node_t *head );
float sommaNodi( Node_t *head );

Node_t *trovaNodoPrecedente( Node_t *head, int posizione );
Node_t *trovaUltimoNodo( Node_t *head );
Node_t *trovaPenultimoNodo( Node_t *head, int posizione );

int cercaElemento( Node_t *head );

void ordinaLista( Node_t **phead );
void invertiLista( Node_t **phead );
Node_t *unioneLista( Node_t *head1, Node_t *head_2 );
Node_t *intersezioneListe( Node_t *head1, Node_t *head_2 );

#endif