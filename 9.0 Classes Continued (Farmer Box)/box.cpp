//
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

#include "box.hpp"
#include "produce.hpp"

using namespace std;

FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0), winter_produce({}), summer_produce({}), fall_produce({}), spring_produce({}) {}

FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) : order_size(new_order_size) {}

// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100, FruitsAndVeggiesBox::MAX_DAY = 31;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2019;

void FruitsAndVeggiesBox::print() {
    for (int i = 0; i < winter_produce.size(); i++) {
        winter_produce[i].WinterProduce::print();
    }
    for (int i = 0; i < spring_produce.size(); i++) {
        spring_produce[i].SpringProduce::print();
    }
    for (int i = 0; i < summer_produce.size(); i++) {
        summer_produce[i].SummerProduce::print();
    }
    for (int i = 0; i < fall_produce.size(); i++) {
        fall_produce[i].FallProduce::print();
    }
}

void FruitsAndVeggiesBox::assign_seasons(int current_month) {
    // remove previously set seasons
    produce_seasons.clear();
    // insert corresponding seasons based on specified rules
    switch (current_month) {
        case JAN:
            produce_seasons.push_back(WINTER);
            break;
        case FEB:
        case MAR:
            produce_seasons.push_back(WINTER);
            produce_seasons.push_back(SPRING);
            break;
        case APR:
            produce_seasons.push_back(SPRING);
            break;
        case MAY:
        case JUN:
            produce_seasons.push_back(SPRING);
            produce_seasons.push_back(SUMMER);
            break;
        case JUL:
            produce_seasons.push_back(SUMMER);
            break;
        case AUG:
        case SEP:
            produce_seasons.push_back(SUMMER);
            produce_seasons.push_back(FALL);
            break;
        case OCT:
            produce_seasons.push_back(FALL);
            break;
        case NOV:
        case DEC:
            produce_seasons.push_back(FALL);
            produce_seasons.push_back(WINTER);
            break;
    }
}

void FruitsAndVeggiesBox::empty_the_box() {
    winter_produce.clear();
    summer_produce.clear();
    spring_produce.clear();
    fall_produce.clear();
}

int FruitsAndVeggiesBox::size() {
    int cur_size = 0;
    cur_size += (spring_produce.size() + winter_produce.size() + spring_produce.size() + summer_produce.size());
    return cur_size;
}

void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {
    string fruits;
    ifstream seasonal_fruits;

    // opens file
    seasonal_fruits.open(file_name);

    while (getline(seasonal_fruits, fruits)) {
        return_vector.push_back(fruits);
    }

    seasonal_fruits.close();
}

void FruitsAndVeggiesBox::load_up_produce_names() {
    // TODO: complete method definition here

    // load up the four files one at a time
    file_to_vector(winter_produce_names, WINTER_FILE);
    file_to_vector(spring_produce_names, SPRING_FILE);
    file_to_vector(summer_produce_names, SUMMER_FILE);
    file_to_vector(fall_produce_names, FALL_FILE);
}

void FruitsAndVeggiesBox::print_all_produce() {
    print_loaded_names();
}

void FruitsAndVeggiesBox::print_loaded_names() {
    // TODO: complete method definition here
    // print each vector separately by listing each group of names separately
    cout << "[WINTER PRODUCE]" << endl;
    for (int i = 0; i < winter_produce_names.size(); i++) {
        cout << winter_produce_names[i] << endl;
    }
    cout << endl;
    cout << "[SUMMER PRODUCE]" << endl;
    for (int i = 0; i < summer_produce_names.size(); i++) {
        cout << summer_produce_names[i] << endl;
    }
    cout << endl;
    cout << "[SPRING PRODUCE]" << endl;
    for (int i = 0; i < spring_produce_names.size(); i++) {
        cout << spring_produce_names[i] << endl;
    }
    cout << endl;
    cout << "[FALL PRODUCE]" << endl;
    for (int i = 0; i < fall_produce_names.size(); i++) {
        cout << fall_produce_names[i] << endl;
    }
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
    // generate random values for the current produce item
    rand_item = rand() % vector_size; // random item name
    rand_weight = rand() % MAX_WEIGHT + 1;
    rand_day = rand() % MAX_DAY + 1;
    rand_month = rand() % MAX_MONTH + 1;
    rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    WinterProduce cur_item;
    bool is_unique = true;

    // step1. keep repeating this until a unique item is generated
    do {
        // step1.1. generate random values for the winter produce item
        generate_random_value(winter_produce_names.size());

        // step1.2. create a new WinterProduce instance with the matching values
        cur_item = WinterProduce(winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the winter produce vector to check if the item is unique
        for (WinterProduce element : winter_produce) {
            if (element == cur_item)
                is_unique = false;
        }
    }   while (!is_unique);

    // step2. once a unique item is generated, store it into the vector
    winter_produce.push_back(cur_item);
}

void FruitsAndVeggiesBox::handle_spring_item() {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    SpringProduce cur_item;
    bool is_unique = true;

    // step1. keep repeating this until a unique item is generated
    do {
        // step1.1. generate random values for the winter produce item
        generate_random_value(spring_produce_names.size());

        // step1.2. create a new WinterProduce instance with the matching values
        cur_item = SpringProduce(spring_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the winter produce vector to check if the item is unique
        for (SpringProduce element : spring_produce) {
            if (element == cur_item)
                is_unique = false;
        }
    }   while (!is_unique);

    // step2. once a unique item is generated, store it into the vector
    spring_produce.push_back(cur_item);
}

void FruitsAndVeggiesBox::handle_summer_item() {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    SummerProduce cur_item;
    bool is_unique = true;

    // step1. keep repeating this until a unique item is generated
    do {
        // step1.1. generate random values for the winter produce item
        generate_random_value(summer_produce_names.size());

        // step1.2. create a new WinterProduce instance with the matching values
        cur_item = SummerProduce(summer_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the winter produce vector to check if the item is unique
        for (SummerProduce element : summer_produce) {
            if (element == cur_item)
                is_unique = false;
        }
    }   while (!is_unique);

    // step2. once a unique item is generated, store it into the vector
    summer_produce.push_back(cur_item);
}

void FruitsAndVeggiesBox::handle_fall_item() {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    FallProduce cur_item;
    bool is_unique = true;

    // step1. keep repeating this until a unique item is generated
    do {
        // step1.1. generate random values for the winter produce item
        generate_random_value(fall_produce_names.size());

        // step1.2. create a new WinterProduce instance with the matching values
        cur_item = FallProduce(fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the winter produce vector to check if the item is unique
        for (FallProduce element : fall_produce) {
            if (element == cur_item)
                is_unique = false;
        }
    } while (!is_unique);

    // step2. once a unique item is generated, store it into the vector
    fall_produce.push_back(cur_item);
}

void FruitsAndVeggiesBox::insert_unique_item() {
    // TODO: complete method definition here

    // step1. randomly generate a unique produce item
    // step1.1. randomly select a season from available seasons
    rand_season = rand() % produce_seasons.size();
    // step1.2. insert a new unique item with random values into the box
    switch (produce_seasons[rand_season]) {
        case WINTER:
            // step1.3a. insert winter produce item
            handle_winter_item();
            break;

        case SPRING:
            // step1.3b. insert spring produce item
            handle_spring_item();
            break;

        case SUMMER:
            // step1.3c. insert summer produce item
            handle_summer_item();
            break;

        case FALL:
            // step1.3d. insert fall produce item
            handle_fall_item();
            break;
    }
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {
    // TODO: complete method definition here

    // step0. set the randomization seed
    srand(time(0));

    // step1. remove all items if some already inserted
    empty_the_box();

    // step2. load up produce names
    load_up_produce_names();

    // step3. decide which seasons are current
    assign_seasons(current_month);

    // step4. insert matching unique items based on the current seasons
    for (int i = 0; i < order_size; i++) {
        insert_unique_item();
    }
}