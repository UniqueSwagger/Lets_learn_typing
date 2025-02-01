#include "typing_test.h"
#include "ncurses.h"
#include "text_functions.h"

void initialize_colors() {
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_WHITE, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_MAGENTA, -1);
}

void process_input(char *text, char *input, size_t *pos, int *words, int *correct_symbols, int *mistakes_count) {
    int ch = getch();

    if (ch == 127 || ch == KEY_BACKSPACE) {
        if (*pos > 0) {
            (*pos)--;
            if (text[*pos] == ' ') {
                (*words)++;
            } else if (input[*pos] == text[*pos]) {
                (*correct_symbols)--;
            } else {
                (*mistakes_count)--;
            }

            input[*pos] = '\0';
        }
    } else {
        if (text[*pos] == ' ') {
            (*words)--;
        } else if (ch == text[*pos]) {
            (*correct_symbols)++;
        } else {
            (*mistakes_count)++;
        }

        input[(*pos)++] = ch;
        input[*pos] = '\0';
    }
}

void update_screen(char *text, char *input, size_t pos, int correct_symbols, int words, int mistakes_count, time_t start_time) {
    mvprintw(4, 0, "%-99s", " ");
    mvprintw(4, 0, "%s", input);

    for (size_t j = 0; j < strlen(text); j++) {
        attron(input[j] == text[j] ? COLOR_PAIR(1) : COLOR_PAIR(2));
        mvaddch(1, j, text[j]);
        attroff(input[j] == text[j] ? COLOR_PAIR(1) : COLOR_PAIR(2));
    }

    mvchgat(1, pos, strlen(text) - pos, A_NORMAL, 3, NULL);
    mvchgat(1, pos, 1, A_NORMAL, 4, NULL);

    time_t time_now = time(NULL);
    double difference = difftime(time_now, start_time);
    double cpm = correct_symbols / (difference / 60);
    double wpm = cpm / 5;
    mvprintwa(5, 0, COLOR_PAIR(1) | A_BOLD, "Words left: %d; Mistakes: %d; WPM: %.0lf; CPM: %.0lf\tTime: %.0lf", words, mistakes_count, wpm, cpm, difference);
    refresh();
}

void reset_input(char *input, char *text, char *next_text, size_t *pos, int words_per_line) {
    *pos = 0;
    strcpy(input, "");
    strcpy(text, next_text);
    generate_text(next_text, words_per_line);

    clear();
    mvprintwa(0, 0, COLOR_PAIR(5), "Type this text:");
    mvprintw(1, 0, "%s", text);
    mvprintw(2, 0, "%s", next_text);
    mvprintwa(3, 0, COLOR_PAIR(5), "Your typing:");
    mvprintw(4, 0, "%-99s", " ");
}

void display_final_stats(int correct_symbols, int mistakes_count, time_t start_time) {
    time_t end_time = time(NULL);
    double test_duration = difftime(end_time, start_time);
    double accurancy = correct_symbols / mistakes_count;
    double cpm = correct_symbols / (test_duration / 60);
    double wpm = cpm / 5;

    clear();
    move(0, 0);
    printwa(COLOR_PAIR(4), "Test completed!\n");
    printw("Correct characters: %d\n", correct_symbols);
    printw("Mistakes: %d\n", mistakes_count);
    printw("Accurancy %lf\n", accurancy);
    printw("Words per minute (WPM): %.2lf\n", wpm);
    printw("Characters per minute (CPM): %.2lf\n", cpm);
    printw("Test duration: %.0lf seconds\n", test_duration);
    printwa(COLOR_PAIR(2), "Press q to exit.");
}

void start_typing_test(int passage_length) {
    char text[100] = "";
    char next_text[100] = "";
    char input[100] = "";
    int words = 100;
    int correct_symbols = 0;
    int mistakes_count = 0;
    int words_per_line = 5;
    size_t pos = 0;

    initialize_colors();

    generate_text(text, words_per_line);
    generate_text(next_text, words_per_line);

    printwa(COLOR_PAIR(4), "Enter any key to start.");
    getch();
    move(0, 0);
    clrtoeol();

    mvprintwa(0, 0, COLOR_PAIR(5), "Type this text:");
    mvprintw(1, 0, "%s", text);
    mvprintw(2, 0, "%s", next_text);
    mvprintwa(3, 0, COLOR_PAIR(5), "Your typing:");


    time_t start_time = time(NULL);

    while (words > 0) {
        process_input(text, input, &pos, &words, &correct_symbols, &mistakes_count);
        update_screen(text, input, pos, correct_symbols, words, mistakes_count, start_time);

        if (pos >= strlen(text)) {
            reset_input(input, text, next_text, &pos, words_per_line);
            update_screen(text, input, pos, correct_symbols, words, mistakes_count, start_time);
        }
    }

    display_final_stats(correct_symbols, mistakes_count, start_time);

    char ch;
    while(true) {
        ch = getch();
        if(ch == 'q') {
            break;
        }
    }
}

