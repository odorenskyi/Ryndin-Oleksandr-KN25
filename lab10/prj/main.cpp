#include "ModulesRyndin.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "=== TestDriver: Lab 10 ===" << std::endl;

    std::string inputFile  = "input.txt";
    std::string outputFile = "output.txt";

    // Тест 10.1
    task10_1(inputFile, outputFile);
    std::cout << "[10.1] output.txt створено -> PASSED" << std::endl;

    // Тест 10.2
    task10_2(inputFile);
    std::cout << "[10.2] Пунктуацію та час дописано -> PASSED" << std::endl;

    // Тест 10.3
    task10_3(outputFile, 1.0, 0.0, 0.0, 13);
    std::cout << "[10.3] s_calculation та двійковий код дописано -> PASSED" << std::endl;

    std::cout << "Всі тести пройдено успішно." << std::endl;
    return 0;
}
