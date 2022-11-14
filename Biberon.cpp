#include "Biberon.h"
#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const string week[7]{ "Mon", "Tue", "Wednesday","Thu", "Fri", "Sat", "Sun" };

Biberon::Biberon() {
    this->quantity = 0;
    this->vomit = false;
    this->clock = 0;
    this->give = true;
    this->day = week[0];
    firstDrink();
}

Biberon::~Biberon() {
}

void Biberon::Test() {
    cout << this->day;
}

void Biberon::firstDrink() {
    char answer;
    cout << "Hello did you have finished to give milk to the baby ? y or n\n";
    cin >> answer;
    if (answer == 'y') {
        this->quantity = 0;
        cout << "\ngreat! the reminder for the next baby bottel is set in 4hour.\n";
        this->quantity = this->quantity + 1;
        this->clock = 240;
        this->give = false;
        Timer();
    }
    else {
        cout << "Tell us when you have give the bay bottel.";
    }
}

void Biberon::Timer() {
    time_t curr_time;;
    string current_day;
    int sec;
    int alarm = NULL;
    while (this->give == false) {
        curr_time = time(NULL);
        char* tm = ctime(&curr_time);
        string timer = tm;
        string save_day;
        string cont;
        if (current_day == "") {
            for (unsigned int i = 0; i < 3; i++) { //check day
                char c = timer[i];
                current_day = current_day + c;
            }
            for (unsigned int i = 17; i < 20; i++) {
                char s = timer[i];
                cont = cont + s;
            }
            sec =  stoi(cont);
            alarm = sec + 8;
            cout << sec;
            cout << "\n alarm set at " << alarm;
            save_day = current_day;
            cout << "\ncurrent day register : " << save_day << "\n\n";
        }
        if (alarm != NULL) {
            for (unsigned int i = 17; i < 20; i++) {
                char s = timer[i];
                cont = cont + s;
            }
            sec = stoi(cont);
            if (sec == alarm) {
                char answer;
                cout << "\nDrinnnnnnng    Drinnnnnng";
                cout << "\n did you have finished to give milk to the baby ? y or n";
                cin >> answer;
                if (answer == 'y') {
                    this->give == false;
                }
            }
        }
        cout << tm;
        _sleep(1000);
    }

}

int main() {
    Biberon* main_biberon = new Biberon();
    return 0;
}