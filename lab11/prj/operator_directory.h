#ifndef OPERATOR_DIRECTORY_H
#define OPERATOR_DIRECTORY_H

#include <iostream>
#include <string>
#include <vector>

// Спільна структура даних
struct OperatorRecord {
    std::string code;
    std::string name;
};

// --- Функції Розробника 1 ---
void loadData(std::vector<OperatorRecord>& directory, const std::string& filename);
void saveData(const std::vector<OperatorRecord>& directory, const std::string& filename);

// --- Функції Розробника 2 ---
void printDirectory(const std::vector<OperatorRecord>& directory);
void exportToFile(const std::vector<OperatorRecord>& directory, const std::string& exportFilename);

// --- Функції Розробника 3 ---
void searchRecord(const std::vector<OperatorRecord>& directory, const std::string& query);
void addRecord(std::vector<OperatorRecord>& directory);
void deleteRecord(std::vector<OperatorRecord>& directory, const std::string& codeToDelete);

#endif
