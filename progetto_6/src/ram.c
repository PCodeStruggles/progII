#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ram.h"

// TODO: impostare s = INTERNO per nodi interni dell'albero

void dumpRamNodesInfo(FILE *f, RAM r) {
  if (r == NULL || f == NULL)
    return;
  char s[25] = {0};
  switch (r->s) {
  case INTERNO:
    strcpy(s, "INTERNO");
    break;
  case LIBERO:
    strcpy(s, "LIBERO");
    break;
  case OCCUPATO:
    strcpy(s, "OCCUPATO");
    break;
  }
  fprintf(f, "\t\"%p\" [label=\"{ Addr: %p | Size: %d | Status: %s }\"];\n", r,
          r, r->KB, s);
  dumpRamNodesInfo(f, r->lbuddy);
  dumpRamNodesInfo(f, r->rbuddy);
}

void buildNodeConnections(FILE *f, RAM r) {
  if (r == NULL || f == NULL)
    return;
  if (r->lbuddy) {
    fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->lbuddy);
    buildNodeConnections(f, r->lbuddy);
  }
  if (r->rbuddy) {
    fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->rbuddy);
    buildNodeConnections(f, r->rbuddy);
  }
}

void dumpRam(const char *filePath, RAM r) {
  if (r == NULL)
    return;
  FILE *f;
  f = fopen(filePath, "w");
  fprintf(f, "digraph G {\n\tnode [shape=record];\n");
  dumpRamNodesInfo(f, r);
  fprintf(f, "\n");
  buildNodeConnections(f, r);
  fprintf(f, "}");
  fclose(f);
}

RAM initram(int M) {
  if ((M >= 1) && (M == 1 || (M % 2) == 0)) {
    RAM r = malloc(sizeof(struct nodo));
    if (r == NULL)
      return NULL;

    r->KB = M;
    r->s = LIBERO;
    r->parent = NULL;
    r->lbuddy = NULL;
    r->rbuddy = NULL;

    return r;
  }
  return NULL;
}

RAM allocram(int K, RAM ram) {
  if (K > 0 && ram != NULL) {
    if ((ram->KB / 2) < K) {
      if (ram->KB >= K && ram->s == LIBERO) {
        ram->s = OCCUPATO;
        return ram;
      } else {
        return NULL;
      }
    } else {
      if (!ram->lbuddy && ram->s == LIBERO) {
        ram->s = INTERNO;
        ram->lbuddy = malloc(sizeof(struct nodo));
        if (ram->lbuddy == NULL)
          return NULL;

        ram->lbuddy->KB = ram->KB / 2;
        ram->lbuddy->s = LIBERO;
        ram->lbuddy->parent = ram;
        ram->lbuddy->lbuddy = NULL;
        ram->lbuddy->rbuddy = NULL;

        ram->rbuddy = malloc(sizeof(struct nodo));
        if (ram->rbuddy == NULL)
          return NULL;

        ram->rbuddy->KB = ram->KB / 2;
        ram->rbuddy->s = LIBERO;
        ram->rbuddy->parent = ram;
        ram->rbuddy->lbuddy = NULL;
        ram->rbuddy->rbuddy = NULL;
      }

      RAM n = allocram(K, ram->lbuddy);
      if (n == NULL) {
        n = allocram(K, ram->rbuddy);
      }
      return n;
    }
  } else {
    return NULL;
  }
}

// TODO: trovare modo più elegante per controllare se il nodo ram è lbuddy o
// rbuddy
// NOTE: cosa deve succedere quando passo a deallocram la root dell'albero?
// NOTE: c'è un caso in cui l'altro buddy è un puntatore nullonullo?
Risultato deallocram(RAM ram) {
  if (ram == NULL || ram->s != OCCUPATO) {
    return NOK;
  }
  if (ram->parent && ram == ram->parent->lbuddy) {
    // siamo lbuddy, dobbiamo checkare s di rbuddy
    if (ram->parent->rbuddy->s == LIBERO) {
      RAM p = ram->parent;
      p->s = LIBERO;

      free(p->lbuddy);
      p->lbuddy = NULL;

      free(p->rbuddy);
      p->rbuddy = NULL;

    } else {
      ram->s = LIBERO;
    }
    return OK;
  }
  if (ram->parent && ram == ram->parent->rbuddy) {
    // siamo rbuddy, dobbiamo checkare s di lbuddy
    if (ram->parent->lbuddy->s == LIBERO) {
      RAM p = ram->parent;
      p->s = LIBERO;

      free(p->lbuddy);
      p->lbuddy = NULL;

      free(p->rbuddy);
      p->rbuddy = NULL;

    } else {
      ram->s = LIBERO;
    }
    return OK;
  }
  return NOK;
}
