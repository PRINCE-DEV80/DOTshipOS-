#ifndef TERM_H
#define TERM_H
extern char userName[];
void showPrompt(char Name[]);
void help(void);
void file(char *fileName);
void cat(char *fileName);
void rm(char *fileName);
void ls(void);
void showTime(void);
void showDate(void);
void showYear(void);
void showHistory(void);
void changeUsername(char *userName, const char *newName);
void changePassword(char *password, const char *newPassword);
void runTerminal(char *userName, char *password);
void sysInfo();
#endif
