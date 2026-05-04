#ifndef TREE_REC_H
#define TREE_REC_H

enum response { ADDED, OVERWRITTEN, OUT_OF_MEMORY };

typedef enum response Response;

typedef struct intTreeNode IntTreeNode, *IntTree; 

struct intTreeNode {  
   IntTree left;
   int data;
   IntTree right;
}; 

void indMinBST_r(IntTree tree);

int findMinBST(IntTree tree);

bool searchBST(IntTree tree, int value);

#endif //TREE_REC_H
