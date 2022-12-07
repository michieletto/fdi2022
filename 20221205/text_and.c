#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Massimo numero di caratteri nei campi di testo
#define MAX_TEXT_CHAR 30
// Massimo numero di autori nel database
#define NUM_MAX_AUTHORS 10

// Struttura dati che rappresenta un autore
typedef struct {
    char name[MAX_TEXT_CHAR+1];         // per poter visualizzare MAX_TEXT_CHAR caratteri 
    char surname[MAX_TEXT_CHAR+1];      // devo aggiungerne 1 che contenga il carattere 
    int day;                            // terminatore '/0' che conclude le stringhe in C
    int month;
    int year;
} author;

/**
 * Stampa a video le informazioni su un autore
 * @param [in] informazioni sull'autore da stampare
**/
void print_author(author* author_ptr) {
    printf(" >>> AUTHOR <<<\n");
    // In input ricevo un puntatore perciò
    // per l'accesso ai campi uso l'operatore ->
    printf("Name: %s\n", author_ptr->name);
    // In maniera equivalente potrei usare l'operatore * per ottenere
    // il valore puntato per usare l'operatore . per accedere al campo
    printf("Surame: %s\n", (*author_ptr).surname);
    printf("Date of birth: %d/%d/%d\n", author_ptr->day, author_ptr->month, author_ptr->year);
}


/**
 * Funzione ricorsiva per la ricerca di un autore all'interno del database
 * basata sulla concatenazione di cognome e nome dell'autore
 * @param [in] author_ptr informazioni sull'autore da cercare
 * @param [in] start puntatore all'elemento da cui iniziare la ricerca
 * @param [in] end puntatore all'elemento a cui concludere la ricerca
 * @return vero se l'autore è stato trovato, falso altrimenti
**/ 
bool search_author_recursive(author* author_ptr, author* start, author* end) {
    // Se l'elemento iniziale segue quello finale (situazione di incoerenza)
    if (start>end)
        // non ho trovato l'elemento nell'array
        return false;
    // calcolo l'elemento a metà tra inizio e fine
    author* middle = start + (end-start)/2;

    // calcolo le lunghezze degli array di caratteri da usare come chiave di ricerca
    // per l'elemento a metà dell'array ordinato
    int len_middle = strlen(middle->name) + strlen(middle->surname) + 1;
    // e per quello da cercare
    int len_seach = strlen(author_ptr->name) + strlen(author_ptr->surname) + 1;

    // calcolo la chiave di ricerca per l'elemento a metà dell'array ordinato
    char temp_key_middle[len_middle];
    // strcpy copia la stringa scr (la seconda), nella stringa dst (la prima)
    strcpy(temp_key_middle, middle->surname);
    // strcat concatena la stringa scr (la seconda), in coda alla stringa dst (la prima)
    strcat(temp_key_middle, middle->name);
    
    // calcolo la chiave di ricerca per l'elemento da cercare nell'array ordinato
    char temp_key_search[len_seach];
    strcpy(temp_key_search, author_ptr->surname);
    strcat(temp_key_search, author_ptr->name);
    
    // confronto le due chiavi
    int out = strcmp(temp_key_search, temp_key_middle);
    // se sono uguali
    if (out == 0)
        // ho trovato l'elemento che cercavo
        return true;
    // altrimenti verifico in quale metà continuare la ricerca
    // se l'elemento cercato è minore di quello a metà
    else if (out < 0) {
        // cerco dall'inizio fino all'elemento prima della metà,
        // posso escludere l'elemento di mezzo perché abbiamo 
        // vericato che non coincide con quello cercato
        search_author_recursive(author_ptr, start, middle-1);
    } else {
        // cerco dall'elemento dopo la metà fino alla fine,
        // posso escludere l'elemento di mezzo perché abbiamo 
        // vericato che non coincide con quello cercato
        search_author_recursive(author_ptr, middle+1, end);
    }
}

/**
 * Funzione iterativa per la ricerca di un autore all'interno del database
 * basata sulla concatenazione di cognome e nome dell'autore
 * @param [in] author_ptr informazioni sull'autore da cercare
 * @param [in] start puntatore all'elemento da cui iniziare la ricerca
 * @param [in] end puntatore all'elemento a cui concludere la ricerca
 * @return vero se l'autore è stato trovato, falso altrimenti
**/ 
bool search_author_iterative(author* author_ptr, author* start, author* end) {
    // Finché l'elemento iniziale precede in memoria quello finale
    // significa che c'è almeno un elemento da controllare tra start e end
    while (start<end) {    
        // calcolo l'elemento a metà tra inizio e fine
        author* middle = start + (end-start)/2;

        // calcolo le lunghezze degli array di caratteri da usare come chiave di ricerca
        // per l'elemento a metà dell'array ordinato
        int len_middle = strlen(middle->name) + strlen(middle->surname) + 1;
        // e per quello da cercare
        int len_seach = strlen(author_ptr->name) + strlen(author_ptr->surname) + 1;

        // calcolo la chiave di ricerca per l'elemento a metà dell'array ordinato
        char temp_key_middle[len_middle];
        // strcpy copia la stringa scr (la seconda), nella stringa dst (la prima)
        strcpy(temp_key_middle, middle->surname);
        // strcat concatena la stringa scr (la seconda), in coda alla stringa dst (la prima)
        strcat(temp_key_middle, middle->name);
        
        // calcolo la chiave di ricerca per l'elemento da cercare nell'array ordinato
        char temp_key_search[len_seach];
        strcpy(temp_key_search, author_ptr->surname);
        strcat(temp_key_search, author_ptr->name);
        
        // confronto le due chiavi
        int out = strcmp(temp_key_search, temp_key_middle);
        // se sono uguali
        if (out == 0)
            // ho trovato l'elemento che cercavo
            return true;
        // altrimenti verifico in quale metà continuare la ricerca
        // se l'elemento cercato è minore di quello a metà
        else if (out < 0) {
            // aggiorno il puntatore all'elemento a cui concludere la ricerca 
            // con l'indirizzo dell'elemento prima della metà,
            // posso escludere l'elemento di mezzo perché abbiamo 
            // vericato che non coincide con quello cercato
            end =  middle-1;
        } else {
            // aggiorno il puntatore all'elemento da cui iniziare la ricerca 
            // con l'indirizzo dell'elemento dopo la metà,
            // posso escludere l'elemento di mezzo perché abbiamo 
            // vericato che non coincide con quello cercato
            start = middle + 1;
        }
    }
    // non ho trovato l'elemento nell'array
    return false;
}

/**
 * Funzione alias che permette di richiamare la ricerca di un autore nel database
 * a partire da array di autori e numero di autori presenti nell'array 
 * convertendo queste informazioni in puntatori all'inizio e alla fine dell'array
 * @param [in] author_ptr informazioni sull'autore da cercare
 * @param [in] author_db array di autori che costituisce il database
 * @param [in] num_authors numero di autori presenti nel database
 * @return vero se l'autore è stato trovato, falso altrimenti
**/
bool search_author(author* author_ptr, author author_db[], int num_authors){
    // Nel caso il numero di autori sia nullo
    if (num_authors == 0)
        // so che l'autore cercato non sarà presente
        return false;
    // Creo il puntatore all'inizio dell'array di autori
    author* start = author_db;
    // Creo il puntatore alla fine dell'array di autori
    author* end = author_db + num_authors;
    // Richiamo la funzione per la ricerca dell'autore basata sui puntatori
    return search_author_recursive(author_ptr, start, end);
}

/**
 * Acquisisce le informazioni su un autore tramite input dell'utente e 
 * nel caso questo non sia presente nel database, lo aggiunge in coda
 * @param [inout] author_db array di autori che costituisce il database
 * @param [inout] num_authors numero di autori presenti nel database
**/
void read_author(author author_db[], int *num_authors) {
    // Creo una variabile temporanea in cui salvare le informazioni
    // sull'autore inserite da input utente
    author temp_author;
    // Acquisisco le informazioni
    printf("Author name: ");
    scanf("%s", temp_author.name);
    printf("Author surname: ");
    scanf("%s", temp_author.surname);
    printf("Author day of birth: ");
    scanf("%d", &temp_author.day);
    printf("Author month of birth: ");
    scanf("%d", &temp_author.month);
    printf("Author year of birth: ");
    scanf("%d", &temp_author.year);

    // Se non trovo l'autore tra quelli presenti nel database
    if (!search_author(&temp_author, author_db, *num_authors)) {
        // Inserisco le informazioni in coda all'array
        author_db[*num_authors].day = temp_author.day;
        author_db[*num_authors].month = temp_author.month;
        author_db[*num_authors].year = temp_author.year;
        strcpy(author_db[*num_authors].name, temp_author.name);
        strcpy(author_db[*num_authors].surname, temp_author.surname);
        // e aumento il numero di autori salvati nella struttura
        (*num_authors)++;
        // *num_authors++
        // questa operazione sembra fare la stessa cosa, ma in realtà 
        // incrementa il valore del puntatore prima di accedere al valore puntato
        // cercate di aggiungere le parentesi per specificare al meglio l'ordine 
        // delle operazioni da effettuare ed evitare possibili errori

        // Uso la stampa a video per capire cosa succede all'interno del programma e
        // per trovare/risolvere velocemente eventuali errori che si presentano e di 
        // cui non è chiara la motivazione fin da subito, per accelerarne la soluzione
        printf("Added an author to the db!\n");
    } else {
        printf("The author is already in the db!\n");
    }
}

int main () {
    // Numero di autori presenti inizialmente nel database
    int num_authors = 0;
    // Array di autori che costituisce il database
    author authors[NUM_MAX_AUTHORS];

    // Test di acquisizione da utente di un autore
    read_author(authors, &num_authors);

    // Verifico che il database sia stato modificato correttamente
    printf("Num authors: %d\n", num_authors);
    for (int i = 0; i < num_authors; i++)
    {
        // Stampando tutti gli autori presenti nel database
        print_author(&authors[i]);
    }
    
    // Esco dal programma senza errori
    return 0;
}