#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct intTreeNode IntTreeNode, *intTree;

struct intTreeNode {
    intTree left;
    int data;
    intTree right;
};

/* Visita il sotto alberosinistro, 
 * la radice e poi il sottoalbero destro 
 */
void inOrder(intTree Tree)
{
    if(Tree == NULL) return;

    inOrder(Tree->left);

    /* visita del nodo */
    printf("%d ", Tree->data);

    inOrder(Tree->right);
}

/* Visita la radice, il sottoalbero sinistro e poi il sottoalbero destro */
void preOrder(intTree Tree)
{
    if(Tree == NULL) return;

    /* visita del nodo */
    printf("%d ", Tree->data);

    preOrder(Tree->left);
    preOrder(Tree->right);
}

/* Visita il sottoalbero sinistro, quello destro e poi la radice */
void postOrder(intTree Tree)
{
    if(Tree == NULL) return;

    postOrder(Tree->left);
    postOrder(Tree->right);

    /* visita del nodo */
    printf("%d ", Tree->data);
}

size_t size(intTree Tree)
{
    if (Tree == NULL) return 0;
    size_t res = 1;
    res += size(Tree->left);
    res += size(Tree->right);
    return res;
}

size_t height(intTree Tree)
{
    if(Tree == NULL) return 0;
    size_t res = 0;
    if(Tree->left != NULL) {
        res = 1 + height(Tree->left);
    } else if(Tree->right != NULL) {
        res = 1 + height(Tree->right);
    }
    return res;
}

bool greaterThanZero(int a) { return a > 0; }

bool greaterThan10(int a) { return a > 10; }

size_t count(intTree Tree, bool (*predicate)(int elem))
{
    if(Tree == NULL) return 0;
    size_t res = 0;
    res += count(Tree->left, predicate);
    if((*predicate)(Tree->data)) res += 1;
    res += count(Tree->right, predicate);
    return res;
}

int main(void)
{
    intTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return 1;
    root->data = 12;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return 1;
    root->left->data = 10;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return 1;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return 1;
    root->left->left->data = 7;

    root->left->left->right = malloc(sizeof(IntTreeNode));
    if(root->left->left->right == NULL) return 1;
    root->left->left->right->data = 8;

    printf("InOrder: ");
    inOrder(root);
    printf("\n");

    printf("preOrder: ");
    preOrder(root);
    printf("\n");

    printf("postOrder: ");
    postOrder(root);
    printf("\n");

    printf("Tree size: %zu\n", size(root));
    printf("Tree height: %zu\n", height(root));
    printf("Num of elem greater than 0:  %zu\n", count(root, greaterThanZero));
    printf("Num of elem greater than 10: %zu\n", count(root, greaterThan10));
}
