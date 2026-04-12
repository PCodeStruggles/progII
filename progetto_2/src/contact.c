#include <stdio.h>

#include <string.h>

#include "contact.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */

/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */

/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**

 * @brief Controlla se due contatti hanno lo stesso nome e cognome.

 * Restituisce:
 * - 1 se i due contatti sono uguali, 0 se sono diversi, -99 se qualche name o
 surname è NULL

 * @param c1 primo contatto.

 * @param c2 secondo contatto.

 * @return  1, 0, o -99.

 */

int contactEq(Contact c1, Contact c2)
{
    int ret = 0;
    if (c1.name == NULL || c1.surname == NULL || c2.name == NULL ||
            c2.surname == NULL) {
        ret = -99;
    } else if (strlen(c1.name) != strlen(c2.name) ||
               strlen(c1.surname) != strlen(c2.surname)) {
        ret = 0;
    } else {
        if (strcmp(c1.name, c2.name) == 0 && strcmp(c1.surname, c2.surname) == 0) {
            ret = 1;
        }
    }
    return ret;
}

/**  @brief Controlla se due contatti hanno lo stesso nome e cognome
      @param pc1 il puntatore al primo contatto (assumete non NULL)
      @param pc2 il puntatore al secondo contatto (assumete non NULL)
      @return 1 se i due contatti sono uguali, 0 se sono diversi, -99 se qualche
   name o surname è NULL
*/
int contactEqEff(const Contact *pc1, const Contact *pc2)
{
    int ret = 0;
    if (pc1->name == NULL || pc1->surname == NULL || pc2->name == NULL ||
            pc2->surname == NULL) {
        ret = -99;
    } else if (strlen(pc1->name) != strlen(pc2->name) ||
               strlen(pc1->surname) != strlen(pc2->surname)) {
        ret = 0;
    } else {
        if (strcmp(pc1->name, pc2->name) == 0 &&
                strcmp(pc1->surname, pc2->surname) == 0) {
            ret = 1;
        }
    }
    return ret;
}

/**  @brief Confronta due contatti per cognome rispetto all'ordine
   lessicografico e, se il cognome e' lo stesso, per nome
      @param c1 il primo  contatto
      @param c2 il secondo contatto
      @return -1 se c1 minore di c2, 0 se c1 uguale a c2, 1 se c1 maggiore di
   c2, -99 se qualche name o surname è NULL
*/
int contactCmp(Contact c1, Contact c2)
{
    int ret = 0;
    if(c1.surname == NULL || c1.name == NULL ||
            c2.surname == NULL || c2.name == NULL) {
        ret = -99;
    } else {
        ret = strcmp(c1.surname, c2.surname);
    }
    return ret;
}

/**  @brief Confronta due contatti per cognome rispetto all'ordine
   lessicografico e, se il cognome e' lo stesso, per nome
      @param pc1 il puntatore al primo  contatto (assumete non NULL)
      @param pc2 il puntatore al secondo  contatto (assumete non NULL)
      @return -1 se *pc1 minore di *pc2, 0 se *pc1 uguale a *pc2, 1 se *pc1
   maggiore di *pc2, -99 se qualche name o surname è NULL
*/
int contactCmpEff(const Contact *pc1, const Contact *pc2)
{
    int ret = 0;
    if(pc1->surname == NULL || pc2->surname == NULL) {
        ret = -99;
    } else {
        ret = strcmp(pc1->surname, pc2->surname);
    }
    return ret;
}
