/**
 * modules_ryndin.cpp
 * Лабораторна робота №9, Варіант 2
 * Студент: Риндін Олександр
 */

#include "ModulesRyndin.h"
#include <cstddef>
#include <cmath>

/*  ЗАДАЧА 9.1 — Шкала хвилювання ВМО */
static const WaveInfo wmoTable[10] = {
    { 0.00f,  0.00f, "CALM-GLASSY"   },
    { 0.00f,  0.10f, "CALM-RIPPLED"  },
    { 0.10f,  0.50f, "SMOOTH-WAVELET"},
    { 0.50f,  1.25f, "SLIGHT"        },
    { 1.25f,  2.50f, "MODERATE"      },
    { 2.50f,  4.00f, "ROUGH"         },
    { 4.00f,  6.00f, "VERY ROUGH"    },
    { 6.00f,  9.00f, "HIGH"          },
    { 9.00f, 14.00f, "VERY HIGH"     },
    {14.00f, -1.00f, "PHENOMENAL"    }
};

WaveInfo task9_1(int grade)
{
    WaveInfo invalid = { 0.0f, 0.0f, NULL };
    if (grade < 0 || grade > 9) return invalid;
    return wmoTable[grade];
}

/*  ЗАДАЧА 9.2 — Аналіз масиву */
void task9_2(const double *numbers, int n,
             int *negCount, int *zeroCount, int *rangeCount)
{
    *negCount = 0; *zeroCount = 0; *rangeCount = 0;
    for (int i = 0; i < n; ++i) {
        double x = numbers[i];
        if (x < 0.0)                  (*negCount)++;
        if (fabs(x) < 1e-12)          (*zeroCount)++;
        if (x >= 5.0 && x <= 1024.0)  (*rangeCount)++;
    }
}

/* ЗАДАЧА 9.3 — Двійковий аналіз */
int task9_3(int N)
{
    const int BITS = 17;
    int d1    = (N >> 1) & 1;
    int count = 0;
    for (int i = 0; i < BITS; ++i) {
        int bit = (N >> i) & 1;
        count += d1 ? (bit == 0 ? 1 : 0)
                    : (bit == 1 ? 1 : 0);
    }
    return count;
}

/* s_calculation — Лабораторна робота №8, Варіант 1
   Формула: |sin(|y - z²|) + √x - √|(y·z)^x + y/(2π)|| */
double s_calculation(double x, double y, double z)
{
    const double PI = 3.141592653589793;

    double part1 = sin(fabs(y - z * z));
    double part2 = sqrt(x);
    double part3 = sqrt(fabs(pow(y * z, x) + y / (2.0 * PI)));

    return fabs(part1 + part2 - part3);
}
