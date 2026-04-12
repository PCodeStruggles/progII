#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NOME_LEN 30
#define MAX_COGNOME_LEN 30
#define MAX_STUDENTI 100

typedef struct studente {
    char nome[MAX_NOME_LEN + 1];
    char cognome[MAX_COGNOME_LEN + 1];
    int matricola;
} studente;

typedef struct {
    studente studenti[MAX_STUDENTI];
    unsigned int num_studenti;
} studente_array;

/* Funzioni base */
studente *crea_studente(const char *nome, const char *cognome, int matricola);
void stampa_studente(const studente *s);
void libera_studente(studente *s);

/* Gestione array di studenti */
int aggiungi_studente_array(studente_array *arr, const studente *s);
void stampa_array_studenti(const studente_array *arr);
void ordina_array_per_cognome(studente_array *arr);
void ordina_array_per_matricola(studente_array *arr);
studente *ricerca_per_matricola(const studente_array *arr, int matricola);

#endif /* STUDENT_H */
