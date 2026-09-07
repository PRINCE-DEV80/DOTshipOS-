#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"

void messageApp() {
    int mChoice;
    char receiver[100];
    char msg[500];

    while (1) {
        printf("\n================ MESSAGE APP ================\n");
        printf("1. Send Message\n");
        printf("2. View Sent Messages\n");
        printf("3. Back to Menu\n");
        printf("Enter Choice = ");
        scanf("%d", &mChoice);
        (void)getchar(); // Clear buffer (Warning 1 fix)

        switch (mChoice) {
            case 1:
                printf("Enter Receiver Name/Number: ");
                fgets(receiver, sizeof(receiver), stdin);
                receiver[strcspn(receiver, "\n")] = 0;

                printf("Enter Message: ");
                fgets(msg, sizeof(msg), stdin);
                msg[strcspn(msg, "\n")] = 0;

                FILE *file = fopen("messages.txt", "a");
                if (file == NULL) {
                    printf("Error opening file!\n");
                } else {
                    fprintf(file, "To: %s | Message: %s\n", receiver, msg);
                    fclose(file);
                    printf("--> Message sent successfully!\n");
                }
                break;

            case 2: {
                FILE *readFile = fopen("messages.txt", "r");
                if (readFile == NULL) {
                    printf("\nNo messages sent yet!\n");
                } else {
                    int ch; // 'char' ki jagah 'int' kar diya (Warning 2 fix)
                    printf("\n--- SENT MESSAGES HISTORY ---\n");
                    while ((ch = fgetc(readFile)) != EOF) {
                        putchar(ch);
                    }
                    fclose(readFile);
                }
                break;
            }

            case 3:
                return;

            default:
                printf("Wrong Choice! Try again.\n");
                break;
        }
    }
}
