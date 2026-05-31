#ifndef MODULESRYNDIN_H_INCLUDED
#define MODULESRYNDIN_H_INCLUDED

#include <string>

double s_calculation(double x, double y, double z);

// Задача 10.1: записати авторську інф-цію, кількість абзаців, пошук слів
void task10_1(const std::string& inputFile, const std::string& outputFile);

// Задача 10.2: дописати кількість знаків пунктуації, дату та час
void task10_2(const std::string& inputFile);

// Задача 10.3: дописати результат s_calculation та число b у двійковому коді
void task10_3(const std::string& outputFile, double x, double y, double z, int b);

#endif
