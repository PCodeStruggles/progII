#include "student.h"

studente *crea_studente(const char *nome, const char *cognome, int matricola) {
    /* TODO: allocare memoria, copiare nome e cognome, impostare matricola. */
    /* TODO: gestire parametri NULL e fallimento di allocazione. */
    return NULL;
}

void stampa_studente(const studente *s) {
    /* TODO: stampare nome, cognome e matricola in modo sicuro. */
    /* TODO: gestire il caso s == NULL. */
}

void libera_studente(studente *s) {
    /* TODO: liberare la memoria allocata. */
    /* TODO: gestire il caso s == NULL. */
}

/* Gestione array di studenti */
int aggiungi_studente_array(studente_array *arr, const studente *s) {
    /* TODO: aggiungere uno studente all'array. */
    /* TODO: restituire 1 se successo, 0 se array pieno o parametri invalidi. */
    return 0;
}

void stampa_array_studenti(const studente_array *arr) {
    /* TODO: stampare tutti gli studenti dell'array con numerazione. */
}

void ordina_array_per_cognome(studente_array *arr) {
    /* TODO: ordinare l'array per cognome (alfabetico). */
    /* TODO: implementazione ricorsiva o iterativa. */
}

void ordina_array_per_matricola(studente_array *arr) {
    /* TODO: ordinare l'array per matricola (numerico). */
    /* TODO: implementazione ricorsiva o iterativa. */
}

studente *ricerca_per_matricola(const studente_array *arr, int matricola) {
    /* TODO: cercare uno studente per matricola. */
    /* TODO: restituire il puntatore allo studente o NULL se non trovato. */
    return NULL;
}
