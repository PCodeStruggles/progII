#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/charArrayQueue.h"

CharQueueADT mkQueue()
{
    CharQueueADT q = malloc(sizeof(struct charQueue));
    if(q == NULL) return NULL;
    q->capacity = INITIAL_CAPACITY;
    q->a = malloc(sizeof(char) * q->capacity);
    if(q->a == NULL) {
        free(q);
        return NULL;
    }
    q->size = 0;
    q->rear = 0;
    q->front = 0;
    return q;
}

void dsQueue(CharQueueADT *pq)
{
    assert(pq != NULL);
    free((*pq)->a);
    free(*pq);
    *pq = NULL;
}

void printQueue(const CharQueueADT q)
{
    if(q == NULL || q->a == NULL) return;
    printf("q->size:  %d - q->capacity: %d\n", q->size, q->capacity);
    printf("q->front: %d - %c\n", q->front, q->a[q->front]);
    printf("q->rear : %d - %c\n", q->rear, q->a[q->rear]);
    for(int i = 0; i < q->size; i++) printf("%c ", q->a[i]);
    printf("\n");
}

bool enqueue(CharQueueADT q, const char e)
{
    if(q == NULL || q->a == NULL) return false;
    if(q->size >= q->capacity) {
        if(q->front < q->rear) {
            q->a = realloc(q->a, sizeof(char) * q->capacity * 2);
            if (q->a == NULL) return false;
            q->capacity *= 2;
        } else {
            char* tmp = malloc((q->capacity * 2) * sizeof(char));
            if(tmp == NULL) return false;

            /* I.C: tmp[0...i-1] = q->a[front...front+i] */

            for(int i = 0; i < q->size; i++) {
                tmp[i] = q->a[(q->front + i) % q->capacity];
            }
            free(q->a);
            q->a = tmp;
            q->capacity *= 2;
            q->front = 0;
            q->rear = q->size;
        }
    }
    q->a[(q->rear) % q->capacity] = e;
    q->rear = (q->rear % q->capacity) +1;
    q->size += 1;
    return true;
}

bool dequeue(CharQueueADT q, char*res)
{
    if(q == NULL || q->a == NULL || q->size == 0) return false;
    *res = q->a[q->front];
    q->front = (q->front +1) % q->capacity;
    q->size -= 1;
    if(q->size < (q->capacity / 4)) {
        char* newArray = malloc(sizeof(char) * (q->capacity / 2));
        if(newArray == NULL) return false;

        /* I.C.: newArray[0 ... i] = q->a[front ... front + i]*/

        for(int i = 0; i < q->size; i++) {
            newArray[i] = q->a[(q->front + i) % q->capacity];
        }
        free(q->a);
        q->a = newArray;
        q->capacity = q->capacity / 2;
        q->front = 0;
        q->rear = q->size;
    }
    return true;
}

bool isEmpty(const CharQueueADT q)
{
    if(q == NULL || q->a == NULL) return false;
    return (q->size == 0);
}

int size(const CharQueueADT q)
{
    if(q == NULL || q->a == NULL) return 0;
    return (q->size);
}

bool peek(const CharQueueADT q, const int position, char* res)
{
    if(q == NULL || q->a == NULL || res == NULL) return false;
    if(position >= 0 && position <= q->size) {
        *res = q->a[(q->front + position) % q->capacity];
        return true;
    } else {
        return false;
    }
}
