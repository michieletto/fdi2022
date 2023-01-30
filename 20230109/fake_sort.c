#include <stdio.h>
#include "fake_sort.h"

int main() {
    Person marvel[NUM_PEOPLE] = {
        {"Natilia", "Romanoff", 26}, // 0
        {"Tony", "Stark", 34},       // 1
        {"Thor", "Odinson", 1527},   // 2
        {"Bruce", "Banner", 41},     // 3
        {"Peter", "Parker", 22},     // 4
        {"Scott", "Lang", 33},       // 5
        {"Wanda", "Maximoff", 35},   // 6
        {"James", "Howlett", 155},   // 7
        {"Clinton", "Barton", 38},   // 8
        {"Steven", "Rogers", 79}    // 9
    };

    /*************************************/
    /*  INIZIO  PARTE DA INIZIALIZZARE   */
    /*************************************/

    Person *age_asc[NUM_PEOPLE] = {
        &marvel[4], 
        &marvel[0], 
        &marvel[5], 
        &marvel[1], 
        &marvel[6], 
        &marvel[8], 
        &marvel[3], 
        &marvel[9],
        &marvel[7],
        &marvel[2],
    };
    Person *age_des[NUM_PEOPLE] = {
        &marvel[2], 
        &marvel[7], 
        &marvel[9], 
        &marvel[3], 
        &marvel[8], 
        &marvel[6], 
        &marvel[1], 
        &marvel[5],
        &marvel[0],
        &marvel[4],
    };
    Person *surname_asc[NUM_PEOPLE] = {
        &marvel[3], 
        &marvel[8], 
        &marvel[7], 
        &marvel[5], 
        &marvel[6], 
        &marvel[2], 
        &marvel[4], 
        &marvel[9],
        &marvel[0],
        &marvel[1],
    };
    Person *surname_des[NUM_PEOPLE] = {
        &marvel[1], 
        &marvel[0], 
        &marvel[9], 
        &marvel[4], 
        &marvel[2], 
        &marvel[6], 
        &marvel[5], 
        &marvel[7],
        &marvel[8],
        &marvel[3],
    };
    Person *name_asc[NUM_PEOPLE] = {
        &marvel[3], 
        &marvel[8], 
        &marvel[7], 
        &marvel[0], 
        &marvel[4], 
        &marvel[5], 
        &marvel[9], 
        &marvel[2],
        &marvel[1],
        &marvel[6],
    };
    Person *name_des[NUM_PEOPLE] = {
        &marvel[6], 
        &marvel[1], 
        &marvel[2], 
        &marvel[9], 
        &marvel[5], 
        &marvel[4], 
        &marvel[0], 
        &marvel[7],
        &marvel[8],
        &marvel[3],
    };

    /*************************************/
    /*   FINE  PARTE DA INIZIALIZZARE    */
    /*************************************/
    char sort_type;
    printf("Sort type: ");
    scanf("%c", &sort_type);
    printf("\n");

    Person **sorted = NULL;
    switch (sort_type)
    {
    case NAME_ASC:
        sorted = name_asc;
        break;
    case NAME_DES:
        sorted = name_des;
        break;
    case SURNAME_ASC:
        sorted = surname_asc;
        break;
    case SURNAME_DES:
        sorted = surname_des;
        break;
    case AGE_ASC:
        sorted = age_asc;
        break;
    case AGE_DES:
        sorted = age_des;
        break;
    }

    for (int i = 0; i < NUM_PEOPLE; i++){
        if((sorted != NULL) && (sorted[i] != NULL))
            printf("%s, %s, %d\n", sorted[i]->name, sorted[i]->surname, sorted[i]->age);
        else
            printf("Data not available\n");
    }
    
}