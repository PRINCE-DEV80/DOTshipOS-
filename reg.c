#include <stdio.h>
#include <string.h>
#include "reg.h"

char savedName[200];
char savedPassword[200];

void reg_ister() {
    printf("===================================\n");
    printf("==============REGISTER=============\n");
    printf("===================================\n");
    printf("USERNAME : ");
    scanf(" %199s", userName);

    printf("PASSWORD : ");
    scanf(" %199s", password);
    printf("REGISTER SUCCESSFUL!!\n");

    FILE *fp = fopen("user.dat", "w");
    if (fp == NULL) {
        printf("ERROR: Could not save user data!\n");
        return;
    }

    fprintf(fp, "%s\n", userName);
    fprintf(fp, "%s\n", password);

    fclose(fp);
    registered = 1;
}

void login() {
    printf("===================================\n");
    printf("================LOGIN==============\n");
    printf("===================================\n");
    printf("USERNAME : ");
    scanf(" %199s", name);
    printf("PASSWORD : ");
    scanf(" %199s", pass);

    FILE *fp = fopen("user.dat", "r");
    if (fp == NULL) {
        printf("Data could not read\n");
    } else {
        // Direct read into savedName and savedPassword
        fscanf(fp, "%199s", savedName);
        fscanf(fp, "%199s", savedPassword);
        fclose(fp);
    }
}

int check_registration() {
    FILE *fp = fopen("user.dat", "r");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}
