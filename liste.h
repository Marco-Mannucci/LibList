
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
Stampa lista, dall'ultimo elemento ( ricorsiva poiché, per la versione iterativa avrei dovuto 
                                    invertire temporaneamente i collegamenti dei nodi, stampare la lista e poi ripristinarla.)

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
Node_t *rimuoviNodoInTesta( Node_t **phead );
Node_t *rimuoviNodoInCoda( Node_t **phead );
Node_t *rimuoviNodoInPosizione( Node_t **phead, int posizione );

void cancellaNodoInTesta( Node_t **phead );
void cancellaNodoInCoda( Node_t **phead );
void cancellaNodoInPosizione( Node_t **phead, int posizione );

void distruggiLista( Node_t **phead );

Node_t *trovaNodoPrecedente( Node_t *head, int posizione );
Node_t *trovaUltimoNodo( Node_t *head );
Node_t *trovaPenultimoNodo( Node_t *head );

bool cercaElemento( Node_t *head, int elemento );

void ordinaLista( Node_t **phead );

void stampaListaTesta_Fine( Node_t *head );
void stampaListaFine_Testa( Node_t *head );

int contaNodi( Node_t *head );
int sommaNodi( Node_t * head);

void invertiLista( Node_t **phead );
Node_t *unioneLista( Node_t *head1, Node_t *head_2 );
Node_t *intersezioneListe( Node_t *head1, Node_t *head_2 );

#endif