//Timmy Truong
//SYDE 121
//September 12, 2018
#include <iostream>

using namespace std;

int main() {
    int uwaterlooID, age, birthdate;
    string name;

    cout << "Welcome to my first C++ program!" << endl;
    cout << "Below are some questions!" << endl;

    cout << "What is your name?" << endl;
    cin >> name;

    cout << "What is your University of Waterloo ID?" << endl;
    cin >> uwaterlooID;

    cout << "What is your age?" << endl;
    cin >> age;

    cout << "What is your birthday? (FORMAT: DDMMYYYY)" << endl;
    cin >> birthdate;

    cout << "Your name is " << name << '.' << endl;
    cout << "Your University of Waterloo ID is " << uwaterlooID << '.' << endl;
    cout << "You are " << age << " years old." << endl;
    cout << "Your birthday is on " << birthdate << '.' << endl;

    return 0;
}