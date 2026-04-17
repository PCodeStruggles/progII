#include <stdbool.h>
#include <stdlib.h>

#include "../include/intLinkedListSortedSetADT.h"
#include "../include/intSortedSetADT.h"

IntSortedSetADT mkSSet()
{
    IntSortedSetADT s = malloc(sizeof(struct intSortedSet));
    if (s == NULL) return NULL;
    s->first = NULL;
    s->last = NULL;
    s->size = 0;
    return s;
}

_Bool dsSSet(IntSortedSetADT *ssptr)
{
    if (ssptr == NULL || *ssptr == NULL) return 0;
    ListNodePtr currentNode = (*ssptr)->first;
    while (currentNode != NULL) {
        ListNodePtr tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }
    free(*ssptr);
    *ssptr = NULL;
    return 1;
}

_Bool sset_add(IntSortedSetADT ss, const int elem)
{
    if (ss == NULL) return 0;
    ListNodePtr currentNode = ss->first;
    ListNodePtr prevNode = NULL;
    while (currentNode != NULL && currentNode->elem < elem) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode && currentNode->elem == elem) {
        return 0;
    }
    ListNodePtr newNode = malloc(sizeof(ListNode));
    newNode->elem = elem;
    newNode->next = NULL;
    if (currentNode) {
        if (prevNode) {
            newNode->next = currentNode;
            prevNode->next = newNode;
        } else {
            newNode->next = currentNode;
            ss->first = newNode;
        }
    } else {
        if (ss->size == 0) {
            ss->first = newNode;
            ss->last = newNode;
        } else {
            ss->last->next = newNode;
            ss->last = newNode;
        }
    }
    ss->size += 1;
    return 1;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem)
{
    if (ss == NULL) return 0;
    ListNodePtr currentNode = ss->first;
    ListNodePtr prevNode = NULL;
    while (currentNode) {
        if (currentNode->elem != elem) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        } else {
            ListNodePtr tmp = currentNode;
            if (prevNode) {
                prevNode->next = currentNode->next;
            } else {
                ss->first = currentNode->next;
            }
            if (currentNode->next == NULL) {
                ss->last = prevNode;
            }
            free(tmp);
            ss->size -= 1;
            return 1;
        }
    }
    return 0;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem)
{
    if (ss == NULL || ss->size == 0) return 0;
    ListNodePtr currentNode = ss->first;
    while (currentNode) {
        if (elem == currentNode->elem) return 1;
        currentNode = currentNode->next;
    }
    return 0;
}

_Bool isEmptySSet(const IntSortedSetADT ss)
{
    if (ss == NULL) return 0;
    return (ss->size == 0);
}

int sset_size(const IntSortedSetADT ss)
{
    if (ss == NULL) return -1;
    return ss->size;
}

// TODO To be implemented
// toglie e restituisce un elemento a caso dall'insieme, restituisce false se l'insieme è NULL oppure è vuoto
_Bool sset_extract(IntSortedSetADT ss, int *ptr)
{
    if(ss == NULL || ptr == NULL) return 0;
    if(ss->first) {
        *ptr = ss->first->elem;
        ListNodePtr tmp = ss->first;
        ss->first = ss->first->next;
        ss->size -= 1;
        free(tmp);
        return 1;
    } else return 0;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return 0;
    ListNodePtr currentNodeS1 = s1->first;
    ListNodePtr currentNodeS2 = s2->first;
    while (currentNodeS1 && currentNodeS2) {
        if (currentNodeS1->elem != currentNodeS2->elem) return 0;
        currentNodeS1 = currentNodeS1->next;
        currentNodeS2 = currentNodeS2->next;
    }
    if (currentNodeS1 || currentNodeS2) {
        return 0;
    } else {
        return 1;
    }
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return 0;
    ListNodePtr currentNodeS1 = s1->first;
    ListNodePtr currentNodeS2 = s2->first;
    while (currentNodeS1 && currentNodeS2) {
        if (currentNodeS1->elem != currentNodeS2->elem) {
            currentNodeS2 = currentNodeS2->next;
        } else {
            currentNodeS1 = currentNodeS1->next;
            currentNodeS2 = currentNodeS2->next;
        }
    }
    if (currentNodeS1 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return 0;
    ListNodePtr currentNodeS1 = s1->first;
    ListNodePtr currentNodeS2 = s2->first;
    while (currentNodeS1 && currentNodeS2) {
        if (currentNodeS1->elem != currentNodeS2->elem) {
            currentNodeS2 = currentNodeS2->next;
        } else {
            currentNodeS1 = currentNodeS1->next;
            currentNodeS2 = currentNodeS2->next;
        }
    }
    if (!currentNodeS1 && s1->size < s2->size) {
        return 1;
    } else {
        return 0;
    }
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return NULL;
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) return NULL;
    ListNodePtr currentNodeS1 = s1->first;
    ListNodePtr currentNodeS2 = s2->first;
    while (currentNodeS1 || currentNodeS2) {
        if (currentNodeS1) {
            sset_add(newSet, currentNodeS1->elem);
            currentNodeS1 = currentNodeS1->next;
        }
        if (currentNodeS2) {
            sset_add(newSet, currentNodeS2->elem);
            currentNodeS2 = currentNodeS2->next;
        }
    }
    return newSet;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1,
                                  const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return NULL;
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) return NULL;
    ListNodePtr currentNodeS1 = s1->first;
    ListNodePtr currentNodeS2 = s2->first;
    while (currentNodeS1 || currentNodeS2) {
        if (currentNodeS1) {
            if (sset_member(s2, currentNodeS1->elem)) {
                sset_add(newSet, currentNodeS1->elem);
            }
            currentNodeS1 = currentNodeS1->next;
        }
        if (currentNodeS2) {
            if (sset_member(s1, currentNodeS2->elem)) {
                sset_add(newSet, currentNodeS2->elem);
            }
            currentNodeS2 = currentNodeS2->next;
        }
    }
    return newSet;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1,
                                 const IntSortedSetADT s2)
{
    if (s1 == NULL || s2 == NULL) return NULL;
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) return NULL;
    ListNodePtr currentNode = s1->first;
    while (currentNode) {
        if (!sset_member(s2, currentNode->elem))
            sset_add(newSet, currentNode->elem);
        currentNode = currentNode->next;
    }
    return newSet;
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr)
{
    if (ss == NULL || ptr == NULL) return 0;
    if (ss->first) {
        *ptr = ss->first->elem;
        return 1;
    } else {
        return 0;
    }
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr)
{
    if (ss == NULL || ptr == NULL) return 0;
    if (ss->last) {
        *ptr = ss->last->elem;
        return 1;
    } else {
        return 0;
    }
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr)
{
    if (ss == NULL || ptr == NULL) return 0;
    if (ss->first) {
        *ptr = ss->first->elem;
        ListNodePtr tmp = ss->first;
        ss->first = ss->first->next;
        free(tmp);
        return 1;
    } else {
        return 0;
    }
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr)
{
    if (ss == NULL || ptr == NULL) return 0;
    if (ss->last) {
        *ptr = ss->last->elem;
        sset_remove(ss, *ptr);
        return 1;
    } else {
        return 0;
    }
}
