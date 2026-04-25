#include <stdlib.h>
#include <stdio.h>

#include "../include/ram.h"

void dumpRamNodesInfo(FILE* f, RAM r)
{
    if(r == NULL) return;
    fprintf(f,"\t\"%p\" [label=\"{ Addr: %p | Size: %d | Status: %s }\"];\n",
            r, 
            r, 
            r->KB, 
            (r->s == 1) ? "LIBERO" : "OCCUPATO");
    dumpRamNodesInfo(f, r->lbuddy);
    dumpRamNodesInfo(f, r->rbuddy);
}

void buildNodeConnections(FILE* f, RAM r)
{
    if(r->lbuddy) {
        fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->lbuddy);
        buildNodeConnections(f, r->lbuddy);
    }
    if(r->rbuddy) {
        fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->rbuddy);
        buildNodeConnections(f, r->rbuddy);
    }
}

void dumpRam(const char* filePath, RAM r)
{
    if(r == NULL) return;
    FILE* f;
    f = fopen(filePath, "w");
    fprintf(f, "digraph G {\n\tnode [shape=record];\n");
    dumpRamNodesInfo(f, r);
    fprintf(f, "\n");
    buildNodeConnections(f, r);
    fprintf(f, "}");
    fclose(f);
}

/**
* @brief Crea una struttura RAM con una certa quantità di memoria
* @param M la quantità di memoria voluta, espressa in KB 
*  (deve essere una potenza di 2, maggiore o uguale a 1)
* @return Il puntatore alla struttura creata, oppure NULL in caso di errore
*/
RAM initram(int M)
{
    if ((M >= 1) && (M == 1 || (M % 2) == 0)) {
        RAM r = malloc(sizeof(struct nodo));
        if (r == NULL) return NULL;

        r->KB     = M;
        r->s      = LIBERO;
        r->parent = NULL;
        r->lbuddy = NULL;
        r->rbuddy = NULL;

        return r;
    }
    return NULL;
}

/**
* @brief Tenta di allocare una data quantità di memoria entro una RAM
* @param K la quantità di memoria richiesta, in KB
* @param ram la RAM entro cui cercare la memoria richiesta
* @return Il puntatore al nodo che può ospitare la quantità richiesta, 
*  oppure NULL se non trovato
*/
RAM allocram(int K, RAM ram)
{
    if(K > 0) {
        if((ram->KB / 2) < K) {
            if(ram->KB >= K && ram->s == LIBERO) {
                ram->s = OCCUPATO;
                return ram;
            } else {
                return NULL;
            }
        } else {
            if(!ram->lbuddy) {
                ram->lbuddy = malloc(sizeof(struct nodo));
                if(ram->lbuddy == NULL) return NULL;

                ram->lbuddy->KB     = ram->KB / 2;
                ram->lbuddy->s      = LIBERO;
                ram->lbuddy->parent = ram;
                ram->lbuddy->lbuddy = NULL;
                ram->lbuddy->rbuddy = NULL;

                ram->rbuddy = malloc(sizeof(struct nodo));
                if(ram->rbuddy == NULL) return NULL;

                ram->rbuddy->KB     = ram->KB / 2;
                ram->rbuddy->s      = LIBERO;
                ram->rbuddy->parent = ram;
                ram->rbuddy->lbuddy = NULL;
                ram->rbuddy->rbuddy = NULL;

            }

            RAM n = allocram(K, ram->lbuddy);
            if(n == NULL) {
                n = allocram(K, ram->rbuddy);
            }
            return n;
        }
    } else {
        return NULL;
    }
}

