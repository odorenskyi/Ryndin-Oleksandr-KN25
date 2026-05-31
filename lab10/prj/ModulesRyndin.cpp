#include "ModulesRyndin.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <iterator>

double s_calculation(double x, double y, double z) {
    const double PI = 3.141592653589793;
    double part1 = std::sin(std::abs(y - std::pow(z, 2)));
    double part2 = std::sqrt(x);
    double part3 = std::sqrt(std::abs(std::pow(y * z, x) + y / (2 * PI)));
    return std::abs(part1 + part2 - part3);
}

void task10_1(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);
    if (!fin.is_open() || !fout.is_open()) {
        std::cerr << "Помилка відкриття файлу." << std::endl;
        return;
    }
    fout << "Автор: Риндін Олександр Олексійович" << std::endl;
    fout << "Організація: ЦНТУ, КН-25" << std::endl;
    fout << "Місто: Кропивницький, Україна" << std::endl;
    fout << "Рік: 2026" << std::endl << std::endl;

    std::string text((std::istreambuf_iterator<char>(fin)),
                      std::istreambuf_iterator<char>());
    fin.close();

    int paragraphs = 0;
    std::istringstream iss(text);
    std::string line;
    while (std::getline(iss, line))
        if (!line.empty()) paragraphs++;
    fout << "Кількість абзаців: " << paragraphs << std::endl << std::endl;

    auto containsWord = [&](const std::string& word) {
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != std::string::npos) {
            bool leftOk  = (pos == 0 || !isalpha((unsigned char)text[pos-1]));
            bool rightOk = (pos+word.size() >= text.size() ||
                           !isalpha((unsigned char)text[pos+word.size()]));
            if (leftOk && rightOk) return true;
            pos++;
        }
        return false;
    };
    fout << "Слово 'Україна':     " << (containsWord("Україна")     ? "є" : "немає") << std::endl;
    fout << "Слово 'університет': " << (containsWord("університет") ? "є" : "немає") << std::endl;
    fout << "Слово 'блокнот':     " << (containsWord("блокнот")     ? "є" : "немає") << std::endl;
    fout.close();
}

void task10_2(const std::string& inputFile) {
    std::ifstream fin2(inputFile);
    std::string text((std::istreambuf_iterator<char>(fin2)),
                      std::istreambuf_iterator<char>());
    fin2.close();

    int punct = 0;
    std::string signs = ".,!?;:-\"\'()«»";
    for (char c : text)
        if (signs.find(c) != std::string::npos) punct++;

    time_t now = time(nullptr);
    char buf[64];
    strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", localtime(&now));

    std::ofstream f(inputFile, std::ios::app);
    if (!f.is_open()) { std::cerr << "Помилка відкриття файлу." << std::endl; return; }
    f << std::endl << "Кількість знаків пунктуації: " << punct << std::endl;
    f << "Дата та час дозапису: " << buf << std::endl;
    f.close();
}

void task10_3(const std::string& outputFile, double x, double y, double z, int b) {
    std::ofstream f(outputFile, std::ios::app);
    if (!f.is_open()) { std::cerr << "Помилка відкриття файлу." << std::endl; return; }
    double result = s_calculation(x, y, z);
    f << std::endl << "s_calculation(" << x << ", " << y << ", " << z << ") = " << result << std::endl;
    f << "Число " << b << " у двійковому коді: ";
    if (b == 0) { f << "0"; }
    else {
        std::string bits = "";
        unsigned int n = (unsigned int)b;
        while (n > 0) { bits = (char)('0' + n % 2) + bits; n /= 2; }
        f << bits;
    }
    f << std::endl;
    f.close();
}
