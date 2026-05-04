#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

#include "../include/tree_rec.h"

void findMinBST_r(IntTree tree, int* min)
{
    if(tree == NULL) return;
    if(tree->data < *min) *min = tree->data;
    findMinBST_r(tree->left, min);
}

/**
* @brief restituisce il minimo elemento di BST.
* ritorna INT_MAX se tree == NULL.
*/
int findMinBST(IntTree tree)
{
    if(tree == NULL) return INT_MAX;
    int min = INT_MAX;
    findMinBST_r(tree, &min);
    return min;
}

/**
* @brief restituisce 1 se il valore è presente, altrimenti 0;
*/
bool searchBST(IntTree tree, int value)
{
    if(tree == NULL) return 0;
    if(tree->data > value) {
        return searchBST(tree->left, value);
    } else if (tree->data < value) {
        return searchBST(tree->right, value);
    } else {
        return 1;
    }
}
