#include <stdio.h>
#include <string.h>

#define NUM_CAT 3

typedef unsigned long ID[2];

enum tag {
    FIRST = 1,
    SECOND = 2,
    THIRD,
    FORTH,
};
enum tag position = FIRST;


typedef enum {
    PRIVATE = 0,
    BUSINESS,
} type;

enum categories {
    PER_CONTO_MIO = 1,
    ELECTRONIC = 5,
    FOOD = 20,
    JUNK_FOOD = 21,
    DIY = 50,
};

typedef enum categories user_categories[NUM_CAT];

struct private
{
    type t;
    ID serial;
    char name[30];
    user_categories cat;
};

struct business
{
    type t;
    char vat[25];
    ID serial;
    char name[30];
    user_categories cat;
};

typedef union
{
    struct private user;
    struct business entity;    
} account;

void print_category(enum categories c) {
    switch (c)
    {
    case PER_CONTO_MIO:
        printf("PER CONTO MIO");
        break;
    case ELECTRONIC:
        printf("ELECTRONIC");
        break;
    case FOOD:
        printf("FOOD");
        break;
    case JUNK_FOOD:
        printf("JUNK FOOD");
        break;
    case DIY:
        printf("DYI");
        break;
    }
}

void print_account(account acc) {
    switch (acc.entity.t)
    {
    case PRIVATE:
        printf("Private user\n");
        printf("Name: %s (%lu-%lu)\n", acc.user.name, acc.user.serial[0], acc.user.serial[1]);
        for (size_t i = 0; i < NUM_CAT; i++)
        {
            printf("Cat. %lu: ", i+1);
            print_category(acc.user.cat[i]);
            printf("\n");
        }
        
        break;

    case BUSINESS:
        printf("Business entity\n");
        printf("Name: %s (%lu-%lu)\n", acc.entity.name, acc.entity.serial[0], acc.entity.serial[1]);
        for (size_t i = 0; i < NUM_CAT; i++)
        {
            printf("Cat. %lu: ", i+1);
            print_category(acc.entity.cat[i]);
            printf(" (%d)\n", acc.entity.cat[i]);
        }
        printf("VAT: %s\n", acc.entity.vat);
        break;
    
    default:
        printf("Unknow account type\n");
        break;
    }
}

int main() {
    account acc;
    acc.entity.t = BUSINESS;
    acc.entity.serial[0] = 10;
    acc.entity.serial[1] = 20;
    strcpy(acc.entity.name, "Amazon, Inc.");
    acc.entity.cat[0] = ELECTRONIC;
    acc.entity.cat[1] = FOOD;
    acc.entity.cat[2] = DIY;
    strcpy(acc.entity.vat, "AAA0115587412");
    
    print_account(acc);

    return 0;
}
