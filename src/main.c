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
    printw("Select difficulty:\n");
    printw("1. Easy (20 words)\n");
    printw("2. Medium (40 words)\n");
    printw("3. Hard (60 words)\n");
    printw("Press 1, 2 or 3: ");
    refresh();
    int ch = getch();
    int passage_length = 20; // default
    if(ch == '1') {
        passage_length = 20;
    } else if(ch == '2') {
        passage_length = 40;
    } else if(ch == '3') {
        passage_length = 60;
    }
    clear();
    refresh();

    start_typing_test(passage_length);

    endwin();
    return 0;
}

