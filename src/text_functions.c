#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "text_functions.h"
#include "text_data.h"

void generate_text(char *text, int num_words) {
    int size = sizeof(words) / sizeof(words[0]);
    strcpy(text, "");

    for (int i = 0; i <= num_words; ++i) {
        strcat(text, words[rand() % size]);
        strcat(text, " ");
    }

    text[strlen(text) - 1] = '\0';
}

void printwa(int attribute, const char *format, ...) {
    attron(attribute);
    va_list args;
    va_start(args, format);
    vw_printw(stdscr, format, args);
    va_end(args);
    attroff(attribute);
}

void mvprintwa(int y, int x, int attrs, const char *format, ...) {
    attron(attrs);
    va_list args;
    va_start(args, format);
    move(y, x);
    vw_printw(stdscr, format, args);
    va_end(args);
    attroff(attrs);
}

