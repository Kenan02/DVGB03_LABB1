
#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <time.h>
#include <math.h>
#include <stdbool.h>

typedef void (*sortFunc)(int *a, int n);
typedef bool (*searchFunc)(int *a, int n, int v);

double sortTime(sortFunc func, int *a, int n);
double searchTime(searchFunc func, int *a, int n, int v);

// T through N
double TtN(double value, int n);

// T/(N/2)
double TtN2(double value, int n);

// T/logN
double logN(double value, int n);

// T/(N*logN)
double TtNlogN(double value, int n);

// T/N^2
double Np2(double value, int n);

// N^3
double Np3(double value, int n);
// T/1
double T_one(double value, int n);

#endif