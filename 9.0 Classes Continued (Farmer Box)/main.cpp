#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include "box.hpp"
#include "produce.hpp"
#include "produce.cpp"
#include "box.cpp"

using namespace std;

void test_fill();
void test_produce();
void run();

int main () {
    run();
    return 0;
}

void test_fill() {

    FruitsAndVeggiesBox small_box(5);
    small_box.fill_the_box(3);

    cout << "***************************LIST OF ALL PRODUCE***************************" << endl;
    small_box.print_all_produce();
    cout << "***************************LIST OF ALL PRODUCE END***************************" << endl;

    cout << endl;

    cout << "***************************SMALL BOX TEST***************************" << endl;
    small_box.print();
    cout << "***************************SMALL BOX TEST END***************************" << endl;

    cout << endl;

    FruitsAndVeggiesBox medium_box(10);
    cout << "***************************MEDIUM BOX TEST***************************" << endl;
    medium_box.fill_the_box(6);
    medium_box.print();
    cout << "***************************MEDIUM BOX TEST END***************************" << endl;

    cout << endl;

    FruitsAndVeggiesBox large_box(15);
    cout << "***************************LARGE BOX TEST***************************" << endl;
    large_box.fill_the_box(9);
    large_box.print();
    cout << "***************************LARGE BOX TEST END***************************" << endl;
}

void test_produce() {
    Produce carrots;
    Produce tomatoes("Tomato", 9200, 25, 12, 2018);

    cout << endl;
    cout << "***************************CONSTRUCTOR TEST***************************" << endl;
    carrots.print();
    tomatoes.print();
    cout << "***************************CONSTRUCTOR TEST END***************************" << endl;

}

void run() {
    test_fill();
    test_produce();
}

