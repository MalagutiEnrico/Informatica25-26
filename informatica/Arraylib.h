/**
 * Funzione che stampa a video il vettore.
 * @param int vettore da stampare
 * @param int dimensione del vettore
 * @param char separatore degli elementi del vettore
*/
void stampaVettore(int vett[], int dim, char sep);

/**
 * Funzione che riempie un vettore con numeri inseriti dall'utente
 * @param int vettore da riempire
 * @param int dimensione del vettore da riempire
*/
void riempiVettore(int vett[], int dim);

/**
 * Funzione che riempie un vettore con elementi casuali compresi tra il numero minimo e il valore massimo
 * @param int vettore da riempire
 * @param int dimensione del vettore da riempire
 * @param int estremo minore dell'intervallo
 * @param int estremo maggiore dell'intervallo
*/
void riempiVettoreCasuale(int vett[], int dim, int min, int max);

/**
 * Funzione che riempie un vettore di numeri casuali, compresi tra max e min, diversi tra loro.
 * @param int[] vettore da riempire
 * @param int dimensione del vettore
 * @param int estremo minore dell'intervallo
 * @param int estremo maggiore dell'intervallo
 */
void riempiCasualiDiversi(int vett[], int dim, int min, int max);

/**
 * Funzione che conta quante volte un numero compare all'interno del vettore 
 * @param int vettore in cui cercare il numero
 * @param int dimensione del vettore
 * @param int numero da cercare nel vettore
 * @return numero di volte che il numero compare nel vettore
*/
int contaValore(int vett[], int dim, int num);

/**
 * Funzione che ricerca il valore massimo presente in un vettore
 * @param int vettore in cui cercare il massimo
 * @param int dimensione del vettore
 * @return valore massimo trovato nel vettore
*/
int massimo(int vett[], int dim);

/**
 * Funzione che ricerca il valore minimo presente in un vettore
 * @param int vettore in cui cercare il minimo
 * @param int dimensione del vettore
 * @return valore minimo trovato nel vettore
*/
int minimo(int vett[], int dim);

/**
 * Funzione che somma gli elementi di un vettore
 * @param int vettore di cui sommare gli elementi
 * @param int dimensione del vettore
 * @return int somma degli elementi del vettore
*/
int somma(int vett[], int dim);

/**
 * Funzione che ritorna alla media degli elementi di un vettore
 * @param int[] vettore di cui fare la media
 * @param int dimensione del vettore
 * @return media degli elementi
*/
float mediaVettore(int vett[], int dim);

/**
 * Funzione che scambia gli elementi tra di loro
 * @param int valore da scambiare
 * @param int valore da scambiare
 */
void scambia(int *x, int *y);

/**
 * Funzione che ricerca la posizione di un vettore ordinato in maniera sequenziale
 * @param int[] vettore in cui cercare
 * @param int dimensione del vettore
 * @param int valore da ricercare
 * @return posizione dell'elemento nel vettore
*/
int ricercaSequenziale(int vettore[], int dim, int val);

/**
 * Funzione che ricerca la posizione di un elemento in un vettore ordinato in maniera binaria
 * @param int[] vettore in cui cercare il valore
 * @param int dimensione del vettore
 * @param int posizione inferiore da cui cercare l'elemento
 * @param int posizione maggiore da cui cercare l'elemetno
 * @param int valore da cercare
 * @return posizione dell'elemento nel vettore
*/
int ricercaBinaria(int vettore[], int dim, int estInf, int estSup, int valore);

/**
 * Funzione che sposta a destra tutti gli elementi di un vettore dalla posizione indicata
 * @param int[] vettore da spostare
 * @param int dimensione del vettore
 * @param int posizione da cui iniziare a spostare gli elementi 
*/
void shiftDx(int vett[], int dim, int pos);

/**
 * Funzione che ritorna alla posizione del numero all'interno di un vettore ordinato
 * @param int[] vettore da spostare
 * @param int dimensione del vettore
 * @param int numero da cercare
 * @return posizione dell'elemento del vettore
*/
int trovaPosizione (int vett[], int dim, int num);

/**
 * Funzione che riempie un vettore con elementi casuali in maniera ordinata
 * @param int[] vettore da spostare
 * @param int dimensione del vettore
 * @param int valore minimo con cui riempire il vettore
 * @param int valore massimo con cui riempire il vettore
*/
void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo);

/**
 * Funzione che scambia due vettori tra di loro
 * @param int[] primo vettore
 * @param int[] secondo vettore
 * @param int dimensione dei vettori
*/
void scambiaVettori(int v1[], int v2[], int dim);

/**
 * Funzione che ordina gli elementi di un vettore con l'algoritmo bubbleShort
 * @param int[] vettore da ordinare
 * @param int dimensione del vettore
*/
void bubbleSort(int vett[], int dim);

/**
 * Funzione che ordina gli elementi di un vettore in maniera decrescente
 * @param int[] vettore da ordinare
 * @param int dimensione del vettore
*/
void bubbleSortDec(int vett[], int dim);

/**
 * Funzione che ordina gli elementi di un vettore con l'algortimo quickSort
 * @param int[] vettore da ordinare
 * @param int dimensione del vettore
 * @param int posizione di inizio dove ordinare
 * @param int posizione finale 
 */
void quickSort(int v[], int dim, int inizio, int fine);