#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "../include/ram.h"

#define RAMSTR_MAX_LEN 256

void dumpRamNodesInfo(FILE *f, RAM r)
{
    if (r == NULL || f == NULL) return;
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

void buildNodeConnections(FILE *f, RAM r)
{
    if (r == NULL || f == NULL) return;
    if (r->lbuddy) {
        fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->lbuddy);
        buildNodeConnections(f, r->lbuddy);
    }
    if (r->rbuddy) {
        fprintf(f, "\t\"%p\" -> \"%p\";\n", r, r->rbuddy);
        buildNodeConnections(f, r->rbuddy);
    }
}

void dumpRam(const char *filePath, RAM r)
{
    if (r == NULL) return;
    FILE *f = NULL;
    f = fopen(filePath, "w");
    if (f == NULL) return;
    fprintf(f, "digraph G {\n\tnode [shape=record];\n");
    dumpRamNodesInfo(f, r);
    fprintf(f, "\n");
    buildNodeConnections(f, r);
    fprintf(f, "}");
    fclose(f);
}

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

RAM allocram(int K, RAM ram)
{
    if (K > 0 && ram != NULL) {
        // Base case
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
                if (ram->lbuddy == NULL) {
                    return NULL;
                }

                ram->lbuddy->KB     = ram->KB / 2;
                ram->lbuddy->s      = LIBERO;
                ram->lbuddy->parent = ram;
                ram->lbuddy->lbuddy = NULL;
                ram->lbuddy->rbuddy = NULL;

                ram->rbuddy = malloc(sizeof(struct nodo));
                if (ram->rbuddy == NULL) {
                    return NULL;
                }

                ram->rbuddy->KB     = ram->KB / 2;
                ram->rbuddy->s      = LIBERO;
                ram->rbuddy->parent = ram;
                ram->rbuddy->lbuddy = NULL;
                ram->rbuddy->rbuddy = NULL;
            }

            // Recursive step
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

Risultato deallocram(RAM ram)
{
    if (ram == NULL || ram->s != OCCUPATO) {
        return NOK;
    }
    if (ram->parent && ram == ram->parent->lbuddy) {
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

int numfree(RAM ram)
{
    if (ram == NULL) {
        return 0;
    }
    int res = 0;
    if (ram->s == LIBERO) {
        res += ram->KB;
    }
    res += numfree(ram->lbuddy);
    res += numfree(ram->rbuddy);
    return res;
}

void ram2strBuilder(RAM ram, char **ramstr)
{
    if (ram == NULL) {
        **ramstr = '#';
        (*ramstr) = (*ramstr) + 1;
        return;
    }
    // Pre-order: root -> left subtree -> rigth subtree
    char status = 0;
    switch (ram->s) {
    case INTERNO:
        status = 'i';
        break;
    case LIBERO:
        status = 'f';
        break;
    case OCCUPATO:
        status = 'o';
        break;
    }
    **ramstr = status;
    (*ramstr) = (*ramstr) + 1;

    ram2strBuilder(ram->lbuddy, ramstr);
    ram2strBuilder(ram->rbuddy, ramstr);
}

char *ram2str(RAM ram)
{
    char *ramstr = (char) malloc(RAMSTR_MAX_LEN);
    if (ramstr == NULL) return NULL;
    char *strstart = ramstr;
    if(ram) {
        int n = sprintf(ramstr, "%d ", ram->KB);
        ramstr += n;
    }
    ram2strBuilder(ram, &ramstr);
    *ramstr = '\0';
    return strstart;
}

RAM str2RamBuilder(char** strTreeInfo, long int rootSize)
{
    if(**strTreeInfo == '\0' || **strTreeInfo == '#') {
        if(**strTreeInfo == '\0') {
            return NULL;
        } else {
            (*strTreeInfo) = (*strTreeInfo) + 1;
            return NULL;
        }
    } else {
        RAM node = malloc(sizeof(struct nodo));
        if (node == NULL) return NULL;
        node->KB = rootSize;
        switch(**strTreeInfo) {
        case 'o':
            node->s = OCCUPATO;
            break;
        case 'i':
            node->s = INTERNO;
            break;
        case 'f':
            node->s = LIBERO;
            break;
        }
        
        (*strTreeInfo) = (*strTreeInfo) + 1;

        node->lbuddy = str2RamBuilder(strTreeInfo, rootSize / 2);
        node->rbuddy = str2RamBuilder(strTreeInfo, rootSize / 2);
        return node;
    }
}

RAM str2ram(char *str)
{
    if(str == NULL) return NULL;
    long int rootSize = strtol(str, NULL, 10);
    if(rootSize == LONG_MIN || rootSize == LONG_MAX) return NULL;
    size_t i = 0;
    while(!isspace(str[i])) i++;
    char* strTreeInfo = str + i + 1;
    RAM r = str2RamBuilder(&strTreeInfo, rootSize);
    return r;
}
