#include "monopoly.h"

/**
 * Restituisce la pedina corrispondente al carattere in input
 * @param c[in] lettera iniziale della pedina (maiuscola o minuscola)
 * @return pedina il cui nome inizia per il carattere richiesto 
 * supporre che la lettera abbia sempre una pedina corrispondente
**/
alterego get_turn(char c){
    switch (toupper(c))
    {
    case 'C':
        return CAR;
    case 'S':
        return SCOTTISH_TERRIER;
    case 'H':
        return HAT;
    case 'I':
        return IRON;
    case 'B':
        return BATTLESHIP;
    case 'P':
        return PENGUIN;
    case 'T':
        return THIMBLE;
    case 'R':
        return RUBBER_DUCKY;
    }
}

/**
 * Restituisce la cifra da pagare se il giocatore è in debito
 * @param houses[in] numero di case in possesso del giocatore
 * @param hotels[in] numero di alberghi in possesso del giocatore
 * @return cifra da rimuovere dal conto del giocatore
 * corrisponde a 2 volte il numero di case - il numero di alberghi
**/
int neg_score(int houses, int hotels) {
    return 2*houses - hotels;
}

/**
 * Restituisce la cifra se il giocatore deve riscuotere un credito
 * @param houses[in] numero di case in possesso del giocatore
 * @param hotels[in] numero di alberghi in possesso del giocatore
 * @return cifra da aggiungere al conto del giocatore
 * corrisponde a 2 volte il numero di alberghi + il numero di case
**/
int pos_score(int houses, int hotels) {
    return 2*hotels + houses;
}

/**
 * Gestisce i turni di gioco e al termine stampa il vincitore
 * @param players[in] array di informazioni sui giocatori
 * @param game[in] stringa che descrive i  turni di gioco
 * ogni carattere rappresenta il turno di un giocatore
 * se il giocatore ha guadagnato denaro, la lettera sarà minuscola
 * se il giocatore ha perso denaro, la lettera sarà maiuscola
 * la prima lettera della sequenza è sempre minuscola
 * ad ogni turno mostrare il giocatore con il capitale più elevato:
 * la sua pedina, il siuo nome, il suo capitale attuale
 * concluso il gioco mostrare il vincitore
**/
void game_evolution(struct figure players[], char game[]) {
    int i = 0;
    alterego max_token = 0;
    while (game[i] != '\0') {
        char c = game[i];
        alterego token = get_turn(c);
        
        if (!players[token].jail) {
            if((c >= 'A') && (c <= 'Z')) {
                players[token].money -= neg_score(players[token].houses, players[token].hotels);
            } else {
                players[token].money += pos_score(players[token].houses, players[token].hotels);
            }
        }

        for(int token_index = 0; token_index < LAST_TOKEN; token_index++)
            if(players[token_index].money >= players[max_token].money)
                max_token = token_index;

        print_score(players[max_token].token,
            players[max_token].name,
            players[max_token].money);

        i++;
    }

    print_winner(players[max_token]);
}
