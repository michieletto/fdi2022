#include <stdio.h>

// enumeratore contenente gli indici dei piatti del menù
typedef  enum {
    CART = 0,
    BAYA_TACO,
    BURRITO,
    BOWL,
    NACHOS,
    QUESADILLA,
    SUPER_BURRITO,
    SUPER_QUESADILLA,
    STANDARD_TACO,
    TORTILLA_SALAD,
    LAST_DISH_NUMBER,
} dish_number;

// enumeratore contenente i prezzi dei piatti del menù
typedef  enum {
    DUE_BAYA_TACO = 4,
    DUE_BURRITO = 8,
    DUE_BOWL = 9,
    DUE_NACHOS = 11,
    DUE_QUESADILLA = 9,
    DUE_SUPER_BURRITO = 9,
    DUE_SUPER_QUESADILLA = 10,
    DUE_STANDARD_TACO = 3,
    DUE_TORTILLA_SALAD = 8,
} dish_price;

/**
 * Stampa a schermo la lista dei piatti a disposizione nel locale,
 * ognuno identificato da un indice, che l'utente utilizzerà per selezionare il piatto.
 * 
 * @param total importo totale dei piatti selezionati finora dall'utente.
 *              
 * Se total > 0, allora mostrare anche l'opzione per passare al pagamento del conto.
**/
void print_menu(int total) {
    printf("[%d] Baja Taco\n", BAYA_TACO);
    printf("[%d] Burrito\n", BURRITO);
    printf("[%d] Bowl\n", BOWL);
    printf("[%d] Nachos\n", NACHOS);
    printf("[%d] Quesadilla\n", QUESADILLA);
    printf("[%d] Super Burrito\n", SUPER_BURRITO);
    printf("[%d] Super Quesadilla\n", SUPER_QUESADILLA);
    printf("[%d] Standard Taco\n", STANDARD_TACO);
    printf("[%d] Tortilla Salad\n", TORTILLA_SALAD);
    // l'opzione per il pagamento del conto è presente solo se è presente un importo in carrello
    if (total > 0) 
        printf("[%d] Go to cart\n", CART);
}

/**
 * Chiede all'utente l'indice della prossima opzione desiderata.
 * Ripete la richiesta finché non ottiente una risposta valida. 
 * 
 * @param total importo totale dei piatti selezionati finora dall'utente.
 *              
 * Se total > 0, allora accetta anche l'opzione per passare al pagamento del conto.
 * Negli altri casi accetta solo indici corrispondenti a piatti nel menu.
 * 
 * @return indice della prossima opzione desiderata dall'utente.
 * 
**/
int ask_user(int total) {
    // Inizializzare la variabile che contiene la prossima opzione dell'utente
    int dish_num = -1;

    // Chiedere all'utente quale opzione vuole selezionare
    for(;;) {
        printf("Select next option: \n");
        scanf("%d", &dish_num);
        // verificare che l'utente inserisca un indice presente nel menù
        // oppure, se è presente un importo in carrello, l'opzione per il pagamento del conto
        if ((dish_num > 0 && dish_num < LAST_DISH_NUMBER) || (dish_num == CART && total > 0)) {
            break;
        } else {
            // in caso contrario, stampare un messaggio e ripetere la richiesta
            printf("Invalid option\n");
        }
    }
    
    return dish_num; 
}

/**
 * Restituisce il costo del piatto all'indice selezionato dall'utente.
 * 
 * @param dish_num indice del piatto selezionato
 * @return costo del piatto selezionato
 * 
**/
int get_dish_price(int dish_num) {
    // Selezionare il costo del piatto scelto, ad esempio usando il costrutto switch
    switch (dish_num)
    {
    case BAYA_TACO:
        return DUE_BAYA_TACO;
    case BURRITO:
        return DUE_BURRITO;
    case BOWL:
        return DUE_BOWL;
    case NACHOS:
        return DUE_NACHOS;
    case QUESADILLA:
        return DUE_QUESADILLA;
    case SUPER_BURRITO:
        return DUE_SUPER_BURRITO;
    case SUPER_QUESADILLA:
        return DUE_SUPER_QUESADILLA;
    case STANDARD_TACO:
        return DUE_STANDARD_TACO;
    case TORTILLA_SALAD:
        return DUE_TORTILLA_SALAD;
    }

    return 0;
}

int main() {
    int total = 0;
    int dish_num = -1;
    
    while (dish_num != CART)
    {        
        // mostrare il menù dei piatti disponibili, ognuno identificato da un indice
        print_menu(total);
        dish_num = ask_user(total);
        // se si tratta di un piatto in menù, aggiungere al conto il prezzo del piatto
        total += get_dish_price(dish_num);
    
        // mostrare l'attuale ammontare del conto
        printf("Current amount due: %d\n", total);
    }
    
    // selezionata l'opzione di pagamento mostrare il totale dovuto e uscire
    printf("\nTotal amount due: %d\n", total);

    return 0;
}