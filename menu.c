// menu.c
#include <stdio.h>
#include "menu.h"
void osMenu()
{
   
        printf("\n===== DOTship OS =====\n");
        printf("1. Calculator\n");
        printf("2. Settings\n");
        printf("3. About\n");
        printf("4. Reset\n");
        printf("5. Terminal\n");
        printf("6. Messages\n");
        printf("7. Back\n");
        printf("Enter Choice = ");
        scanf(" %d",&menuChoice);
}
