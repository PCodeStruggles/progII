/*

@brief Converte in naturale (data la base).

Calcola il numero intero rappresentato dalla striga in argomento nella base
(la base deve essere un numero intero nel range 2,...,36) in argomento:
  - Saltando  eventuali spazi bianchi iniziali.
  - Fermandosi al raggiungimento del primo carattere non cifra nella base data
  (le cifre per la base 36 sono: 0,...,9,A,...,Z).

@param b: La base
@param s: Una stringa da convertire
@param r: L'indirizzo dell'itero dove memorizzare il risultato

@return Restituisce 0 se 'b' non è nell'intervallo ammesso, oppure se non trova
nessuna cifra valida (e in tal caso il valore all'indirizzo r non è
significativo). Altrimenti restituisce 1, e scrive all'indirizzo r il numero
intero rappresentato nella stringa nella base data.

Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato
tipicamente scorretto).

*/
int stoub(const char *s, const unsigned short b, int *r);
