# Libreria per liste in C++

Libreria in C++ per la gestione di **liste concatenate semplici** e **liste circolari**, scritta a scopo didattico. Ogni operazione è implementata in modo iterativo (tranne la stampa inversa, che è ricorsiva) usando solo i costrutti visti a lezione: puntatori, doppi puntatori, allocazione dinamica con `new` e `delete`.

## Indice

- [Caratteristiche](#caratteristiche)
- [Struttura del progetto](#struttura-del-progetto)
- [Il tipo nodo](#il-tipo-nodo)
- [Compilazione](#compilazione)
- [Esempio d'uso](#esempio-duso)
- [Funzioni disponibili](#funzioni-disponibili)
- [Convenzioni](#convenzioni)
- [Gestione della memoria](#gestione-della-memoria)
- [Autore](#autore)
- [Licenza](#licenza)

## Caratteristiche

- Creazione, controllo e distruzione di una lista
- Inserimento in testa, in coda, in posizione e ordinato
- Rimozione (il nodo viene scollegato) e cancellazione (il nodo viene scollegato ed eliminato)
- Ricerca di un elemento, del nodo precedente, dell'ultimo e del penultimo nodo
- Copia di una lista e rimozione dei duplicati
- Stampa dal primo all'ultimo elemento e viceversa (versione ricorsiva)
- Conteggio dei nodi e somma dei valori
- Ordinamento (bubble sort sui collegamenti) e inversione
- Unione (con e senza duplicati) e intersezione fra due liste
- Stesso insieme di funzioni per le **liste circolari**, con suffisso `Circ`

## Struttura del progetto

```
.
├── listeTypes.h          # Definizione del tipo Node_t
├── liste.h               # Prototipi delle funzioni (liste semplici e circolari)
├── liste.cpp             # Implementazione per liste semplici
├── listeCircolari.cpp    # Implementazione per liste circolari
├── LICENSE
└── README.md
```

## Il tipo nodo

Ogni nodo contiene un intero e il puntatore al nodo successivo:

```cpp
typedef struct Node {
    int info;
    struct Node *next;
} Node_t;
```

## Compilazione

Serve un compilatore con supporto a C++11 o successivo. Con `g++`:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp liste.cpp listeCircolari.cpp -o liste
```

`main.cpp` è il tuo programma che include `liste.h`.

## Esempio d'uso

```cpp
#include "liste.h"

int main() {

    Node_t *head = creaLista();

    aggiungiNodoInCoda( &head, creaNodo( 3 ) );
    aggiungiNodoInCoda( &head, creaNodo( 1 ) );
    aggiungiNodoInTesta( &head, creaNodo( 7 ) );        // 7 -> 3 -> 1

    ordinaLista( &head );                               // 1 -> 3 -> 7
    stampaListaTesta_Fine( head );

    distruggiLista( &head );                            // head torna nullptr

    return 0;
}
```

## Funzioni disponibili

Le funzioni per le liste circolari hanno lo stesso nome e gli stessi parametri di quelle semplici, con il suffisso `Circ` (esempio: `contaNodi` e `contaNodiCirc`).
`creaLista`, `creaNodo` e `checkListaVuota` valgono per entrambi i tipi di lista.

### Creazione e controllo

| Funzione | Descrizione |
|---|---|
| `creaLista` | Restituisce una lista vuota (`nullptr`) |
| `creaNodo` | Alloca un nodo con il valore dato e `next = nullptr` |
| `checkListaVuota` | Dice se la lista è vuota |

### Ricerca

| Funzione | Descrizione |
|---|---|
| `trovaNodoPrecedente` | Restituisce il nodo in posizione `posizione - 1` (o l'ultimo se la lista è più corta) |
| `trovaUltimoNodo` | Restituisce l'ultimo nodo |
| `trovaPenultimoNodo` | Restituisce il penultimo nodo (`nullptr` con meno di 2 nodi) |
| `cercaElemento` | Dice se un valore è presente nella lista |

### Inserimento

| Funzione | Descrizione |
|---|---|
| `aggiungiNodoInTesta` | Inserisce un nodo all'inizio |
| `aggiungiNodoInCoda` | Inserisce un nodo alla fine |
| `aggiungiNodoInPosizione` | Inserisce un nodo nella posizione indicata |
| `inserimentoOrdinato` | Inserisce un nodo mantenendo la lista ordinata (a parità di valore, prima degli uguali) |

### Rimozione e cancellazione

| Funzione | Descrizione |
|---|---|
| `rimuoviNodoInTesta` / `InCoda` / `InPosizione` | Scollegano il nodo dalla lista e lo **restituiscono** |
| `cancellaNodoInTesta` / `InCoda` / `InPosizione` | Scollegano il nodo e lo **eliminano** con `delete` |
| `distruggiLista` | Elimina tutti i nodi e riporta la testa a `nullptr` |

### Copia e duplicati

| Funzione | Descrizione |
|---|---|
| `copiaLista` | Restituisce una nuova lista con nodi nuovi e gli stessi valori |
| `rimuoviDuplicati` | Elimina i nodi con valore già presente, tenendo il primo |

### Stampa

| Funzione | Descrizione |
|---|---|
| `stampaListaTesta_Fine` | Stampa dal primo all'ultimo elemento |
| `stampaListaFine_Testa` | Stampa dall'ultimo al primo elemento, in modo ricorsivo |

La versione ricorsiva evita di dover invertire temporaneamente i collegamenti per poi ripristinarli.
Nelle liste circolari serve una funzione di appoggio (`stampaListaFine_TestaRicCirc`), perché senza `nullptr` la ricorsione ha bisogno di `head` per sapere dove fermarsi.

### Statistiche

| Funzione | Descrizione |
|---|---|
| `contaNodi` | Numero di nodi |
| `sommaNodi` | Somma dei valori dei nodi |

### Ordinamento e inversione

| Funzione | Descrizione |
|---|---|
| `ordinaLista` | Ordina in modo crescente rispetto al campo `info` |
| `invertiLista` | Inverte la lista in un solo passaggio, girando il `next` di ogni nodo |

### Operazioni fra liste

Tutte restituiscono una **lista nuova**, con nodi creati ad hoc: le liste di partenza non vengono modificate.

| Funzione | Descrizione |
|---|---|
| `unioneListaNRD` | Unione senza rimozione dei duplicati (concatenazione) |
| `unioneListaRD` | Unione con rimozione dei duplicati |
| `intersezioneListe` | Valori presenti in entrambe le liste, senza duplicati |

## Convenzioni

**Liste semplici**

- Lista vuota: `head == nullptr`
- Ultimo nodo: `next == nullptr`

**Liste circolari**

- Lista vuota: `head == nullptr`
- Lista di un nodo: `head->next == head`
- Ultimo nodo: `next == head`
- Dopo ogni funzione la lista resta chiusa a cerchio

Le funzioni che modificano la testa ricevono un doppio puntatore (`Node_t **phead`), così il chiamante vede l'aggiornamento.

Non vanno mai mescolati i due tipi: passare una lista circolare a una funzione per liste semplici (o il contrario) provoca un ciclo infinito.

## Gestione della memoria

- I nodi vengono allocati con `new` in `creaNodo`.
- Le funzioni `rimuovi...` non liberano memoria: chi le chiama è responsabile del nodo restituito.
- Le liste restituite da `copiaLista`, `unioneLista...` e `intersezioneListe` vanno liberate con `distruggiLista` (o `distruggiListaCirc`).

## Autore

Marco Mannucci

## Licenza

Distribuito con licenza MIT. Vedi il file [LICENSE](LICENSE).
