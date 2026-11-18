#include <stdio.h>

/* Print the run-length encoding of one string. */
void print_rle(const char input[]) {
    int position = 0;          /* Index of the run's first character. */

    while (input[position] != '\0') {
        char current = input[position]; /* Character in the current run. */
        int count = 1;                  /* Number of matching characters. */

        /* Look ahead while the next character matches. */
        while (input[position + count] == current) {
            count = count + 1;
        }

        printf("%d%c", count, current);
        position = position + count;
    }
}

/* Run one example and show both its input and encoded output. */
void show_example(const char input[]) {
    printf("%s -> ", input);
    print_rle(input);
    printf("\n");
}

int main(void) {
    /* Repeated characters: the main example compresses well. */
    show_example("AAAAABBBCC");

    /* No repeated neighbors: every run has length 1. */
    show_example("ABCDEFGH");

    /* A mixed example shows that only consecutive matches form a run. */
    show_example("AABCCCCD");

    return 0;
}
