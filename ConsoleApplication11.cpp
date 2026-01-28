#include <iostream>
#include <vector>
#include <limits>
#include "student.h"

using namespace std;

vector<Student> students;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void add() {
    string name;
    int bookNum;

    cout << "Имя: ";
    cin >> name;

    cout << "Номер зачетки: ";
    while (!(cin >> bookNum)) {
        cout << "Введите число: ";
        clearInput();
    }
    clearInput();

    Student s(name, bookNum);

    cout << "Количество предметов: ";
    int subjCount;
    while (!(cin >> subjCount)) {
        cout << "Введите число: ";
        clearInput();
    }
    clearInput();

    for (int j = 0; j < subjCount; j++) {
        string subjName;
        cout << "Предмет " << j + 1 << ": ";
        getline(cin, subjName);
        s.book.addSubject(Subject(subjName));
    }

    students.push_back(s);
    cout << "Студент добавлен" << endl;
}

void showAll() {
    if (students.empty()) {
        cout << "Список пуст" << endl;
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        cout << "\nСтудент " << i + 1 << "\n";
        cout << "Имя: " << students[i].name << "\n";
        cout << "Номер зачетки: " << students[i].book.number << "\n";
        cout << "Предметы: ";

        for (const auto& subj : students[i].book.subjects) {
            cout << subj.name << ", ";
        }
        cout << "\n";
    }
}

void search() {
    if (students.empty()) {
        cout << "Список пуст" << endl;
        return;
    }

    vector<string> required;
    string subj;

    cout << "Введите предметы (для завершения 'stop'):" << endl;
    clearInput();  
    while (true) {
        cout << "Предмет " << required.size() + 1 << ": ";
        getline(cin, subj);
        if (subj == "stop") break;
        if (!subj.empty()) { 
            required.push_back(subj);
        }
    }

    if (required.empty()) {
        cout << "Не указаны предметы для поиска!\n";
        return;
    }

    vector<int> result;
    for (auto& s : students) {
        bool hasAll = true;
        for (auto& req : required) {
            bool found = false;
            for (auto& subj : s.book.subjects) {
                if (subj.name == req) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                hasAll = false;
                break;
            }
        }
        if (hasAll) {
            result.push_back(s.book.number);
        }
    }

    if (result.empty()) {
        cout << "Студенты не найдены" << endl;
    }
    else {
        cout << "Номера зачеток: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "\n1. Добавить студента" << endl;
        cout << "2. Показать всех студентов" << endl;
        cout << "3. Найти студентов по предметам" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            showAll();
            break;
        case 3:
            search();
            break;
        case 4:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Неверный выбор" << endl;
        }
    } while (choice != 4);

    return 0;
}