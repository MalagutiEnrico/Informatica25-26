/**
 * Libreria per la gestione delle stringhe come puntatori
 * Scritta da Malaguti Enrico
*/

#ifndef STRINGLIB_H
#define STRINGLIB_H

typedef char* String;
typedef enum {false, true} Bool;

/**
 * Pulisce il buffer stdin da eventuali caratteri residui 
*/
void clearBuffer();

/**
 * Funzione che crea una stringa di dimensione massima dim (compreso il carattere terminatore)
 * @param int dimensione della stringa da allocare
 * @return String puntatore alla stringa allocata
*/
String creaStringaDimensionata(int dim);

/**
 * Funzione che alloca una stringa di qualunque dimensione e permette di scegliere con quale carattere terminare l'inserimento
 * @param char carattere che fa terminare la stringa (specificare '\n' di default)
 * @return String puntatore alla stringa allocata
*/
String creaStringa(char terminator);

/**
 * Funzione che calcola la lunghezza di una stringa escluso il carattere terminatore
 * @param String stringa di cui contare la lunghezza
 * @return int numero di caratteri (escluso il carattere terminatore)
*/
int lenString(String str);

/**
 * Funzione che concatena due stringhe
 * @param String prima stringa da concatenare
 * @param String seconda stringa da concatenare
 * @return String puntatore alla stringa concatenata
*/
String concatString(String str1, String str2, char sep);

/**
 * Funzione che conta le occorrenze di un carattere all'interno di una stringa
 * @param String stringa in cui cercare il carattere
 * @param char carattere da cercare
 * @return int numero di occorrenze del carattere all'interno della stringa
*/
int charFrequency(String str, char character);

/**
 * Funzione che ricerca la seconda stringa all'interno della prima e conta quante volte è presente
 * @param String stringa in cui cercare
 * @param String stringa da cercare
 * @return int numero di occorrenze della seconda stringa nella prima
*/
int stringInString(String str1, String str2);

/**
 * Funzione che divide una stringa in due in base al carattere separatore e restituisce il puntatore ai puntatori delle stringhe
 * @param String stringa da dividere
 * @param char carattere separatore
 * @return puntatore ai puntatori delle stringhe
*/
String* sepString(String str, char sep);

/**
 * Funzione che crea una copia della stringa passata come parametro
 * @param String stringa da copiare
 * @return string puntatore alla copia della stringa
*/
String copyString(String str);

/**
 * Funzione che controlla che due stringhe siano uguali
 * @param String stringa numero uno
 * @param String stringa numero due
 * @return bool true se sono uguali, false se sono diverse
*/
Bool equal(String str1, String str2);

/**
 * Funzione che inverte tutti i caratteri di una stringa da minuscolo a maiuscolo o viceversa
 * @param String stringa da convertire
 * @param Bool se true allora converte da maiuscolo a minuscolo; altrimenti il contrario
*/
void maiuscMinusc(String str, Bool condition);

#endif