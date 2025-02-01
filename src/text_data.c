#include "text_data.h"
#include <stdio.h>
#include <string.h>

char words[200][20];
void load_word_pool() {
    FILE *file = fopen("word_pool.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    int i = 0;
    while (fscanf(file, "%19s", words[i]) == 1 && i < 200) {
        i++;
    }

    fclose(file);
}
