#include <stdio.h>
#include <stdlib.h>

#include "../include/linkedListQueue.h"

CharQueueADT mkQueue()
{
    CharQueueADT q = malloc(sizeof(struct charQueue));
    if(q == NULL) return NULL;
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void dsQueue(CharQueueADT *pq)
{
    if(pq == NULL || *pq == NULL) return;

    ListNodePtr currentNode = (*pq)->front;

    while(currentNode != NULL) {
        ListNodePtr tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }
    free(*pq);
    *pq = NULL;
}

void printQueue(CharQueueADT pq)
{
    if(pq == NULL) return;

    ListNodePtr currentNode = pq->front;

    while(currentNode != NULL) {
        printf("Node       : %p\n", currentNode);
        printf("Node->data : %c\n", currentNode->data);
        printf("Node->next : %p\n", currentNode->next);
        currentNode = currentNode->next;
    }
}

bool enqueue(CharQueueADT q, const char e)
{
    if(q == NULL) return false;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return false;

    newNode->data = e;
    newNode->next = NULL;

    if(q->size == 0) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size += 1;
    return true;
}

bool dequeue(CharQueueADT q, char*res)
{
    if(q == NULL || q->front == NULL || res == NULL) return false;

    *res = q->front->data;
    ListNodePtr tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    q->size -= 1;
    return true;
}

bool isEmpty(CharQueueADT q)
{
    if(q == NULL) return false;
    return (q->size == 0);
}

int size(CharQueueADT q)
{
    if(q == NULL) return 0;
    return q->size;
}

bool peek(CharQueueADT q, int position, char* res)
{
    if(q == NULL || q->front == NULL || res == NULL) return false;
    if(position < 0 || position >= (int)q->size) return false;
    ListNodePtr currentNode = q->front;
    for(int i = 0; i < position; i++) currentNode = currentNode->next;
    *res = currentNode->data;
    return true;
}
