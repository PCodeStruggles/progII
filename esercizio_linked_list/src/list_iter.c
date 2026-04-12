#include <stdlib.h>
#include <stdio.h>

#include "../include/list_iter.h"

// TODO: Remove bool ret allocations where not needed
// TODO: Remove ListNodePtr CurrentNode allocations where not needed

void printList(ListNodePtr list)
{
    if(list == NULL) return;
    ListNodePtr currentNode = list;
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

ListNodePtr listInit(int value)
{
    ListNodePtr listHead = malloc(sizeof(ListNode));
    if(listHead == NULL) return listHead;
    listHead->data = value;
    listHead->next = NULL;
    return listHead;
}

bool listAppendNode(ListNodePtr list, int value)
{
    bool ret = false;
    if(list == NULL) return ret;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return ret;

    newNode->data = value;
    newNode->next = NULL;

    ListNodePtr currentNode = list;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    ret = true;

    return ret;
}

bool listPrependNode(ListNodePtr* list, int value)
{
    bool ret = false;
    if(list == NULL) return ret;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return ret;
    newNode->data = value;
    newNode->next = *list;

    *list = newNode;
    ret = true;
    return ret;
}

bool listInsertAfter(ListNodePtr* list, ListNodePtr position, int value)
{
    bool ret = false;
    if(list == NULL || position == NULL) return ret;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return ret;
    newNode->data = value;
    newNode->next = NULL;

    ListNodePtr currentNode = *list;

    while(currentNode != NULL && currentNode != position) {
        currentNode = currentNode->next;
    }

    if(currentNode != NULL) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    return ret;
}

ListNodePtr fromTo_iter(int m, int n)
{
    if(m > n) return NULL;
    ListNodePtr list = listInit(m++);
    if(list == NULL) return list;
    for(; m <= n; m++) {
        listAppendNode(list, m);
    }
    return list;
}

bool included_iter(ListNodePtr ls1, ListNodePtr ls2)
{
    bool ret = false;
    if(ls1 == NULL || ls2 == NULL) return ret;

    ListNodePtr currentNode1 = ls1;
    ListNodePtr currentNode2 = ls2;

    while(currentNode1 != NULL &&
            currentNode2 != NULL &&
            currentNode1->data == currentNode2->data) {
        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next;
    }

    if(currentNode1 == NULL) ret = true;

    return ret;
}

ListNodePtr reverse_iter(ListNodePtr ls)
{
    if(ls == NULL) return NULL;
    ListNodePtr reverseList = listInit(ls->data);

    ListNodePtr currentNode = ls->next;

    while(currentNode != NULL) {
        listPrependNode(&reverseList, currentNode->data);
        currentNode = currentNode->next;
    }
    return reverseList;
}

ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2)
{
    if(ls1 == NULL || ls2 == NULL) return NULL;

    ListNodePtr listSum = listInit(ls1->data + ls2->data);

    ListNodePtr currentNode1 = ls1->next;
    ListNodePtr currentNode2 = ls2->next;

    while(currentNode1 != NULL && currentNode2 != NULL) {
        listAppendNode(listSum, currentNode1->data + currentNode2->data);
        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next;
    }

    return listSum;
}

int occurrences_iter(ListNodePtr ls, int x)
{
    int ret = 0;
    if(ls == NULL) return ret;

    ListNodePtr currentNode = ls;

    while(currentNode != NULL) {
        if(currentNode->data == x) ret += 1;
        currentNode = currentNode->next;
    }

    return ret;
}

void remove_all_iter(ListNodePtr *p_ls, int x)
{
    if(p_ls == NULL) return;

    ListNodePtr prevNode = NULL;
    ListNodePtr currentNode = *p_ls;

    while(currentNode != NULL) {
        if(currentNode->data == x) {
            ListNodePtr nodeToBeDeleted = currentNode;
            prevNode->next = currentNode->next;
            currentNode = currentNode->next;
            free(nodeToBeDeleted);
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return;
}

void duplicate_even_iter(ListNodePtr *ls)
{
    if(ls == NULL) return;

    ListNodePtr currentNode = *ls;
    
    while(currentNode != NULL) {
        if(currentNode->data % 2 == 0) {
            ListNodePtr temp = currentNode->next;
            listInsertAfter(ls, currentNode, currentNode->data);
            currentNode = temp;
        } else {
	    currentNode = currentNode->next;
        }
    }
}
