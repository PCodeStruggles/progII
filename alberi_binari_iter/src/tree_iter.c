#include "../include/tree_iter.h"

#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

QueuePtr qInit()
{
    QueuePtr q = malloc(sizeof(Queue));
    if(q == NULL) return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

bool enqueue(QueuePtr q, void* data)
{
    if(q == NULL || data == NULL) return false;

    QNodePtr newNode = malloc(sizeof(QNode));
    if(newNode == NULL) return false;
    newNode->data = data;

    if(q->size == 0) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size += 1;
    return true;
}

void* dequeue(QueuePtr q)
{
    if(q == NULL) return NULL;
    QNodePtr tmp = q->head;
    void* ret    = tmp->data;

    q->head = q->head->next;
    if(q->head == NULL) {
        q->tail = NULL;
    }

    q->size -= 1;
    // free(tmp);
    return ret;
}

bool isQueueEmpty(QueuePtr q)
{
    if(q == NULL) return false;
    return (q->size == 0);
}

/**
* @brief Mette nell'albero l'elemento `e` nella  posizione identificata da `path` (una stringa di caratteri ``L '' per left e ``R'' per right).
* Ovvero:
*  - se `path` porta a un nodo, assegna `e` al campo `data`di quel nodo
*  - se `path` porta fuori dall'albero, inserisce come figlio della foglia da cui è usciti dallalbero un nuovo nodo che contiene `e`.
* Restituisce:
* - ADDED se ha aggiunto un nuovo nodo,
* - OVERWRITTEN se ha modificato nodo esistente,
* - OUT_OF_MEMORY se la malloc fallisce,
* - ERROR se `path`contiene un carattere diverso da `L`o `R` prima di uscire dall'albero
*/
Response putIter(IntTree *treePtr, char *path, int e)
{
    if(treePtr == NULL || *treePtr == NULL || path == NULL) return ERROR;
    size_t i = 0;
    while(*treePtr != NULL && path[i] != '\0') {
        if(path[i] == 'L') {
            treePtr = &(*treePtr)->left;
        } else if(path[i] == 'R') {
            treePtr = &(*treePtr)->right;
        } else {
            return ERROR;
        };
        i++;
    }

    if(*treePtr == NULL) {
        IntTree newNode = malloc(sizeof(IntTreeNode));
        if(newNode == NULL) return OUT_OF_MEMORY;

        newNode->data  = e;
        newNode->left  = NULL;
        newNode->right = NULL;

        *treePtr = newNode;
        return ADDED;

    } else {
        (*treePtr)->data = e;
        return OVERWRITTEN;
    }
}

/**
* @brief Dato un albero binario restituisce le profondità minima e massima delle sue foglie
* (considerate entrambe -1 se l’albero è vuoto).
*/
ReportPtr minMaxLevel_iter(CharTree tree)
{
    ReportPtr rep = malloc(sizeof(Report));
    rep->min = -1;
    rep->max = -1;
    if(tree == NULL) return rep;

    QueuePtr q = qInit();
    if(q == NULL) return rep;
    QueryEntry root_entry = {tree, 0};
    if(!enqueue(q, &root_entry)) return rep;

    rep->min = INT_MAX;
    rep->max = INT_MIN;

    int depth = 0;

    while(!isQueueEmpty(q)) {

        QueryEntry* entry = dequeue(q);
        if(entry->node->left == NULL && entry->node->right == NULL) {
            // il nodo è una leaf
            if(entry->depth < rep->min) rep->min = entry->depth;
            if(entry->depth > rep->max) rep->max = entry->depth;
        } else {
            if(entry->node->left) {
                enqueue(q, &(QueryEntry) {entry->node->left, depth + 1} );
            }
            if(entry->node->right) {
                enqueue(q, &(QueryEntry) {entry->node->right, depth + 1} );
            }
            depth += 1;
        }
    }
}
