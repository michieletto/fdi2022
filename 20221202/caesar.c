#include "caesar.h"

/**
 * Codifica le informazioni in chiaro presenti in messages con la chiave key
 * @param messages [in/out] array contenente i messaggi da codificare
 * @param size [in] dimensione dell'array da codificare
 * @param key [in] chiave di codifica per il cifrario di Cesare
**/
void encode(struct cypher messages[], unsigned int size, int key) {
    for (unsigned int i = 0; i < size; i++)
    {
        int j = 0;
        while (messages[i].decrypted[j] != '\0')
        {
            messages[i].encrypted[j] = (NUM_KEYS + messages[i].decrypted[j] - 'A' + key) % NUM_KEYS + 'A';
            // printf("%c -> %c\n", messages[i].decrypted[j], messages[i].encrypted[j]);
            j++;
        }
        messages[i].encrypted[j] = '\0';
    }
}

/**
 * Decodifica le informazioni codificate in messages con la chiave key per rendere in chiaro
 * @param messages [in/out] array contenente i messaggi da decodificare
 * @param size [in] dimensione dell'array da decodificare
 * @param key [in] chiave di decodifica per il cifrario di Cesare
**/
void decode(struct cypher messages[], unsigned int size, int key) {
    for (unsigned int i = 0; i < size; i++)
    {
        int j = 0;
        while (messages[i].encrypted[j] != '\0')
        {
            messages[i].decrypted[j] = (NUM_KEYS + messages[i].encrypted[j] - 'A' - key) % NUM_KEYS + 'A';
            j++;
        }
        messages[i].decrypted[j] = '\0';
    }
}

/**
 * Calcola la chiave di codifica per il cifrario di Cesare dato un messaggio 
 * contenente sia codifica che decodifica
 * @param message [in] messaggio di cui si conoscono sia codifica che decodifica
 *
 * @return chiave di codifica per il cifrario di Cesare 
 * se è necessario gestire errori, ritornare 0
**/
int get_key(struct cypher message) {
    return (message.encrypted[0] - message.decrypted[0])%NUM_KEYS;
}

/**
 * Calcola la chiave di codifica per il cifrario di Cesare dato un array di messaggi
 * @param messages [in] array di messaggi in cui cercare la chiave di codifica
 * @param size [in] dimensione dell'array di messaggi
 *
 * @return chiave di codifica per il cifrario di Cesare 
 * se non ci sono messaggi contenenti sia codifica che decodifica, ritorna 0
**/
int find_key(struct cypher messages[], unsigned int size) {
    for(unsigned int i=0; i < size; i++) {
        if ((messages[i].decrypted[0] != '\0') && (messages[i].encrypted[0] != '\0')) {
            return get_key(messages[i]);
        }
    }
    return 0;
}

/**
 * Verifica un array di messaggi per codificarlo o decodificarlo
 * @param messages [in/out] array di messaggi in cui cercare la chiave di codifica
 * @param size [in] dimensione dell'array di messaggi
**/
void check_messages(struct cypher messages[], unsigned int size) {
    int key = find_key(messages, size);
    if (key == 0)  {
        key = ask_key(size);
        encode(messages, size, key);
    } else {
        decode(messages, size, key);
    }
}
