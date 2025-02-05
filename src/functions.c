#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "functions.h"
#include "data.h"
void gen_text(char *text, int num_words, int difficulty) {
    int size = sizeof(words) / sizeof(words[0]);
    strcpy(text, "");
    for (int i = 0; i < num_words; ++i) {
        char word[20];
        strcpy(word, words[rand() % size]);
        if(difficulty==1){
            // Easy
            if(strlen(word) >= 1 && strlen(word) < 5){
                strcat(text, word);
                strcat(text, " ");
            }
            else{
                i--;
            }
        }
        else if(difficulty==2){
            // Medium
            if(strlen(word) >= 5 && strlen(word) < 8){
                strcat(text, word);
                strcat(text, " ");
            }
            else{
                i--;
            }
        }
        else if(difficulty==3){
            // Hard
            if(strlen(word) >= 8){
                strcat(text, word);
                strcat(text, " ");
            }
            else{
                i--;
            }
        }
    }

    strcat(text, "\n");
    text[strlen(text)-1] = '\0';
}

void myPrint(int attribute, const char *format, ...) {
    attron(attribute);
    va_list args;
    va_start(args, format);
    vw_printw(stdscr, format, args);
    va_end(args);
    attroff(attribute);
}

void myMvPrint(int y, int x, int attrs, const char *format, ...) {
    attron(attrs);
    va_list args;
    va_start(args, format);
    move(y, x);
    vw_printw(stdscr, format, args);
    va_end(args);
    attroff(attrs);
}

