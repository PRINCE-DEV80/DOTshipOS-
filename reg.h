#ifndef REG_H
#define REG_H

void reg_ister(void);
void login(void);
int check_registration(void);

extern char userName[200];
extern char password[200];
extern char savedName[200];
extern char savedPassword[200];
extern char name[200];
extern char pass[200];
extern int registered;

#endif
