/**
 * Ryndin_task.cpp
 * Головна програма — Задача 9.4
 * Лабораторна робота №9, Варіант 2
 * Студент: Риндін Олександр
 */

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <windows.h>
#include "ModulesRyndin.h"

static void flushInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static int isExitChar(int ch)
{
    unsigned char uc = (unsigned char)ch;
    return (ch == 'y' || ch == 'Y' ||
            uc == 0xEDu ||   /* 'н' CP1251 */
            uc == 0xADu);    /* 'н' CP866  */
}

/* s_calculation (ЛР №8, Варіант 1)
 * Формула: |sin(|y - z²|) + √x - √|(y·z)^x + y/(2π)||*/
static void run_s_calculation(void)
{
    double x, y, z;
    printf("\n=== s_calculation (Лабораторна робота №8) ===\n");
    printf("Формула: |sin(|y - z^2|) + sqrt(x) - sqrt(|(y*z)^x + y/(2*PI)|)|\n");
    printf("Введiть x: ");
    if (scanf("%lf", &x) != 1) { printf("Помилка!\n"); flushInput(); return; }
    printf("Введiть y: ");
    if (scanf("%lf", &y) != 1) { printf("Помилка!\n"); flushInput(); return; }
    printf("Введiть z: ");
    if (scanf("%lf", &z) != 1) { printf("Помилка!\n"); flushInput(); return; }
    flushInput();

    double s = s_calculation(x, y, z);
    printf("s_calculation(%.4f, %.4f, %.4f) = %.6f\n", x, y, z, s);
}

/* Задача 9.1*/
static void run_task9_1(void)
{
    int grade;
    printf("\n=== ЗАДАЧА 9.1 — Шкала хвилювання ВМО ===\n");
    printf("Введiть бал хвилювання (0-9): ");
    if (scanf("%d", &grade) != 1) {
        printf("Помилка введення!\n"); flushInput(); return;
    }
    flushInput();

    WaveInfo wi = task9_1(grade);
    if (wi.description == NULL) {
        printf("Помилка: бал повинен бути у дiапазонi 0-9.\n");
        return;
    }
    printf("Опис хвилювання : %s\n", wi.description);
    if (wi.heightMax < 0.0f)
        printf("Висота хвилi    : понад %.2f м\n", wi.heightMin);
    else if (wi.heightMin == 0.0f && wi.heightMax == 0.0f)
        printf("Висота хвилi    : 0 м (дзеркальна гладiнь)\n");
    else
        printf("Висота хвилi    : %.2f - %.2f м\n", wi.heightMin, wi.heightMax);
}

/* Задача 9.2 */
static void run_task9_2(void)
{
    int n;
    printf("\n=== ЗАДАЧА 9.2 — Аналiз масиву чисел ===\n");
    printf("Введiть кiлькiсть чисел n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Помилка: n повинно бути натуральним числом.\n");
        flushInput(); return;
    }
    flushInput();

    double *arr = (double *)malloc(n * sizeof(double));
    if (!arr) { printf("Помилка видiлення пам'ятi!\n"); return; }

    printf("Введiть %d чисел:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("  [%d]: ", i + 1);
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Помилка введення!\n");
            flushInput(); free(arr); return;
        }
    }
    flushInput();

    int negCount = 0, zeroCount = 0, rangeCount = 0;
    task9_2(arr, n, &negCount, &zeroCount, &rangeCount);
    free(arr);

    printf("\nРезультати:\n");
    printf("  Вiд'ємних чисел           : %d\n", negCount);
    printf("  Чисел, рiвних нулю        : %d\n", zeroCount);
    printf("  Чисел у дiапазонi [5,1024]: %d\n", rangeCount);
}

/*  Задача 9.3*/
static void run_task9_3(void)
{
    int N;
    printf("\n=== ЗАДАЧА 9.3 — Аналiз двiйкового запису ===\n");
    printf("Введiть натуральне число N (0-70700): ");
    if (scanf("%d", &N) != 1 || N < 0 || N > 70700) {
        printf("Помилка: N повинно бути у дiапазонi 0-70700.\n");
        flushInput(); return;
    }
    flushInput();

    int d1     = (N >> 1) & 1;
    int result = task9_3(N);

    printf("Двiйковий запис N = %d:\n  ", N);
    for (int i = 16; i >= 0; --i)
        printf("%d", (N >> i) & 1);
    printf("\n");
    printf("Значення бiта D1 : %d\n", d1);
    if (d1 == 1)
        printf("D1 = 1 -> кiлькiсть двiйкових НУЛIВ : %d\n", result);
    else
        printf("D1 = 0 -> кiлькiсть двiйкових ОДИНИЦЬ: %d\n", result);
}

/* ГОЛОВНА ФУНКЦIЯ — Задача 9.4 */
int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    printf("============================================\n");
    printf("  Лабораторна робота №9 | Варiант 2\n");
    printf("  Студент: Риндiн Олександр\n");
    printf("============================================\n");

    int running = 1;
    while (running) {
        printf("\nВведiть символ команди:\n");
        printf("  q - s_calculation (ЛР №8)\n");
        printf("  e - Задача 9.1 (шкала хвилювання ВМО)\n");
        printf("  r - Задача 9.2 (аналiз масиву)\n");
        printf("  t - Задача 9.3 (двiйковий аналiз)\n");
        printf("> ");

        int ch = getchar();
        flushInput();

        switch (ch) {
            case 'q': run_s_calculation(); break;
            case 'e': run_task9_1();       break;
            case 'r': run_task9_2();       break;
            case 't': run_task9_3();       break;
            default:
                printf("\a");
                printf("Помилкове введення! Допустимi символи: q, e, r, t\n");
                continue;
        }

        printf("\nВийти з програми? (y/Y/н - так, будь-що iнше - нi): ");
        int answer = getchar();
        flushInput();
        if (isExitChar(answer))
            running = 0;
    }

    printf("\nПрограму завершено. До побачення!\n");
    return 0;
}
