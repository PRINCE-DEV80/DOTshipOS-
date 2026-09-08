#include <stdio.h>
#include <string.h>
#include "setting.h"

char naam[200];
char jpassword[200];
int runningSetting = 1;
char passs[200];
int SystemChoice;
int runat = 1;
char passwordOfSetting[200];

void setting() {
    runat = 1; // Re-entry ke liye runat reset
    while (runat == 1) {
        printf("========MENU========\n");
        printf("1. View Acount\n");
        printf("2. Change UserName\n");
        printf("3. Change Password\n");
        printf("4. Developer option\n");
        printf("5. Back\n");
        printf("Enter Choice = ");
        scanf(" %d", &sChoice);

        switch (sChoice) {
            case 1:
                printf("Password : ");
                scanf(" %199s", passwordOfSetting);
                if (strcmp(password, passwordOfSetting) == 0) {
                    printf("UserName : %s\n", userName);
                } else {
                    printf("Wrong Password\n");
                }
                break;

            case 2:
                printf("Change Name : ");
                scanf(" %199s", naam);
                strcpy(userName, naam);
                printf("Changed!!\n");
                break;

            case 3:
                printf("===Change Password===\n");
                printf("Old Password : ");
                scanf(" %199s", jpassword);
                if (strcmp(password, jpassword) == 0) {
                    printf("Put Change Password : ");
                    scanf(" %199s", passs);
                    strcpy(password, passs);
                    printf("Password Changed!!\n");
                } else {
                    printf("Wrong password!!\n");
                }
                break;

            case 4:
                runningSetting = 1;
                while (runningSetting == 1) {
                    printf("======================\n");
                    printf("===Developer Option===\n");
                    printf("======================\n");
                    printf("1. System Information\n");
                    printf("2. Memory Information\n");
                    printf("3. CPU Information\n");
                    printf("4. RAM\n");
                    printf("5. Storage\n");
                    printf("6. Syatem Score\n");
                    printf("7. Back\n");
                    printf("=====================\n");
                    printf("Enter Choice : ");
                    scanf(" %d", &SystemChoice);

                    switch (SystemChoice) {
                        case 1:
                            printf("===System Information===\n");
                            printf("DOTshipOS\n");
                            printf("Version : v0.3\n");
                            printf("Architechure : x86_64 (fake)\n");
                            printf("Language : C\n");
                            printf("Status : Stable\n");
                            break;
                        case 2:
                            printf("===Memory Information===\n");
                            printf("Heap : 512MB\n");
                            printf("Stack : 64MB\n");
                            printf("Pointer Size : 8 bytes\n");
                            printf("Dynamic memory : Emabled\n");
                            break;
                        case 3:
                            printf("===CPU Information===\n");
                            printf("CPU Usage : 90%%\n");
                            printf("Threads : 4\n");
                            printf("Clock : 3.20 GHz\n");
                            break;
                        case 4:
                            printf("===RAM===\n");
                            printf("RAM : 8GB\n");
                            printf("Used : 5.3\n");
                            printf("Free : 2.7GB\n");
                            break;
                        case 5:
                            printf("===Storage===\n");
                            printf("Disk : 512MB\n");
                            printf("Used : 240MB\n");
                            printf("Free : 272MB\n");
                            break;
                        case 6:
                            printf("===Syatem Score===\n");
                            printf("CPU : 90%%\n");
                            printf("RAM : 70%%\n");
                            printf("Storage : 100%%\n");
                            printf("Overrall : 87%%\n");
                            break;
                        case 7:
                            runningSetting = 0;
                            break;
                        default:
                            printf("Wrong Choice!!\n");
                            break;
                    }
                }
                break;

            case 5:
                runat = 0;
                break;

            default:
                printf("Wrong Choice!!\n");
                break;
        }
    }
}
