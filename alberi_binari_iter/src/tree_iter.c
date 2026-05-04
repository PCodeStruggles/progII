#include "../include/tree_iter.h"

#include <stdlib.h>
#include <stddef.h>

/**
* @brief Mette nell'albero l'elemento `e` nella  posizione identificata da `path` (una stringa di caratteri ``L '' per left e ``R'' per right). Ovvero:
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
    IntTree* node = treePtr;
    size_t i = 0;
    while(*node != NULL && path[i] != '\0') {
        if(path[i] == 'L') { node = &(*node)->left; }
        else if(path[i] == 'R') { node = &(*node)->right; }
        else { return ERROR; };
        i++;
    }
    
    if(*node == NULL) {
        IntTree newNode = malloc(sizeof(IntTreeNode));
        if(newNode == NULL) return OUT_OF_MEMORY;
        newNode->data = e;
        newNode->left = NULL;
        newNode->right = NULL;

        *node = newNode;
        return ADDED;

    } else {
        (*node)->data = e;
        return OVERWRITTEN;
    }
}

