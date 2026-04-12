#ifndef LIST_ITER_H
#define LIST_ITER_H

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
    int data;
    ListNodePtr next;
};

// Include addizionali
#include <stdbool.h>

// Funzioni ausiliarie

// @brief: visita ogni nodo della lista e stampa il suo contenuto
// @param list: puntatore alla testa della lista
void printList(ListNodePtr list);

// @brief: Crea una nuova lista creando il primo nodo e inzializza il suo valore a value
// @param value: valore con cui inizializzare il nodo
// @return: restituisce un puntatore alla testa della lista creata
ListNodePtr listInit(int value);

// @brief: Aggiunge in coda il nodo di valore value
// @param list: indirizzo alla testa della lista
// @param value: valore con cui inizializzare il nodo da aggiungere
// @return bool: true se il nodo è stato correttamente aggiunto, false altrimenti
bool listAppendNode(ListNodePtr list, int value);

// @brief: Aggiunge in testa il nodo di valore value
// @param list: indirizzo alla testa della lista
// @param value: valore con cui inizializzare il nodo da aggiungere
// @return bool: true se il nodo è stato correttamente aggiunto, false altrimenti
bool listPrependNode(ListNodePtr* list, int value);

// @brief: Aggiunge un nodo dopo quello indicato dal position
// @param list: puntatore alla testa della lista
// @param position: puntatore al nodo dopo il quale inserire il nuovo nodo
// @param value: valore con cui inizializzare il nuovo nodo
// @return bool: 1 se il nodo è stato correttamente inserito, 0 altrimenti
bool listInsertAfter(ListNodePtr* list, ListNodePtr position, int value);

// Funzioni da implementare

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n, estremi inclusi.
ListNodePtr fromTo_iter(int m, int n);

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso ordine anche nella lista @ls2.
bool included_iter(ListNodePtr ls1, ListNodePtr ls2);

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls);

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2);

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x);

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x);

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_iter(ListNodePtr *ls);

#endif
