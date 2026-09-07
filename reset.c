#include <stdio.h>
#include "reset.h"
#include <string.h>
void reset(){
	

registered = 0;

memset(userName, 0, sizeof(userName));
memset(password, 0, sizeof(password));
memset(name, 0, sizeof(name));
memset(pass, 0, sizeof(pass));

printf("System Reset Successful!\n");
}
