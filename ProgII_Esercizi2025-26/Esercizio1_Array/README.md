# Esercizio Programmazione II: Operazioni su array

## Obiettivo
Realizzare un programma C modulare che esegue operazioni di base su un array di `double`: stampa, somma, media, minimo, massimo e verifica di ordinamento. L'esercizio richiede di separare interfacce e implementazione usando i file in `include/` e `src/`.

## Struttura del progetto
- `include/array_ops.h`: dichiarazioni delle funzioni richieste.
- `src/array_ops.c`: implementazione delle funzioni dichiarate.
- `src/main.c`: programma principale che crea uno o piu' array e stampa i risultati.
- `bin/`: destinazione dell'eseguibile compilato.
- `Makefile`: regole di compilazione e pulizia.

## Specifiche
Implementare in `src/array_ops.c` **due versioni per ogni funzione: ricorsiva e iterativa**.

**Funzioni richieste:**
- `void print_array_recursive(const double *data, size_t length);` e `void print_array_iterative(const double *data, size_t length);`
	- Stampano gli elementi con indice e valore.
	- Se l'array e' vuoto o `data` e' `NULL`, gestire il caso in modo sicuro.
- `double sum_array_recursive(const double *data, size_t length);` e `double sum_array_iterative(const double *data, size_t length);`
	- Restituiscono la somma degli elementi.
- `double average_array_recursive(const double *data, size_t length);` e `double average_array_iterative(const double *data, size_t length);`
	- Restituiscono la media; se `length` e' zero, gestire il caso limite.
- `void min_max_array_recursive(const double *data, size_t length, double *min, double *max);` e `void min_max_array_iterative(const double *data, size_t length, double *min, double *max);`
	- Calcolano minimo e massimo.
	- Se i parametri non sono validi, non modificano i valori.
- `int is_sorted_array_recursive(const double *data, size_t length);` e `int is_sorted_array_iterative(const double *data, size_t length);`
	- Verificano se l'array e' ordinato in modo crescente.
	- Restituiscono 1 se ordinato, 0 altrimenti.

In `src/main.c`:
- Testare **entrambe le versioni** (ricorsiva e iterativa) di ogni funzione.
- Testare `is_sorted_array_recursive` e `is_sorted_array_iterative` con array ordinati e non ordinati.
- Stampare i risultati in modo leggibile e confrontare i risultati delle due versioni.

## Vincoli
- Usare solo C standard (C11).
- **Implementare due versioni per ogni funzione: una ricorsiva e una iterativa**.
	- Versione ricorsiva: usa la ricorsione, no loop for/while.
	- Versione iterativa: usa loop for/while, no ricorsione.
- Non modificare le firme delle funzioni in `array_ops.h`.
- Evitare accessi fuori dai limiti dell'array.

## TDD
- Usare lo sviluppo guidato dai test (TDD).
- Scrivere prima i casi di test nel `src/main.c` e solo dopo implementare le funzioni in `src/array_ops.c`.