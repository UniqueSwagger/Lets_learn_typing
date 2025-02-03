#include "data.h"
#include <stdio.h>
#include <string.h>

char words[200][20];
void load_word_pool() {
    int i = 0;
    while (scanf("%19s", words[i]) == 1 && i < 200) {
        i++;
    }
}