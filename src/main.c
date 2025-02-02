#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "typing_test.h"
#include "text_data.h"
#include <stdio.h>


int main() {
    // Load word pool from redirected file (e.g., ./typing_game < word_pool.txt)
    load_word_pool();
    freopen("/dev/tty", "r", stdin);
    
    initscr();
    noecho();
    cbreak();
    start_color();
    use_default_colors();
    curs_set(0);
    srand(time(NULL));

    // Prompt for difficulty selection
    clear();
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_WHITE, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);

    int ch;
    do {
        clear();
        attron(COLOR_PAIR(3));
        printw("Select difficulty:\n");
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(4));
        printw("1. Easy (30 words)\n");
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(5));
        printw("2. Medium (60 words)\n");
        attroff(COLOR_PAIR(5));
        attron(COLOR_PAIR(6));
        printw("3. Hard (90 words)\n");
        attroff(COLOR_PAIR(6));
        attron(COLOR_PAIR(3));
        printw("Press 1, 2 or 3: ");
        attroff(COLOR_PAIR(3));
        refresh();
        ch = getch();
        if(ch == 27) {
            endwin();
            return 0;
        }
    } while (ch != '1' && ch != '2' && ch != '3');
    clear();
    refresh();

    start_typing_test(ch - '0');

    endwin();
    return 0;
}

