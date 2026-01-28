#pragma once
#include <vector>
#include "subject.h"

using namespace std;

class RecordBook {
public:
    int number;
    vector<Subject> subjects;

    RecordBook(int num = 0) : number(num) {}
    void addSubject(Subject s) { subjects.push_back(s); }
};