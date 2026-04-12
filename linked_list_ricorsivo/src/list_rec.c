#include <stdlib.h>
#include <stdarg.h>

#include "../include/list_rec.h"

_Bool addNode(ListNodePtr* l, int n)
{
    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return 0;
    newNode->data = n;
    newNode->next = 0;
    if(*l == NULL) {
        *l = newNode;
        return 1;
    } else {
        ListNodePtr currentNode = *l;
        ListNodePtr prevNode = NULL;
        while(currentNode) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = newNode;
        return 1;
    }
}

ListNodePtr mkListv(int count, ...)
{
    ListNodePtr l = NULL;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        addNode(&l, num);
    }
    va_end(args);
    return l;
}

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n, estremi inclusi.
ListNodePtr fromTo_rec(int m, int n)
{
    if(m > n) return NULL;
    ListNodePtr currentNode = malloc(sizeof(ListNode));
    if(currentNode == NULL) return NULL;
    currentNode->data = m;
    currentNode->next = fromTo_rec(m + 1, n);
    return currentNode;
}

ListNodePtr fromToAux(int m, int n, ListNodePtr l)
{
    if(n < m) return l;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return NULL;

    newNode->data = n;
    newNode->next = l;

    return fromToAux(m, n - 1, newNode);
}

//VERSIONE ricorsiva di coda
ListNodePtr fromTo(int m, int n)
{
    if(m > n) return NULL;
    return fromToAux(m, n, NULL);
}

_Bool included_rec_(ListNodePtr ls1, ListNodePtr ls2)
{
    if(ls1 == NULL || ls2 == NULL) {
        if(ls1 == NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if(ls1->data == ls2->data) {
            return included_rec_(ls1->next, ls2->next);
        } else {
            return included_rec(ls1, ls2->next);
        }
    }
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2)
{
    if(ls1 == NULL || ls2 == NULL) return 0;
    int ret = included_rec_(ls1, ls2);
    return ret;
}

ListNodePtr reverse_rec_(ListNodePtr ls, ListNodePtr l)
{
    if(ls == NULL) return l;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return NULL;

    newNode->data = ls->data;
    newNode->next = l;

    return reverse_rec_(ls->next, newNode);
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_rec(ListNodePtr ls)
{
    if(ls == NULL) return NULL;
    return reverse_rec_(ls, NULL);
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi corrispondenti di due liste @ls1 e @ls2
// di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2)
{
    if(ls1 == NULL || ls2 == NULL) return NULL;
    ListNodePtr currentNode = malloc(sizeof(ListNode));
    if(currentNode == NULL) return NULL;
    currentNode->data = ls1->data + ls2->data;
    currentNode->next = zipSum_rec(ls1->next, ls2->next);
    return currentNode;
}

ListNodePtr zipSumAux(ListNodePtr ls1, ListNodePtr ls2, ListNodePtr head, ListNodePtr tail)
{
    if(ls1 == NULL || ls2 == NULL) return head;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return NULL;

    newNode->data = ls1->data + ls2->data;
    newNode->next = NULL;

    if(!head) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    return zipSumAux(ls1->next, ls2->next, head, newNode);
}

// VERSIONE ricorsiva di coda
ListNodePtr zipSum(ListNodePtr ls1, ListNodePtr ls2)
{
    if(ls1 == NULL || ls2 == NULL) return NULL;
    return zipSumAux(ls1, ls2, NULL, NULL);
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_rec(ListNodePtr ls, int x)
{
    int ret = 0;
    if(ls == NULL) return ret;
    if(ls->data == x) ret =+1;
    ret += occurrences_rec(ls->next, x);
    return ret;
}

int occurrencesAux(ListNodePtr ls, const int x, int acc)
{
    if(ls == NULL) return acc;
    if(ls->data == x) acc += 1;
    return occurrencesAux(ls->next, x, acc);
}

//VERSIONE ricorsiva di coda
int occurrences(ListNodePtr ls, int x)
{
    if(ls == NULL) return 0;
    return occurrencesAux(ls, x, 0);
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls (modifica *@p_ls).
void remove_all_rec(ListNodePtr *p_ls, int x)
{
    if(p_ls == NULL || *p_ls == NULL) {
    } else {
        if((*p_ls)->data == x) {
            ListNodePtr tmp = *p_ls;
            *p_ls = (*p_ls)->next;
            free(tmp);
            remove_all_rec(&(*p_ls), x);
        } else {
            remove_all_rec(&(*p_ls)->next, x);
        }
    }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_rec(ListNodePtr ls)
{
    if(ls == NULL) {
    } else {
        if((ls->data % 2) == 0) {
            ListNodePtr newNode = malloc(sizeof(ListNode));
            if(newNode == NULL) return;
            newNode->data = ls->data;
            newNode->next = ls->next;
            ls->next = newNode;
            duplicate_even_rec(newNode->next);
        } else {
            duplicate_even_rec(ls->next);
        }
    }
}
