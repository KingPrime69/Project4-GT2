#pragma once

#include <iostream>

using namespace std;

class Biberon {
public:
    Biberon();
    ~Biberon();
    void Test();
    void firstDrink();
    void Timer();

private:
    int quantity;
    bool vomit;
    int clock;
    bool give;
    string day;
};