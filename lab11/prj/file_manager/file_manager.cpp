#include "operator_directory.h"
#include <fstream>
#include <sstream>

// Завантаження даних з файлу в пам'ять (вектор)
void loadData(std::vector<OperatorRecord>& directory, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Увага: Не вдалося відкрити файл бази даних. Створено новий порожній довідник.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string code, name;

        // Розділяємо рядок за символом ';'
        if (std::getline(ss, code, ';') && std::getline(ss, name)) {
            directory.push_back({code, name});
        }
    }
    file.close();
}

// Збереження даних з вектора назад у файл (перезапис)
void saveData(const std::vector<OperatorRecord>& directory, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл бази даних для запису.\n";
        return;
    }

    for (const auto& record : directory) {
        file << record.code << ";" << record.name << "\n";
    }
    file.close();
}
