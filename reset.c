#include <stdio.h>
#include <string.h>
#include "reset.h"

void reset() {
    registered = 0;

    memset(userName, 0, sizeof(userName));
    memset(password, 0, sizeof(password));
    memset(name, 0, sizeof(name));
    memset(pass, 0, sizeof(pass));

    // user.dat ko remove karna taaki next time boot() chala sake
    remove("user.dat");

    printf("System Reset Successful!\n");
}
