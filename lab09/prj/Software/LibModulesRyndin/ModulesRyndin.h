/**
 * ModulesRyndin.h
 * Лабораторна робота №9, Варіант 2
 * Студент: Риндін Олександр
 */

#ifndef MODULESRYNDIN_H
#define MODULESRYNDIN_H

typedef struct {
    float  heightMin;
    float  heightMax;
    const char *description;
} WaveInfo;

WaveInfo task9_1(int grade);

void task9_2(const double *numbers, int n,
             int *negCount, int *zeroCount, int *rangeCount);

int task9_3(int N);

/* З лабораторної роботи №8, Варіант 1 */
double s_calculation(double x, double y, double z);

#endif /* MODULESRYNDIN_H */
