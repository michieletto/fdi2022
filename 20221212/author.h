#ifndef __AUTHOR_H__
#define __AUTHOR_H__

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
void print_author(author* author_ptr);

#endif // __AUTHOR_H__