/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa `s` nella base `b` (tra
 * 2 e 36):
 * − saltando gli eventuali spazi bianchi iniziali;
 * − riconoscendo l'eventuale (singolo) carattere del segno (+ o -);
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data
 * (le cifre per la base 36 sono 0,..,9,A,..,Z, invece a-z non sono cifre
 * valide);
 * - deve essere presente almeno una cifra nella base data.
 *
 * Restituisce:
 * - 0 se uno degli argomenti non è valido, e in tal caso il valore in salvato
 * in `r` non è significativo;
 * - altrimenti, il numero di caratteri letti dalla stringa (inclusi spazi e
 * segni), salvando in `r` il risultato.
 *
 * Notare che la conversione della stringa c_n ... c_2 c_1 c_0 in base b è il
 * numero: c_n * b^n + ... * c_2 * b^2 + c_1 * b + c_0.
 *
 * La funzione non si accorge di eventuali overflow numerici (restituendo in
 * questo caso un risultato scorretto).
 *
 * @param s una stringa da convertire.
 * @param b la base (tra 2 e 36).
 * @param r l'indirizzo dell'intero dove memorizzare il risultato.
 * @return  il numero di caratteri letti dalla stringa
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_stoib" NOTA: questa funzione viene testata indipendentemente dal
 * vostro main IMPORTANTE: cercate sempre di far compilare il vostro codice per
 * poter vedere il risultato dei test, anche a costo di commentare parte del
 * codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * @brief Converts a string to an integer (given the base).
 *
 * Computes the integer represented by the string `s` in base `b` (between 2 and
 * 36):
 * - skipping any leading whitespace;
 * - recognizing an optional (single) sign character (+ or -);
 * - stopping at the first character that is not a valid digit in the given base
 *   (the digits for base 36 are 0,..,9,A,..,Z, while a-z are not valid digits);
 * - at least one digit in the given base must be present.
 *
 * Returns:
 * - 0 if one of the arguments is invalid, and in that case the value stored in
 * `r` is not meaningful;
 * - otherwise, the number of characters read from the string (including
 * whitespace and signs), storing the result in `r`.
 *
 * Note that the conversion of string c_n ... c_2 c_1 c_0 in base b is the
 * number: c_n * b^n + ... * c_2 * b^2 + c_1 * b + c_0.
 *
 * The function does not detect possible numeric overflows (returning an
 * incorrect result in that case).
 *
 * @param s a string to convert.
 * @param b the base (between 2 and 36).
 * @param r the address of the integer where the result is stored.
 * @return  the number of characters read from the string
 *
 * NOTE: this function appears in compilation errors as "student_stoib"
 * NOTE: this function is tested independently of your main
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int stoib(char *s, unsigned short b, int *r) {

  int sign = 1;
  int num = 0;
  int i = 0;
  bool valid_result = false;
  if (s != NULL && r != NULL && b >= 2 && b <= 36) {

    /**
     * Invariante di ciclo: s[x] == ' ' || s[x]  == '\n' || s[x] == '\t'
     * per ogni x che appartiene [0, i)
     */

    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      i++;
    }

    /**
     * Asserzione: sign contiene {1, -1}
     * Sia H valore di i con 0 <= H < strlen(s)
     */

    if (s[i] == '-') {
      sign = -1;
      i++;
    } else if (s[i] == '+') {
      i++;
    }

    /**
     * Invariante di ciclo:
     * H = i, indice della prima cifra diversa da spazio, '-' o '+'.
     * num = contiene la sommatoria in base decimale dei valori delle cifre,
     * valide per la base b, contenute nell'intervallo s[H, i).
     */

    if (b <= 10) {
      for (; s[i] >= '0' && s[i] < '0' + b; i++) {
        num = (num * b) + (s[i] - '0');
        valid_result = true;
      }
    } else {
      for (; (s[i] >= '0' && s[i] <= '9') ||
             (s[i] >= 'A' && s[i] < 'A' + (b - 10));
           i++) {
        if (s[i] <= '9') {
          num = (num * b) + (s[i] - '0');
          valid_result = true;
        } else {
          num = (num * b) + (s[i] - 'A' + 10);
          valid_result = true;
        }
      }
    }
    if (valid_result) {
      *r = num * sign;
    } else {
      i = 0;
    }
  }
  return i;
}

/**
 * Invoca la funzione stoib su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: dovete invocare "stoib" e NON "student_stoib"
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_main" NOTA: il main viene testato indipendentemente dalla vostra
 * funzione stoib IMPORTANTE: cercate sempre di far compilare il vostro codice
 * per poter vedere il risultato dei test, anche a costo di commentare parte del
 * codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the stoib function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: you have to invoke "stoib" and NOT "student_stoib"
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your stoib function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {

  struct test {
    char *s;
    unsigned short b;
    int r;
    int r_expected;
    int out_expected;
  };

  struct test test_cases[] = {
      {NULL, 2, 0, 0, 0},      // Puntatore a NULL
      {"101", 2, 0, 5, 3},     // Input valido
      {"", 2, 0, 0, 0},        // Stringa s vuota
      {" ", 2, 0, 0, 0},       // s contiene solo singolo spazio
      {"     ", 2, 0, 0, 0},   // s contiene solo spazi multipli
      {"\n", 2, 0, 0, 0},      // s contiene solo '\n'
      {"\t", 2, 0, 0, 0},      // s contiene solo '\t'
      {"-", 2, 0, 0, 0},       // s contiene solo '-'
      {"+", 2, 0, 0, 0},       // s contiene solo '+'
      {"101", 0, 0, 0, 0},     // b minore di limite inferiore
      {"A45", 37, 0, 0, 0},    // b maggiore di limite superiore
      {" 1A", 16, 0, 26, 3},   // s inizia con spazio singolo
      {"  1A", 24, 0, 34, 4},  // s inizia con piu' spazi
      {"1A ", 24, 0, 34, 2},   // s termina con spazio singolo
      {"1A   ", 24, 0, 34, 2}, // s termina con piu' spazi
      {"1AG", 16, 0, 26, 2},   // s termina con cifra non valida per base b
      {"G1A", 16, 0, 0, 0},    // s inizia con cifra non valida per base b
      {"x1A", 16, 0, 0, 0},    // s inizia con cifra non accettabile
      {" 1Ax", 16, 0, 26, 3},  // s termina con cifra non accettabile
      {"GST", 16, 0, 0, 0},    // s coniene solo cifre non valide per base b
      {"-1A", 16, 0, -26, 3},  // s contiene valore negativo
      {"+1A", 16, 0, 26, 3},   // s conteiene valore positivo esplicito
      {"-a1A", 16, 0, 0,
       0}, // s conteiene valore negativon con cifra non accettabile
      {"- 1A", 16, 0, 0, 0}, // s contiene valore negativa con spazio dopo segno
      {"-1aA", 16, 0, -1,
       2}, // s contiene valore negativa con cifra non accettabile
  };

  size_t numOfTestCases = sizeof(test_cases) / sizeof(test_cases[0]);
  bool allTestsPassed = true;

  for (size_t i = 0; i < numOfTestCases; i++) {
    int out = stoib(test_cases[i].s, test_cases[i].b, &test_cases[i].r);
    if (test_cases[i].r != test_cases[i].r_expected ||
        test_cases[i].out_expected != out) {
      fprintf(stderr, "Test %zu failed\n", i);
      fprintf(stderr, "s: '%s' - b: %hu\n", test_cases[i].s, test_cases[i].b);
      fprintf(stderr, "Expected r: %d - got: %d\n", test_cases[i].r_expected,
              test_cases[i].r);
      fprintf(stderr, "Expected return value: %d - got: %d\n",
              test_cases[i].out_expected, out);
      allTestsPassed = false;
    }
  }
  if (allTestsPassed) {
    printf("TEST PASSED\n");
  } else {
    printf("TEST FAILED\n");
  }

  return 0;
}
