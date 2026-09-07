#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include "term.h"
#include "calculator.h"
#include "about.h"

#define MAX_HISTORY 100

static FILE *fp;
static char command[1000];
static char line[200];

static char history[MAX_HISTORY][1000];
static int historyCount = 0;

void showPrompt(char Name[])
{
    printf("\033[32m%s@gmail.com> \033[0m", Name);
    fflush(stdout);
}

void help(void)
{
    printf("clear                 : Clear screen\n");
    printf("help                  : Show options\n");
    printf("exit                  : Exit terminal\n");
    printf("ls                    : List files\n");
    printf("whoami                : Show current user\n");
    printf("chuser-<new_username> : Change username\n");
    printf("chpass-<new_password> : Change password\n");
    printf("calc                  : Open Calculator\n");
    printf("about                 : System information\n");
    printf("time / date / year    : System time/date info\n");
    printf("history               : Show command history\n");
    printf("micro-<fileName>      : Create File\n");
    printf("read-<fileName>       : Read File\n");
    printf("rm-<fileName>         : Remove File\n");
    printf("pkg-install-<package> : Install package\n");
    printf("pkg-upgrade           : Upgrade packages\n");
    printf("pkg-update            : Update package list\n");
}

void changeUsername(char *userName, const char *newName)
{
    if (strlen(newName) > 0) {
        strcpy(userName, newName);
        printf("Username changed successfully to: %s\n", userName);
    } else {
        printf("Invalid username!\n");
    }
}

void changePassword(char *password, const char *newPassword)
{
    if (strlen(newPassword) > 0) {
        strcpy(password, newPassword);
        printf("Password changed successfully!\n");
    } else {
        printf("Invalid password!\n");
    }
}

void ls(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                printf("%s  ", dir->d_name);
            }
        }
        printf("\n");
        closedir(d);
    } else {
        printf("Failed to open directory.\n");
    }
}

void showTime(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("Time: %02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
}

void showDate(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("Date: %02d-%02d-%04d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
}

void showYear(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("Year: %04d\n", tm->tm_year + 1900);
}

void showHistory(void)
{
    if (historyCount == 0) {
        printf("No command history available.\n");
        return;
    }
    printf("--- Command History ---\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void file(char *fileName)
{
    fp = fopen(fileName, "a");
    if (fp == NULL) {
        printf("File creation failed\n");
        return;
    }
    fclose(fp);
    printf("File created [%s]\n", fileName);
}

void cat(char *fileName)
{
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File not found [%s]\n", fileName);
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

void rm(char *fileName)
{
    if (remove(fileName) == 0) {
        printf("%s removed!!\n", fileName);
    } else {
        printf("Failed to remove [%s]\n", fileName);
    }
}
void sysInfo(){
	printf("DOTshipOS System Information\n");
	printf("----------------------------\n");
	printf("OS Version : v0.3\n");
	printf("Architecture : x86_64\n");
	printf("Language : C\n");
	printf("Shell : DOTship Terminal\n");
    printf("User : %s\n",userName);
	printf("Memory : Simulation\n");
	printf("Status : Online\n");
	printf("----------------------------\n");
}
void runTerminal(char *userName, char *password)
{
    int termRun = 0;

    printf("\nWelcome to DOTship Terminal\n");
    printf("Type 'help' to see all available commands.\n\n");

    while (termRun == 0) {
        showPrompt(userName);
        scanf(" %999s", command);

        if (historyCount < MAX_HISTORY) {
            strcpy(history[historyCount], command);
            historyCount++;
        }

        if (strcmp(command, "exit") == 0 || strcmp(command,"logout") == 0) {
            printf("logout\n");
            termRun = 1;
        } 
        else if (strcmp(command, "help") == 0 || strcmp(command, "HELP") == 0) {
            help();
        } 
        else if (strcmp(command, "whoami") == 0) {
            printf("Logged in user: %s\n", userName);
        }
        else if (strncmp(command, "chuser-", 7) == 0) {
            changeUsername(userName, command + 7);
        }
        else if (strncmp(command, "chpass-", 7) == 0) {
            changePassword(password, command + 7);
        }
        else if (strcmp(command, "calc") == 0) {
            cal();
        }
        else if (strcmp(command, "about") == 0) {
            about();
        }
        else if (strcmp(command, "ls") == 0) {
            ls();
        }
        else if (strcmp(command, "time") == 0) {
            showTime();
        }
        else if (strcmp(command, "date") == 0) {
            showDate();
        }
        else if (strcmp(command, "year") == 0) {
            showYear();
        }
        else if (strcmp(command, "history") == 0) {
            showHistory();
        }
        else if (strcmp(command, "clear") == 0) {
            printf("\033[H\033[2J\033[3J");
        } 
        else if (strcmp(command, "pkg-update") == 0) {
            printf("Checking package repositories...\n");
            printf("Package lists updated.\n");
        } 
        else if (strcmp(command, "pkg-upgrade") == 0) {
            printf("Checking installed packages...\n");
            printf("Packages are up to date.\n");
        } 
        else if (strncmp(command, "micro-", 6) == 0) {
            file(command + 6);
        } 
        else if (strncmp(command, "read-", 5) == 0) {
            cat(command + 5);
        } 
        else if (strncmp(command, "rm-", 3) == 0) {
            rm(command + 3);
        }
        else if(strcmp(command,"sysInfo") == 0){
        	sysInfo();
        } 
        else {
            printf("Wrong Command!! Type 'help' for available commands.\n");
        }
    }
}
