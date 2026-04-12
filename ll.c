/*
 * LINKED LIST
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *List;

struct listNode {
    int data;
    List next;
};

/*
 * @brief: Visita tutti i nodi della lista e stampa
 * il loro contenuto a schermo
 *
 * @param: ll puntatore alla testa della linked list
 */
void ll_visit(List ll)
{
    if (ll == NULL) return;
    List current = ll;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

/*
 * @brief: Visita tutti gli elementi della list e
 * ritorna il numero di nodi presenti al suo interno
 *
 * @param: ll puntatore alla testa della linked list
 * @return: numero di nodi presenti nella linked list
 */
size_t ll_len(List ll)
{
    size_t ret = 0;
    if (ll == NULL) return ret;
    List current = ll;
    while (current != NULL) {
        ret++;
        current = current->next;
    }
    return ret;
}

/*
 * @brief: aggiunge un nodo alla coda della lista
 *
 * @param ll: puntatore alla testa della linked list
 * @param value: valore che deve assumere il nuovo nodo della linked list
 * @return: 1 se il nodo e' stato aggiunto, 0 altrimenti
 */
bool ll_appendNode(List ll, int value)
{
    if (ll == NULL) return false;
    List newNode = malloc(sizeof(struct listNode));
    if (newNode == NULL) return false;
    newNode->data = value;
    newNode->next = NULL;
    List currentNode = ll;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    assert(currentNode->next == NULL);
    currentNode->next = newNode;
    return true;
}


/*
 * @brief: inserisci nodo in linked list ordinata
 *
 * @param ll: indirizzo alla testa della linked list
 * @param value: valore da inserire all'interno della linked list
 * @return: 1 se il nodo e' stato inseirito, 0 altrimenti
 */
bool ll_insertSorted(List *ll, int value)
{
    if (ll == NULL) return false;
    List newNode = malloc(sizeof(struct listNode));
    if (newNode == NULL) return false;
    newNode->data = value;
    newNode->next = NULL;

    List prevNode = NULL;
    List currentNode = *ll;

    while (currentNode != NULL && value > currentNode->data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (prevNode == NULL) {
        newNode->next = *ll;
        *ll = newNode;
    } else {
        newNode->next = currentNode;
        prevNode->next = newNode;
    }

    return true;
}

/*
 * @brief: inserisce un nuovo nodo di valore value prima del nodo indicato da PositionNode
 *
 * @param ll: indirizzo della testa della linked list
 * @param value: valore del nodo da inserire
 * @positionNode: indirizzo del nodo che deve seguire il nodo inserito
 * @return: 1 se il nodo è stato inserito correttamente, 0 altrimenti
*/

bool ll_insertBefore(List* ll, int value, List positionNode)
{
    bool ret = false;
    if(ll == NULL) return ret;
    List newNode = malloc(sizeof(struct listNode));
    if(newNode == NULL) return ret;

    newNode->data = value;
    newNode->next = NULL;

    List prevNode = NULL;
    List currentNode = *ll;

    while(currentNode != NULL && currentNode != positionNode) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode != NULL) {
        ret = true;
        if(prevNode == NULL) {
            newNode->next = *ll;
            *ll = newNode;
        } else {
            prevNode->next = newNode;
            newNode->next = currentNode;
        }
    }
    return ret;
}

/*
 * @brief: inserisce un nuovo nodo di valore value dopo il nodo indicato da PositionNode
 *
 * @param ll: indirizzo della testa della linked list
 * @param value: valore del nodo da inserire
 * @positionNode: indirizzo del nodo che deve precedere il nodo inserito
 * @return: 1 se il nodo è stato inserito correttamente, 0 altrimenti
*/

bool ll_insertAfter(List* ll, int value, List positionNode)
{
    bool ret = false;
    if(ll == NULL) return ret;
    List newNode = malloc(sizeof(struct listNode));
    if(newNode == NULL) return ret;
    newNode->data = value;
    newNode->next = NULL;

    if(positionNode == NULL) {
        newNode->next = *ll;
        *ll = newNode;
    } else {
        newNode->next = positionNode->next;
        positionNode->next = newNode;
    }
    return ret;
}

/*
 * @brief: cancella la prima occorrenza di value nella lista
 *
 * @param ll: indirizzo alla testa della linked list
 * @param value: valore da rimuovere
 * @return: 1 se il nodo con data = value è stato rimosso, 0 altrimenti
 */
bool ll_deleteFromList(List* ll, int value)
{
    bool ret = false;
    if(ll == NULL) return ret;
    List prevNode = NULL;
    List currentNode = *ll;

    while(currentNode != NULL && value != currentNode->data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode != NULL) {
        ret = true;
        if(prevNode == NULL) {
            *ll = currentNode->next;
        } else {
            prevNode->next = currentNode->next;
        }
        free(currentNode);
    }
    return ret;
}

/*
* @brief: Rimuove il nodo Node dalla lista
*
* @param ll: indirizzo della testa della lista
* @param Node: nodo da rimuovere dalla lista
*/
bool ll_deleteNode(List* ll, List node)
{
    bool ret = false;
    if(ll == NULL || node == NULL) return ret;

    List prevNode = NULL;
    List currentNode = *ll;

    while(currentNode != NULL && currentNode != node) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode != NULL) {
        ret = true;
        if(prevNode == NULL) {
            *ll = currentNode->next;
        } else {
            prevNode->next = currentNode->next;
        }
        free(currentNode);
    }
    return ret;
}


/*
* @brief: elimina il nodo che segue il nodo node
*
* @param ll: indirizzo alla testa della lista
* @param node: nodo che precede il nodo da eliminare
* @return: 1 se il nodo è stato eliminato, 0 altrimenti
*/
bool ll_deleteAfter(List* ll, List node)
{
    bool ret = false;
    if(ll == NULL) return false;

    if(node == NULL) {
        *ll = (*ll)->next;
    } else {
	node->next = node->next->next;
    }

    return ret;
}

int main(void)
{
    List ll = malloc(sizeof(struct listNode));
    if (ll == NULL)
        return -1;
    printf("Linked list head &ll:      %p\n", ll);
    ll->data = 10;
    ll->next = malloc(sizeof(struct listNode));
    ll->next->data = 20;
    ll->next->next = malloc(sizeof(struct listNode));
    ll->next->next->data = 30;
    List positionPtr = ll->next->next;
    printf("positionPtr: %p\n", positionPtr);
    ll_appendNode(ll, 50);
    ll_visit(ll);
    printf("-----------------------\n");
    ll_insertSorted(&ll, 15);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_insertSorted(&ll, 60);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_insertSorted(&ll, 5);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_deleteFromList(&ll, 30);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_deleteFromList(&ll, 5);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_insertBefore(&ll, 150, ll->next->next->next);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_insertAfter(&ll, 200, NULL);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_deleteNode(&ll, ll->next);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));
    printf("-----------------------\n");
    ll_deleteAfter(&ll, NULL);
    ll_visit(ll);
    printf("Linked list len: %zu\n", ll_len(ll));    
    return 0;
}
