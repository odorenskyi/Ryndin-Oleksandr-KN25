#include "ModulesRyndin.h"
#include <cmath>

double s_calculation(double x, double y, double z) {
    // Число Пі для точності
    const double PI = 3.141592653589793;
    
    // Розбиваємо формулу на частини для зручності
    double part1 = std::sin(std::abs(y - std::pow(z, 2)));
    double part2 = std::sqrt(x);
    double part3 = std::sqrt(std::abs(std::pow(y * z, x) + y / (2 * PI)));
    
    // Повертаємо підсумковий результат |part1 + part2 - part3|
    return std::abs(part1 + part2 - part3);
}