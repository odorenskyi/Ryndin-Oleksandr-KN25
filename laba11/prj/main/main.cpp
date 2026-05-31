#include "operator_directory.h"
#include <fstream>

// Виведення на екран
void printDirectory(const std::vector<OperatorRecord>& directory) {
    std::cout << "\n--- Коди операторів мобільного зв'язку України ---\n";
    for (const auto& record : directory) {
        std::cout << "- " << record.code << " : " << record.name << "\n";
    }
    std::cout << "--------------------------------------------------\n";
}

// Запис у текстовий файл за вибором користувача (експорт/звіт)
void exportToFile(const std::vector<OperatorRecord>& directory, const std::string& exportFilename) {
    std::ofstream file(exportFilename);
    if (file.is_open()) {
        file << "Електронний довідник кодів\n\n";
        for (const auto& record : directory) {
            file << record.code << " - " << record.name << "\n";
        }
        file.close();
        std::cout << "Дані успішно експортовано у файл " << exportFilename << "\n";
    } else {
        std::cerr << "Помилка експорту.\n";
    }
}

int main() {
    std::vector<OperatorRecord> directory;
    const std::string filename = "data.txt";

    // Автоматичне завантаження під час запуску (код Розробника 1)
    loadData(directory, filename);

    int choice;
    do {
        std::cout << "\n1. Пошук запису (за кодом або назвою)\n";
        std::cout << "2. Вивести весь довідник на екран\n";
        std::cout << "3. Записати довідник у текстовий файл (експорт)\n";
        std::cout << "4. Додати новий запис\n";
        std::cout << "5. Вилучити запис\n";
        std::cout << "0. Завершити роботу (зберігає дані)\n";
        std::cout << "Оберіть дію: ";
        std::cin >> choice;

        std::string query;
        switch (choice) {
            case 1:
                std::cout << "Введіть код або назву оператора: ";
                std::cin.ignore(); // Очищення буфера
                std::getline(std::cin, query);
                searchRecord(directory, query); // Виклик коду Розробника 3
                break;
            case 2:
                printDirectory(directory);
                break;
            case 3:
                std::cout << "Введіть назву файлу для збереження (наприклад, export.txt): ";
                std::cin >> query;
                exportToFile(directory, query);
                break;
            case 4:
                addRecord(directory); // Виклик коду Розробника 3
                break;
            case 5:
                std::cout << "Введіть код для вилучення (наприклад, 067): ";
                std::cin >> query;
                deleteRecord(directory, query); // Виклик коду Розробника 3
                break;
            case 0:
                std::cout << "Збереження даних та вихід...\n";
                saveData(directory, filename); // Автоматичне збереження (код Розробника 1)
                break;
            default:
                std::cout << "Невірна команда. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
