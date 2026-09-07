#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boot.h"
#include "reg.h"
#include "menu.h"
#include "calculator.h"
#include "about.h"
#include "reset.h"
#include "setting.h"
#include "term.h"
#include "message.h"

// Global Variables
int run = 1;
int choice;
char userName[200];
char password[200];
int registered = 0;
char name[200];
char pass[200];
int menuChoice;
int sChoice;
int running = 0;
int settingChoice;

int main() {

    
    registered = check_registration(); // Saved data check karne ke liye call kiya gaya
if(!registered){
	boot();
}
    while (1) {
        printf("================MENU=================\n");
        printf("1. REGISTER\n");
        printf("2. LOGIN\n");
        printf("3. SHUTDOWN\n");
        printf("Enter Choice = ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                reg_ister();
                break;

            case 2:
                if (registered == 1) {
                    login();

                    if (strcmp(savedName, name) == 0 && strcmp(savedPassword, pass) == 0) {
                        printf("Login successful!!\n");
                        run = 1; // reset run flag for logged in session

                        while (run) {
                            osMenu();
                            switch (menuChoice) {
                                case 1:
                                    cal();
                                    break;

                                case 2:
                                    setting();
                                    running = 1; // Loop ko active karne ke liye 1 set kiya
                                    while (running) {
                                        printf("Enter Choice = ");
                                        scanf(" %d", &settingChoice);
                                        switch (settingChoice) {
                                            case 1:
                                                // remaining
                                                break;
                                            case 2:
                                                // remaining
                                                break;
                                            case 3:
                                                running = 0;
                                                break;
                                            default:
                                                printf("Wrong Choice\n");
                                                break;
                                        }
                                    }
                                    break;

                                case 3:
                                    about();
                                    break;

                                case 4:
                                    reset();
                                    run = 0;
                                    break;

                                case 5:
                                    runTerminal(userName, password);
                                    break;

                                case 6:
                                    messageApp();
                                    break;

                                case 7:
                                    run = 0; // Logout / Back
                                    break;

                                default:
                                    printf("Wrong choice!!\n");
                                    break;
                            }
                        }
                    } else {
                        printf("Login failed!!\n");
                    }
                } else {
                    printf("Registered first!!\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Wrong Choice : %d!!\n", choice);
                break;
        }
    }

    return 0;
}
