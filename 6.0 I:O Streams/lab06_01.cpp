// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        November 7, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #5
// Exercise:    Exercise #1
// File Name:   lab06_01.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     I/O Stream Exploration & SYDE Logo

/*
 * TESTING
 * Used the input.txt file to test part A of the assignment, and it graphed.
 * Edited input.txt to different sizes to test the graphs.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// function declaration
bool part_a();
bool part_b();

// main function!
int main() {
   part_a();
   part_b();
   return 0;
}

bool part_b() {
    // [PURPOSE] put text into an svg file that would end up as the SYDE logo
    // [INPUT] none
    // [OUTPUT] syde_logo_username.svg

    // opens a file to draw the syde logo
    ofstream syde;
    syde.open("syde_logo_username.svg");

    // drawing the syde logo **** I USED CODE TO MAKE THIS LOGO, DIDN'T USE A VISUALIZER -> CODE******
    if (!syde.fail()) {
        syde << "<?xml version=\"1.0\"?>\n";
        syde << "<!DOCTYPE svg PUBLIC \"-//W3c//DTD SVG 1.1//EN\" ";
        syde << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        syde << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\">\n";
        //text (SYDE '23)
        syde << "<style> \n\t.heavy { font: 100px foco; }\n</style>\n";
        syde << "<text x=\"65\" y=\"200\" class=\"heavy\">SYDE</text>\n";
        syde << "<text x=\"140\" y=\"300\" class=\"heavy\">'23</text>\n";
        //horizontal lines
        syde << "<line x1=\"25\" y1=\"100\" x2=\"375\" y2=\"100\" style=\"stroke:purple;stroke-width:10\"/>\n";
        syde << "<line x1=\"25\" y1=\"325\" x2=\"375\" y2=\"325\" style=\"stroke:purple;stroke-width:10\"/>\n";
        //vertical lines
        syde << "<line x1=\"25\" y1=\"100\" x2=\"25\" y2=\"325\" style=\"stroke:purple;stroke-width:10\"/>\n";
        syde << "<line x1=\"375\" y1=\"100\" x2=\"375\" y2=\"325\" style=\"stroke:purple;stroke-width:10\"/>\n";
        //emoji face
        //yellow faces
        syde << "<circle cx=\"85\" cy=\"265\" r=\"40\" stroke=\"black\" stroke-width=\"2\" fill=\"yellow\"/>\n";
        syde << "<circle cx=\"310\" cy=\"265\" r=\"40\" stroke=\"black\" stroke-width=\"2\" fill=\"yellow\"/>\n";
        //eyes
        syde << "<circle cx=\"70\" cy=\"255\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"black\"/>\n";
        syde << "<circle cx=\"100\" cy=\"255\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"black\"/>\n";
        syde << "<circle cx=\"325\" cy=\"255\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"black\"/>\n";
        syde << "<circle cx=\"295\" cy=\"255\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"black\"/>\n";
        //open mouths!
        syde << "<ellipse cx=\"85\" cy=\"280\" rx=\"25\" ry=\"12\" style=\"fill:white;stroke:black;stroke-width:2\"/>\n";
        syde << "<ellipse cx=\"310\" cy=\"280\" rx=\"25\" ry=\"12\" style=\"fill:white;stroke:black;stroke-width:2\"/>\n";
        syde << "</svg>\n";
        syde.close();
    }
    return true;
}

bool part_a() {
    // [PURPOSE] input a file called 'input.txt' and make a graph with the values
    // [INPUT] a file with names & values called 'input.txt'
    // [OUTPUT] couts the names and value in the file

    // varible declaration
    int counter = 0, start = 20, number_of_lines = 0;
    string cur_pair;
    vector<string> names;
    vector<int> values;

    // opens the file
    ifstream text;
    text.open("input.txt");

    //counts the number of lines
    while (getline(text, cur_pair)) {
        number_of_lines++;
    }
    cout << number_of_lines << endl;
    // closes the file to reset getline
    text.close();

    // opens file
    text.open("input.txt");

    // gathers the name and value in the file and stores them in a name vector, and value vector
    for (int index = 0; index < number_of_lines; ++index) {
        getline(text, cur_pair);
        names.push_back(cur_pair.substr(0, cur_pair.find(',', 0)));
        values.push_back(stoi(cur_pair.substr(cur_pair.find(',', 0) + 2)));
    }

    // prints out the names and values
    for (int index = 0; index < number_of_lines; index++) {
        cout << "Name: " << names[index] << '\t' << "Values: " << values[index] << endl;
        counter++;
    }

    // closes the file
    text.close();

    // opens a file to graph the values
    ofstream part_a;
    part_a.open("exercise_1.svg");

    // graphing the values
    if (!part_a.fail()) {
        part_a << "<?xml version=\"1.0\"?>\n";
        part_a << "<!DOCTYPE svg PUBLIC \"-//W3c//DTD SVG 1.1//EN\" ";
        part_a << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        part_a << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"600\" height=\"600\">\n";
        // bars for however many values there are
        for (int i = 0; i <= counter; i++) {
            part_a << "<rect x=\"" << start << "\" y=\"" << 300 - values[i] << "\" width=\"20\" height=\"" << values[i] << "\" style=\"fill:black;\"/>\n";
            start += 40;
        }
        // axes
        part_a << "<line x1=\"10\" y1=\"0\" x2=\"10\" y2=\"300\" style=\"stroke:black;stroke-width:5\"/>\n";
        part_a << "<line x1=\"10\" y1=\"300\" x2=\"300\" y2=\"300\" style=\"stroke:black;stroke-width:5\"/>\n";
        part_a << "</svg>\n";
        part_a.close();
    }
    return true;
}