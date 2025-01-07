#ifndef GAME_H
#define GAME_H

#define CODE_LENGTH 4
#define NUM_COLORS 6
#define MAX_ATTEMPTS 10

void generate_code(int code[CODE_LENGTH]);

void check_guess(int code[CODE_LENGTH], int guess[CODE_LENGTH], int *correct_position, int *incorrect_position);

void print_feedback(int correct_position, int incorrect_position);

void get_player_guess(int guess[CODE_LENGTH]);

#endif
