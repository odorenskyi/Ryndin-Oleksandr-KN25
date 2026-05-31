#include "operator_directory.h"
#include <algorithm>

// Пошук за кодом АБО за назвою
void searchRecord(const std::vector<OperatorRecord>& directory, const std::string& query) {
    bool found = false;
    for (const auto& record : directory) {
        if (record.code == query || record.name == query) {
            std::cout << "=> Знайдено: Код: " << record.code << " | Оператор: " << record.name << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "=> Запис за таким запитом не знайдено.\n";
    }
}

// Додавання нового запису
void addRecord(std::vector<OperatorRecord>& directory) {
    OperatorRecord newRecord;
    std::cout << "Введіть код оператора (наприклад, 063): ";
    std::cin >> newRecord.code;

    std::cin.ignore(); // Очищення буфера після вводу слова

    std::cout << "Введіть назву оператора (наприклад, life:)): ";
    std::getline(std::cin, newRecord.name);

    directory.push_back(newRecord);
    std::cout << "=> Запис успішно додано.\n";
}

// Вилучення запису за заданим кодом
void deleteRecord(std::vector<OperatorRecord>& directory, const std::string& codeToDelete) {
    auto it = std::remove_if(directory.begin(), directory.end(),
                             [&](const OperatorRecord& record) { return record.code == codeToDelete; });

    if (it != directory.end()) {
        directory.erase(it, directory.end());
        std::cout << "=> Запис з кодом " << codeToDelete << " успішно вилучено.\n";
    } else {
        std::cout << "=> Запис з кодом " << codeToDelete << " не знайдено.\n";
    }
}
