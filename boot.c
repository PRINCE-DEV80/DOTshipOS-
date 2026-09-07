#include <stdio.h>
#include <unistd.h>
#include "boot.h"

void boot()
{
    sleep(1);
    printf("===================================\n");
    printf("        DOTship OS v0.3\n");
    printf("===================================\n");
    printf("\n");
    printf("Loading Bootloader...\n");
    sleep(1);
    printf("\n");
    printf("Loading Kernel...\n");
    sleep(1);
    printf("\n");
    printf("Initializing Drivers...\n");
    sleep(1);
    printf("\n");
    printf("Starting System...\n");
    sleep(1);
    printf("\n");
    printf("Boot Complete!\n\n");
}
