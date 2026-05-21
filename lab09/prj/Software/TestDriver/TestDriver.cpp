/**
 * TestDriver.cpp
 * Тестовий драйвер — модульне тестування (Unit Testing)
 * функцій задач 9.1, 9.2, 9.3 зі статичної бібліотеки
 * libModulesRyndin.a
 *
 * Лабораторна робота №9, Варіант 2
 * Студент: Риндін Олександр
 *
 * Формат виведення кожного тест-кейса:
 *   [TC-XXX] Опис | Аргументи | Результат | PASSED / FAILED
 *
 * Компіляція (приклад):
 *   g++ TestDriver.cpp modules_ryndin.cpp -o TestDriver
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include "ModulesRyndin.h"

/* ================================================================
 * Лічильники результатів
 * ================================================================ */
static int g_total  = 0;
static int g_passed = 0;
static int g_failed = 0;

/* ----------------------------------------------------------------
 * Макрос-помічник: вивід рядка результату та оновлення лічильників
 * ---------------------------------------------------------------- */
static void reportResult(const char *tcId,
                         const char *description,
                         int         passed)
{
    g_total++;
    if (passed) {
        g_passed++;
        printf("[%s] %-55s --> PASSED\n", tcId, description);
    } else {
        g_failed++;
        printf("[%s] %-55s --> FAILED  ***\n", tcId, description);
    }
}

/* ================================================================
 *  ТЕСТУВАННЯ ЗАДАЧІ 9.1
 *  task9_1(int grade) -> WaveInfo
 * ================================================================ */
static void testTask9_1(void)
{
    printf("\n");
    printf("================================================================\n");
    printf("  МОДУЛЬНЕ ТЕСТУВАННЯ — ЗАДАЧА 9.1 (Шкала хвилювання ВМО)\n");
    printf("================================================================\n");

    WaveInfo wi;
    char buf[128];

    /* TC-101: grade = 0 → CALM-GLASSY, висота 0–0 м */
    wi = task9_1(0);
    snprintf(buf, sizeof(buf),
             "grade=0 | опис=%s | hMin=%.2f hMax=%.2f",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-101", buf,
        wi.description != NULL &&
        strcmp(wi.description, "CALM-GLASSY") == 0 &&
        fabs(wi.heightMin) < 1e-4f &&
        fabs(wi.heightMax) < 1e-4f);

    /* TC-102: grade = 1 → CALM-RIPPLED, 0.00–0.10 м */
    wi = task9_1(1);
    snprintf(buf, sizeof(buf),
             "grade=1 | опис=%s | hMin=%.2f hMax=%.2f",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-102", buf,
        wi.description != NULL &&
        strcmp(wi.description, "CALM-RIPPLED") == 0 &&
        fabs(wi.heightMin - 0.00f) < 1e-4f &&
        fabs(wi.heightMax - 0.10f) < 1e-4f);

    /* TC-103: grade = 3 → SLIGHT, 0.50–1.25 м */
    wi = task9_1(3);
    snprintf(buf, sizeof(buf),
             "grade=3 | опис=%s | hMin=%.2f hMax=%.2f",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-103", buf,
        wi.description != NULL &&
        strcmp(wi.description, "SLIGHT") == 0 &&
        fabs(wi.heightMin - 0.50f) < 1e-4f &&
        fabs(wi.heightMax - 1.25f) < 1e-4f);

    /* TC-104: grade = 5 → ROUGH, 2.50–4.00 м */
    wi = task9_1(5);
    snprintf(buf, sizeof(buf),
             "grade=5 | опис=%s | hMin=%.2f hMax=%.2f",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-104", buf,
        wi.description != NULL &&
        strcmp(wi.description, "ROUGH") == 0 &&
        fabs(wi.heightMin - 2.50f) < 1e-4f &&
        fabs(wi.heightMax - 4.00f) < 1e-4f);

    /* TC-105: grade = 9 → PHENOMENAL, hMax < 0 (понад 14 м) */
    wi = task9_1(9);
    snprintf(buf, sizeof(buf),
             "grade=9 | опис=%s | hMin=%.2f hMax=%.2f (has to be <0)",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-105", buf,
        wi.description != NULL &&
        strcmp(wi.description, "PHENOMENAL") == 0 &&
        fabs(wi.heightMin - 14.00f) < 1e-4f &&
        wi.heightMax < 0.0f);

    /* TC-106: grade = -1 → некоректний, description == NULL */
    wi = task9_1(-1);
    snprintf(buf, sizeof(buf),
             "grade=-1 (некоректний) | description має бути NULL: %s",
             wi.description ? wi.description : "NULL");
    reportResult("TC-106", buf, wi.description == NULL);

    /* TC-107: grade = 10 → некоректний, description == NULL */
    wi = task9_1(10);
    snprintf(buf, sizeof(buf),
             "grade=10 (некоректний) | description має бути NULL: %s",
             wi.description ? wi.description : "NULL");
    reportResult("TC-107", buf, wi.description == NULL);

    /* TC-108: grade = 7 → HIGH, 6.00–9.00 м */
    wi = task9_1(7);
    snprintf(buf, sizeof(buf),
             "grade=7 | опис=%s | hMin=%.2f hMax=%.2f",
             wi.description ? wi.description : "NULL",
             (double)wi.heightMin, (double)wi.heightMax);
    reportResult("TC-108", buf,
        wi.description != NULL &&
        strcmp(wi.description, "HIGH") == 0 &&
        fabs(wi.heightMin - 6.00f) < 1e-4f &&
        fabs(wi.heightMax - 9.00f) < 1e-4f);
}

/* ================================================================
 *  ТЕСТУВАННЯ ЗАДАЧІ 9.2
 *  task9_2(double*, int, int*, int*, int*)
 * ================================================================ */
static void testTask9_2(void)
{
    printf("\n");
    printf("================================================================\n");
    printf("  МОДУЛЬНЕ ТЕСТУВАННЯ — ЗАДАЧА 9.2 (Аналіз масиву)\n");
    printf("================================================================\n");

    int neg, zero, range;
    char buf[128];

    /* TC-201: порожній масив → всі лічильники = 0 */
    {
        double arr[] = {0.0};   /* фіктивний, n=0 */
        task9_2(arr, 0, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "n=0 | neg=%d zero=%d range=%d (очікувано 0 0 0)",
                 neg, zero, range);
        reportResult("TC-201", buf, neg == 0 && zero == 0 && range == 0);
    }

    /* TC-202: масив {-3, 0, 7, 1024, 1025} →
       neg=1, zero=1, range=2 (7 і 1024) */
    {
        double arr[] = {-3.0, 0.0, 7.0, 1024.0, 1025.0};
        task9_2(arr, 5, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{-3,0,7,1024,1025} | neg=%d zero=%d range=%d"
                 " (оч.: 1 1 2)", neg, zero, range);
        reportResult("TC-202", buf,
                     neg == 1 && zero == 1 && range == 2);
    }

    /* TC-203: масив {5.0, 500.0, 1024.0} → neg=0, zero=0, range=3 */
    {
        double arr[] = {5.0, 500.0, 1024.0};
        task9_2(arr, 3, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{5,500,1024} | neg=%d zero=%d range=%d (оч.: 0 0 3)",
                 neg, zero, range);
        reportResult("TC-203", buf,
                     neg == 0 && zero == 0 && range == 3);
    }

    /* TC-204: масив {4.999, 1024.001} → поза [5,1024], range=0 */
    {
        double arr[] = {4.999, 1024.001};
        task9_2(arr, 2, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{4.999,1024.001} | neg=%d zero=%d range=%d (оч.: 0 0 0)",
                 neg, zero, range);
        reportResult("TC-204", buf,
                     neg == 0 && zero == 0 && range == 0);
    }

    /* TC-205: масив із кількома нулями {0, -0.0, 1e-13} → zero=3 */
    {
        double arr[] = {0.0, -0.0, 1e-13};
        task9_2(arr, 3, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{0,-0,1e-13} | neg=%d zero=%d range=%d (оч.: 0 3 0)",
                 neg, zero, range);
        reportResult("TC-205", buf,
                     neg == 0 && zero == 3 && range == 0);
    }

    /* TC-206: масив {-100, -0.001, -1e-5} → neg=3, zero=0, range=0 */
    {
        double arr[] = {-100.0, -0.001, -1e-5};
        task9_2(arr, 3, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{-100,-0.001,-1e-5} | neg=%d zero=%d range=%d"
                 " (оч.: 3 0 0)", neg, zero, range);
        reportResult("TC-206", buf,
                     neg == 3 && zero == 0 && range == 0);
    }

    /* TC-207: граничні значення {5.0, 1024.0} → range=2 */
    {
        double arr[] = {5.0, 1024.0};
        task9_2(arr, 2, &neg, &zero, &range);
        snprintf(buf, sizeof(buf),
                 "{5.0,1024.0} (межі) | range=%d (оч.: 2)", range);
        reportResult("TC-207", buf, range == 2);
    }
}

/* ================================================================
 *  ТЕСТУВАННЯ ЗАДАЧІ 9.3
 *  task9_3(int N) -> int
 * ================================================================ */
static void testTask9_3(void)
{
    printf("\n");
    printf("================================================================\n");
    printf("  МОДУЛЬНЕ ТЕСТУВАННЯ — ЗАДАЧА 9.3 (Двійковий аналіз)\n");
    printf("================================================================\n");

    int res;
    char buf[128];

    /*
     * N=0: bin(17 біт) = 00000000000000000
     *      D1 = (0>>1)&1 = 0
     *      D1=0 → рахуємо одиниці → 0 одиниць
     */
    res = task9_3(0);
    snprintf(buf, sizeof(buf),
             "N=0 | D1=0 → кількість ОДИНИЦЬ=%d (оч.: 0)", res);
    reportResult("TC-301", buf, res == 0);

    /*
     * N=1: bin = 00000000000000001
     *      D1 = (1>>1)&1 = 0
     *      D1=0 → рахуємо одиниці → 1 одиниця
     */
    res = task9_3(1);
    snprintf(buf, sizeof(buf),
             "N=1 | D1=0 → кількість ОДИНИЦЬ=%d (оч.: 1)", res);
    reportResult("TC-302", buf, res == 1);

    /*
     * N=2: bin = 00000000000000010
     *      D1 = (2>>1)&1 = 1
     *      D1=1 → рахуємо нулі → 16 нулів (з 17 біт, одна '1')
     */
    res = task9_3(2);
    snprintf(buf, sizeof(buf),
             "N=2 | D1=1 → кількість НУЛІВ=%d (оч.: 16)", res);
    reportResult("TC-303", buf, res == 16);

    /*
     * N=5: bin = 00000000000000101
     *      D1 = (5>>1)&1 = (2)&1 = 0
     *      D1=0 → рахуємо одиниці → 2 одиниці
     */
    res = task9_3(5);
    snprintf(buf, sizeof(buf),
             "N=5 | D1=0 → кількість ОДИНИЦЬ=%d (оч.: 2)", res);
    reportResult("TC-304", buf, res == 2);

    /*
     * N=6: bin = 00000000000000110
     *      D1 = (6>>1)&1 = (3)&1 = 1
     *      D1=1 → рахуємо нулі → 15 нулів (дві '1')
     */
    res = task9_3(6);
    snprintf(buf, sizeof(buf),
             "N=6 | D1=1 → кількість НУЛІВ=%d (оч.: 15)", res);
    reportResult("TC-305", buf, res == 15);

    /*
     * N=7: bin = 00000000000000111
     *      D1 = (7>>1)&1 = (3)&1 = 1
     *      D1=1 → рахуємо нулі → 14 нулів (три '1')
     */
    res = task9_3(7);
    snprintf(buf, sizeof(buf),
             "N=7 | D1=1 → кількість НУЛІВ=%d (оч.: 14)", res);
    reportResult("TC-306", buf, res == 14);

    /*
     * N=70700: bin = 10001010000101100
     *   D1 = (70700>>1) & 1 = 35350 & 1 = 0
     *   Кількість одиниць у 70700 (17 біт):
     *   70700 = 0x114AC = 0001 0001 0100 1010 1100
     *   Порахуємо: 1+0+0+0+1+0+1+0+0+1+0+1+0+1+1+0+0 = 6 одиниць
     *   Але 17 біт: 0 0001 0001 0100 1010 1100
     *   1+0+0+0+1+0+1+0+0+1+0+1+0+1+1+0+0 = 6
     */
    {
        /* Порахуємо еталонне значення вручну */
        int expected = 0;
        for (int i = 0; i < 17; ++i)
            expected += (70700 >> i) & 1;
        int d1_70700 = (70700 >> 1) & 1;
        /* d1=0 → рахуємо одиниці */
        res = task9_3(70700);
        snprintf(buf, sizeof(buf),
                 "N=70700 | D1=%d → %s=%d (оч.: %d)",
                 d1_70700,
                 d1_70700 ? "НУЛІВ" : "ОДИНИЦЬ",
                 res,
                 d1_70700 ? (17 - expected) : expected);
        int ok = d1_70700
                 ? (res == 17 - expected)
                 : (res == expected);
        reportResult("TC-307", buf, ok);
    }

    /*
     * N=4: bin = 00000000000000100
     *      D1 = (4>>1)&1 = (2)&1 = 0
     *      D1=0 → рахуємо одиниці → 1 одиниця
     */
    res = task9_3(4);
    snprintf(buf, sizeof(buf),
             "N=4 | D1=0 → кількість ОДИНИЦЬ=%d (оч.: 1)", res);
    reportResult("TC-308", buf, res == 1);
}

/* ================================================================
 * ГОЛОВНА ФУНКЦІЯ ТЕСТОВОГО ДРАЙВЕРА
 * ================================================================ */
int main(void)
{
    printf("================================================================\n");
    printf("  TestDriver — Лабораторна робота №9, Варіант 2\n");
    printf("  Студент: Риндін Олександр\n");
    printf("  Бібліотека: libModulesRyndin\n");
    printf("================================================================\n");

    testTask9_1();
    testTask9_2();
    testTask9_3();

    printf("\n");
    printf("================================================================\n");
    printf("  ПІДСУМОК ТЕСТУВАННЯ\n");
    printf("  Всього тест-кейсів : %d\n", g_total);
    printf("  PASSED             : %d\n", g_passed);
    printf("  FAILED             : %d\n", g_failed);
    printf("  Результат          : %s\n",
           g_failed == 0 ? "ВСІ ТЕСТИ ПРОЙДЕНО" : "Є ПОМИЛКИ — перевірте FAILED");
    printf("================================================================\n");

    return (g_failed == 0) ? 0 : 1;
}
