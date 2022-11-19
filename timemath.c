#include "timemath.h"

double sortTime(sortFunc func, int *a, int n)
{
    double start = clock();
    func(a, n);
    double end = clock();
    double tot = end - start;
    return tot / CLOCKS_PER_SEC;
}

double searchTime(searchFunc func, int *a, int n, int v)
{
    double start = clock();
    func(a, n, v);
    double end = clock();
    double tot = end - start;
    return tot / CLOCKS_PER_SEC;
    return 0;
}

// T through N
double TtN(double value, int n)
{
    return value / n;
}

// T/(N/2)
double TtN2(double value, int n)
{
    return value / (n / 2);
}
// T/logN
double logN(double value, int n)
{
    return value / log10(n);
}

// T/(N*logN)

double TtNlogN(double value, int n)
{

    return value / (n * log10(n));
}

// T/N^2
double Np2(double value, int n)
{
    return value / (n * n);
}

// N^3
double Np3(double value, int n)
{
    return value / (n * n * n);
}

double T_one(double value, int n)
{
    return value / 1;
}