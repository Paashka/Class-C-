#pragma once
#include <string>
#include "record_book.h"

using namespace std;

class Student {
public:
    string name;
    RecordBook book;
    Student(string n = "", int num = 0) : name(n), book(num) {}
};