#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void generate_code(int code[CODE_LENGTH]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % NUM_COLORS + 1;
    }
}

void check_guess(int code[CODE_LENGTH], int guess[CODE_LENGTH], int *correct_position, int *incorrect_position) {
    int code_copy[CODE_LENGTH], guess_copy[CODE_LENGTH];

    for (int i = 0; i < CODE_LENGTH; i++) {
        code_copy[i] = code[i];
        guess_copy[i] = guess[i];
    }

    *correct_position = 0;
    *incorrect_position = 0;

    for (int i = 0; i < CODE_LENGTH; i++) {
        if (code_copy[i] == guess_copy[i]) {
            (*correct_position)++;
            code_copy[i] = guess_copy[i] = 0;
        }
    }

    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess_copy[i] != 0) {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (code_copy[j] == guess_copy[i]) {
                    (*incorrect_position)++;
                    code_copy[j] = 0;
                    break;
                }
            }
        }
    }
}

void print_feedback(int correct_position, int incorrect_position) {
    printf("Feedback: %d at correct positions, %d in the code but at incorrect positions.\n", correct_position, incorrect_position);
}

void get_player_guess(int guess[CODE_LENGTH]) {
    printf("Enter four numbers (from 1 to 6), separated by spaces: ");
    for (int i = 0; i < CODE_LENGTH; i++) {
        scanf("%d", &guess[i]);
    }
}
