#include <stdio.h>
#include <stdlib.h>
#include "computer.h"

void computer_generate_code(int code[CODE_LENGTH]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % NUM_COLORS + 1;
    }

    printf("The computer has generated a code.\n");
}
