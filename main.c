#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "computer.h"

int main() {
    int code[CODE_LENGTH];
    int guess[CODE_LENGTH];
    int correct_position, incorrect_position;
    int attempts = 0;

    srand(time(NULL));

    printf("Welcome to the Mastermind game!\n");
    printf("You have 10 attempts to guess the code!\n");

    computer_generate_code(code);

    attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        get_player_guess(guess);
        check_guess(code, guess, &correct_position, &incorrect_position);
        print_feedback(correct_position, incorrect_position);

        if (correct_position == CODE_LENGTH) {
            printf("Congratulations! You guessed the code in %d attempts!\n", attempts + 1);
            break;
        }

        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Sorry, you couldn't guess the code. The code was: ");
        for (int i = 0; i < CODE_LENGTH; i++) {
            printf("%d ", code[i]);
        }
        printf("\n");
    }

    return 0;
}
