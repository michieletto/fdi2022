#include "keywords.h"

/**
 * Aprire in lettura il file di cui si riceve il path in input
 * Analizzare il file per estrarre le parole chiave dal testo
 * Restituire le parole usando un array di stringhe allocato dinamicamente
 * Usare num_keywords_ptr per fornire in output il numero di parole chiave trovate  
 * @param [in] filepath path del file formattato contenente le parole chiave
 * @param [out] num_keywords_ptr numero di parole chiave trovate (una per riga)
 * @return array allocato dinamicamente di parole chiave
 * Nel caso la lettura del file o l'allocazione di memoria non vadano a buon fine, 
 * azzerare il valore di num_rows_ptr, liberare la memoria allocata e restituire NULL
**/
string* get_keyworks(char filepath[], int *num_keywords_ptr) {
    // Apre il file in lettura
    FILE* f = fopen(filepath, "r");
    
    // Verifica se il file è stato aperto correttamente
    if (f == NULL) {
        *num_keywords_ptr = 0;
        return NULL;
    }

    // Variabili di appoggio
    char buffer[MAX_CHARS_PER_ROW] = {0};
    int keyword_pos;

    // Leggo il numero di keywords (una per riga) dal file
    fscanf(f, "%d", num_keywords_ptr);

    // Alloco la memoria relativa all'array di string
    string *keywords = malloc(sizeof(string)*(*num_keywords_ptr));
    // Verifico se l'allocazione è andata a buon fine 
    if (keywords == NULL) {
        *num_keywords_ptr = 0;
        fclose(f);
        return NULL;
    }

    // Per tutte le righe nel file
    for(int i=0; i<(*num_keywords_ptr); i++){
        // Leggo la posizione della parola chiave nella riga
        fscanf(f, "%d", &keyword_pos);
        // Salto le parole prima della parola chiave
        for (int j = 0; j < keyword_pos; j++)
        {
            fscanf(f, "%s", buffer);
        }
        // Leggo la parola chiave dal file
        fscanf(f, "%s", buffer);
        // Calcolo la lunghezza della parola chiave
        int key_len = strlen(buffer);
        // Alloco una stringa per copiare la parola chiave
        keywords[i] = malloc(sizeof(char)*(key_len+1));
        // Verifico se l'allocazione è andata a buon fine 
        if (keywords[i] == NULL) {
            // Cancellazione della memoria già allocata
            // se gli studenti non lo fanno, peccato
            for(int j = 0; j<i; j++) {
                free(keywords[j]);
                keywords[j] = NULL;
            }
            free(keywords);
            keywords = NULL;
            // Parte necessaria per gli studenti
            fclose(f);
            *num_keywords_ptr = 0;
            return NULL;
        }
        // Copio la parola chiave nell'array
        strcpy(keywords[i], buffer);
        // Passo alla riga successiva del file
        fscanf(f, "%*[^\n]\n");
    }

    fclose(f);
    // Restituisco l'array allocato contenente le parole chiave
    return keywords;
}
