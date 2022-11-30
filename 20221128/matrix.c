#include <stdio.h>
#include <stdbool.h>
#include <math.h>

////////////////////////////////////////////////////////////////
// NON TOCCARE DA QUI
////////////////////////////////////////////////////////////////

// Dimensione massima
#define MAX 4

// Vettore
typedef double vect4[MAX];
// Matrice
typedef double mat4[MAX*MAX];
// Indici delle operazioni nel menù
typedef enum {
    VECT_SUM=0,
    VECT_DIFF,
    MAT_SUM,
    MAT_DIFF,
    VECT_PROD,
    VECT_NORM,
    MAT_TRACE,
    MAT_NORM,
    MAT_PROD,
    LAST_OP_NUMBER,
} op_numbers;

/**
 * Stampa a schermo la lista delle funzioni disponibile in libreria, 
 * ognuna identificata da un indice, che l'utente utilizzerà per selezionare
 * l'operazione da svolgere e di conseguenza il tipo di dato da acquisire
**/
void print_menu(void) {
    printf("[%d] Somma tra vettori\n", VECT_SUM);
    printf("[%d] Differenza tra vettori\n", VECT_DIFF);
    printf("[%d] Somma tra matrici\n", MAT_SUM);
    printf("[%d] Differenza tra matrici\n", MAT_DIFF);
    printf("[%d] Prodotto scalare tra vettori\n", VECT_PROD);
    printf("[%d] Norma di un vettore\n", VECT_NORM);
    printf("[%d] Traccia di una matrice\n", MAT_TRACE);
    printf("[%d] Norma di una matrice\n", MAT_NORM);
    printf("[%d] Prodotto tra matrici\n", MAT_PROD);
}

// Lettura da tastiera di un vettore
// Es:
// vect4 v;
// read_vect("v", v, 3);
void read_vect(char vect_name[], vect4 v, int size) {
    printf("Insert %s\n", vect_name);
    for (int i = 0; i < size; i++) {
        printf("  %s[%d]: ", vect_name, i);
        scanf("%lf", &v[i]);
    }
    printf("\n");
}

// Lettura da tastiera di una matrice
// Es:
// mat4 m;
// read_matrix("m", m, 2);
void read_matrix(char mat_name[], mat4 m, int size) {
    printf("Insert %s\n", mat_name);
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("  %s[%d,%d]: ", mat_name, i, j);
            scanf("%lf", &m[i*size+j]);
        }
    }
    printf("\n");
}

// Stampa del risultato in forma di double
void output_double(double x) {
    printf("Result is:\n");
    printf("%lf\n", x);
}

// Stampa del risultato in forma di vettore
void output_vector(vect4 v, int size){
    printf("Result is:\n");
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf(" %g", v[i]);
    }
    printf(" ]\n");
}

// Stampa del risultato in forma di matrice
void output_matrix(mat4 m, int size){
    printf("Result is:\n");
    for (size_t i = 0; i < size; i++){
        printf("|");
        for (size_t j = 0; j < size; j++)
        {
            printf(" %8.3g", m[i*size+j]);
        }
        printf(" |\n");
    }
}

////////////////////////////////////////////////////////////////
// NON TOCCARE FINO A QUI
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// IMPLEMENTARE DA QUI
////////////////////////////////////////////////////////////////

/**
 * Chiede all'utente l'indice dell'operazione desiderata.
 * Ripete la richiesta finché non ottiente una risposta valida. 
 * 
 * @return indice dell'operazione desiderata dall'utente.
 * 
**/
int ask_op(void) {
    // Inizializzare la variabile che contiene la prossima opzione dell'utente
    int op_num = -1;

    // Chiedere all'utente quale opzione vuole selezionare
    for(;;) {
        printf("Select next operation: \n");
        scanf("%d", &op_num);

        // verificare che l'utente inserisca un indice presente nel menù
        if (op_num >= 0 && op_num < LAST_OP_NUMBER)
        {
            break;
        }
        // in caso contrario, stampare un messaggio e ripetere la richiesta
        printf("Invalid option\n");
    }

    return op_num;
}

/**
 * Chiede all'utente la dimensione di vettori/matrici.
 * Ripete la richiesta finché non ottiente una risposta valida. 
 * 
 * @return la dimensione di vettori/matrici.
 * 
**/
int ask_size(void) {
    // Inizializzare la variabile che contiene la dimensione di vettori/matrici
    int size = -1;

    // Chiedere all'utente la dimensione di vettori/matrici
    for(;;) {
        printf("Size: \n");
        scanf("%d", &size);
    
        // verificare che l'utente inserisca una dimensione tra 1 e MAX compresi
        if (size >= 1 && size >= MAX) 
            break;

        // in caso contrario, stampare un messaggio e ripetere la richiesta
        printf("Invalid option\n");
    }

    return size;
}

/**
 * Somma tra vettori
 * @param v1, v2, size: input
 * @param v: output
**/ 
void sum_vect(vect4 v, vect4 v1, vect4 v2, int size) {
    for (int i = 0; i < size; i++)
    {
        v[i] = v1[i] + v2[i];
    }
}

/**
 * Differenza tra vettori
 * @param v1, v2, size: input
 * @param v: output
**/
void diff_vect(vect4 v, vect4 v1, vect4 v2, int size) {
    for (int i = 0; i < size; i++)
    {
        v[i] = v1[i] - v2[i];
    }
}

/**
 * Somma tra matrici
 * @param m1, m2, size: input
 * @param m: output
**/
void sum_matrix(mat4 m, mat4 m1, mat4 m2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m[i*size+j] = m1[i*size+j] + m2[i*size+j];
        }
    }
}

/**
 * Differenza tra matrici
 * @param m1, m2, size: input
 * @param m: output
**/
void diff_matrix(mat4 m, mat4 m1, mat4 m2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m[i*size+j] = m1[i*size+j] - m2[i*size+j];
        }
    }
}

/**
 * Prodotto scalare tra vettori
 * @param v1, v2, size: input
 * @return valore del prodotto scalare
**/
double product_scalar(vect4 v1, vect4 v2, int size) {
    double s = 0.0;
    for (int i = 0; i < size; i++)
    {
        s += v1[i] * v2[i];
    }
    
    return s;
}

/**
 * Norma di un vettore
 * @param v, size: input
 * @return valore della norma del vettore
**/
double norm_vect(vect4 v, int size) {
    return sqrt(product_scalar(v, v, size));
}

/**
 * Traccia di una matrice
 * @param m, size: input
 * @return valore della traccia della matrice
**/
double trace_matrix(mat4 m, int size) {
    double s = 0.0;
    for (int i = 0; i < size; i++)
    {
        s += m[i*size+i];
    }
    
    return s;
}

/**
 * Norma di una matrice
 * @param m, size: input
 * @return valore della traccia della matrice
**/
double norm_matrix(mat4 m, int size) {
    double s = 0.0;
    for (int i = 0; i < size; i++)  {
        for (int j = 0; j < size; j++) {
            s+= m[i*size+j] * m[i*size+j];
        }
    }
    
    return sqrt(s);
}

/**
 * Prodotto tra matrici
 * @param m1, m2, size: input
 * @param m: output
**/ 
void product_matrix(mat4 m, mat4 m1, mat4 m2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m[i*size+j] = 0.0;
            for (int k = 0; k < size; k++) {
                m[i*size+j] += m1[i*size+k]*m2[k*size+j];
            }
        }
    }
    
}

int main(){
    vect4 v, v1, v2;
    mat4 m, m1, m2;

    // all'avvio mostrare il menù delle operazioni disponibili, ognuna identificata da un indice
    print_menu();

    // chiedere all'utente quale opzione vuole selezionare (sempre valori interi)
    int op_num = ask_op();
    
    // chiedere all'utente la dimensione di vettori/matrici (sempre valori interi)
    int size = ask_size();
    
    // Chiedere i dati ed effettuare l'operazione richiesta e mostrare il risultato, ad esempio usando il costrutto switch
    switch (op_num)
    {
    case VECT_SUM:
        read_vect("v1", v1, size);
        read_vect("v2", v2, size);
        sum_vect(v, v1, v2, size);
        output_vector(v, size);
        break;
    case VECT_DIFF:
        read_vect("v1", v1, size);
        read_vect("v2", v2, size);
        diff_vect(v, v1, v2, size);
        output_vector(v, size);
        break;
    case MAT_SUM:
        read_matrix("m1", m1, size);
        read_matrix("m2", m2, size);
        sum_matrix(m, m1, m2, size);
        output_matrix(m, size);
        break;
    case MAT_DIFF:
        read_matrix("m1", m1, size);
        read_matrix("m2", m2, size);
        diff_matrix(m, m1, m2, size);
        output_matrix(m, size);
        break;
    case VECT_PROD:
        read_vect("v1", v1, size);
        read_vect("v2", v2, size);
        output_double(product_scalar(v1, v2, size));
        break;
    case VECT_NORM:
        read_vect("v", v, size);
        output_double(norm_vect(v, size));
        break;
    case MAT_TRACE:
        read_matrix("m", m, size);
        output_double(trace_matrix(m, size));
        break;
    case MAT_NORM:
        read_matrix("m", m, size);
        output_double(norm_matrix(m, size));
        break;
    case MAT_PROD:
        read_matrix("m1", m1, size);
        read_matrix("m2", m2, size);
        product_matrix(m, m1, m2, size);
        output_matrix(m, size);
        break;
    }
    
    // uscire dal programma (non possono essere eseguite nuove operazioni)
    return 0;
}