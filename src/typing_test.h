#pragma once
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void start_typing_test(int passage_length);  // updated signature
void initialize_colors();
void process_input(char *text, char *input, size_t *pos, int *words, int *correct_symbols, int *mistakes_count);
void update_screen(char *text, char *input, size_t pos, int correct_symbols, int words, int mistakes_count, time_t start_time);
void reset_input(char *input, char *text, char *next_text, size_t *pos, int words_per_line);
void display_final_stats(int correct_symbols, int mistakes_count, time_t start_time);

