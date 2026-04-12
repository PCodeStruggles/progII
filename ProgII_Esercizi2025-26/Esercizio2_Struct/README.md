# Esercizio Programmazione II: Gestione dinamica degli studenti

## Obiettivo
Realizzare una piccola libreria C che gestisce uno studente usando `struct` e memoria dinamica, separando interfaccia e implementazione.

## Struttura del progetto
- `include/student.h`: dichiarazioni della `struct studente` e delle funzioni richieste.
- `src/student.c`: implementazione delle funzioni dichiarate.
- `src/main.c`: programma principale con test che verificano il comportamento.
- `bin/`: destinazione dell'eseguibile compilato.
- `Makefile`: regole di compilazione e pulizia.

## Specifiche
In `include/student.h` è già definito:
- `MAX_NOME_LEN` e `MAX_COGNOME_LEN` pari a 30.
- `MAX_STUDENTI` pari a 100.
- la `struct studente` con campi `nome`, `cognome`, `matricola`.

Implementare in `src/student.c` le seguenti funzioni:

**Funzioni base:**
- `studente *crea_studente(const char *nome, const char *cognome, int matricola);`
	- Alloca memoria e inizializza uno studente.
	- Copia nome e cognome (max 30 caratteri), imposta matricola.
	- Se parametri invalidi o allocazione fallisce, restituire `NULL`.
- `void stampa_studente(const studente *s);`
	- Stampa nome, cognome e matricola.
	- Gestire in modo sicuro il caso `s == NULL`.
- `void libera_studente(studente *s);`
	- Libera la memoria allocata. Gestire `s == NULL`.

**Funzioni per la gestione di un array di studenti:**
- `int aggiungi_studente_array(studente *array, unsigned int *num_studenti, const studente *s);`
	- Aggiunge uno studente all'array statico (max `MAX_STUDENTI` elementi).
	- Restituisce 1 se successo, 0 se array pieno o parametri invalidi.
- `void stampa_array_studenti(const studente *array, unsigned int num_studenti);`
	- Stampa tutti gli studenti dell'array con numerazione.
- `void ordina_array_per_cognome(studente *array, unsigned int num_studenti);` e `void ordina_array_per_matricola(studente *array, unsigned int num_studenti);`
	- Ordinano l'array per cognome (alfabetico) e matricola (numerico).
	- Implementazione ricorsiva o iterativa.
- `studente *ricerca_per_matricola(const studente *array, unsigned int num_studenti, int matricola);`
	- Ricerca uno studente per matricola nell'array, restituisce il puntatore o `NULL`.

In `src/main.c`:
- Scrivere test che verificano tutte le funzioni: creazione valida, troncamento stringhe lunghe, rifiuto parametri `NULL`, stampa sicura, aggiunta a array, ordinamento, ricerca.

## Vincoli
- Usare solo C standard (C11).
- Non modificare le firme in `student.h`.

## TDD
- Usare lo sviluppo guidato dai test (TDD).
- Scrivere prima i test nel `src/main.c`, poi implementare le funzioni in `src/student.c`.