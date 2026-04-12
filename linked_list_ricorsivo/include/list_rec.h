#ifndef LIST_REC_H
#define LIST_REC_H

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

_Bool addNode(ListNodePtr* l, int n);

ListNodePtr mkListv(int count, ...);

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_rec(int m, int n);

//VERSIONE ricorsiva di coda
ListNodePtr fromTo(int m, int n);

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2);

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_rec(ListNodePtr ls);

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi corrispondenti di due liste @ls1 e @ls2 
// di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2);

// VERSIONE ricorsiva di coda
ListNodePtr zipSum(ListNodePtr ls1, ListNodePtr ls2);

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_rec(ListNodePtr ls, int x);

//VERSIONE ricorsiva di coda
int occurrences(ListNodePtr ls, int x);

// Toglie tutte le occorrenze di @x dalla lista *@p_ls (modifica *@p_ls).
void remove_all_rec(ListNodePtr *p_ls, int x);

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_rec(ListNodePtr ls);

#endif
