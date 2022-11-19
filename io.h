#ifndef IO_H
#define IO_H
#include "analyze.h"

typedef double (*printFunc)(double buf, int n);

// read_line reads at least one and at most n-2 characters from stdin, writing a
// null-terminated result to buf; possible overflows are handled and and the
// length of buf is returned, e.g., 5 for "hello" and 0 on error.
int read_line(char *buf, int n);
void printOut(result_t *buf, printFunc func1, printFunc func2, printFunc func3, int n, char header[], char print1[], char print2[], char print3[]);

#endif
