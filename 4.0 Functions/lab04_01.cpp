// Name:        Timmy Truong
// Date:        October 12, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #3
// Exercise:    Exercise #1
// File Name:   lab04_1.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Futbol Simulation

/*
 * TESTING
 * Ran and counted the scenarios 5 times, each time, the stats matched the commentary
 * Added total shots for both teams so the types of shots could be easily added and compared to how many shots taken in
 * the whole game.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

// declaring functions to be used
bool simulation();
// [INPUT] - no input
// [PROCESSING] - for loops for each half, and switch functions to determine the event
// [OUTPUT] - Stats for half time and full time results
void shot(string team, int& goal, int& shot, int& block, int& off, int& shots_total);
// [INPUT] - no input
// [PROCESSING] - switch function to determine if a goal was scored on the shot and adding stats
// [OUTPUT] - output to see the result with commentary
void freekickcard(string team, int& yellowcard, int& redcard, int& freekick);
// [INPUT] - no input
// [PROCESSING] - switch function to determine if a card was given out on the free kick and adding stats
// [OUTPUT] - output to see the result with commentary
void penaltycard(string team, int& yellowcard, int& redcard, int& penalty);
// [INPUT] - no input
// [PROCESSING] - switch function to determine if a card was given out on a penalty and adding stats
// [OUTPUT] - output to see the result with commentary
void penaltyshot(string team, int& goal, int& shot, int& off, int& shots_total);
// [INPUT] - no input
// [PROCESSING] - switch function to determine if a goal was scored on the penalty shot and adding stats
// [OUTPUT] - output to see the result with commentary

// main function runs boolean function
int main() {
    if (simulation())
        cout << "Successful" << endl;
    return 0;
}

//boolean function that runs the simulation
bool simulation() {

    // declaring constant variables
    const string A = "Team A", B = "Team B";
    // declaring local variables
    int a_goal = 0, b_goal = 0, a_shot = 0, b_shot = 0, a_block = 0, b_block = 0, a_off = 0, b_off = 0, a_shots_total = 0, b_shots_total = 0;
    int a_yellow = 0, b_yellow = 0, a_red = 0, b_red = 0, a_fk = 0, b_fk = 0, a_p = 0, b_p = 0;
    int number_events, event, firsthalf, secondhalf;
    /*
     * (a/b)_goal = number of goals for the corresponding team
     * (a/b)_shot = number of shots on goal for the corresponding team
     * (a/b)_block = number of shots that were blocked for the corresponding team
     * (a/b)_off = number of shots that were off goal for the corresponding team
     * (a/b)_shots_total = number of shots taken throughout the half/game for the corresponding team
     * (a/b)_yellow = number of yellow cards for the corresponding team
     * (a/b)_red = number of red cards for the corresponding team
     * (a/b)_fk = number of free kicks taken for the corresponding team
     * (a/b)_p = number of penalty kicks taken for the corresponding team
     */

    // randomize random number generator
    srand(time(0));

    // generate the number of events to take place
    number_events = rand() % 30 + 1;
    // split the number of events into halves
    firsthalf = number_events / 2;
    secondhalf = number_events - firsthalf;

    // for loop to iterate through each event scenario for the total number of events
    for (int i = 0; i < firsthalf; i++) {
        // generate the event number, so the correct print will show for the corresponding event
        event = rand() % 6 + 1;
        // switch function to choose printout based on event number
        switch (event) {
            case 1:
                shot(A, a_goal, a_shot, a_block, a_off, a_shots_total);
                break;
            case 2:
                shot(B, b_goal, b_shot, b_block, b_off, b_shots_total);
                break;
            case 3:
                freekickcard(B, b_yellow, b_red, b_fk);
                shot(A, a_goal, a_shot, a_block, a_off, a_shots_total);
                break;
            case 4:
                freekickcard(A, a_yellow, a_red, a_fk);
                shot(B, b_goal, b_shot, b_block, b_off, b_shots_total);
                break;
            case 5:
                penaltycard(B, b_yellow, b_red, b_p);
                penaltyshot(A, a_goal, a_shot, a_off, a_shots_total);
                break;
            case 6:
                penaltycard(A, a_yellow, a_red, a_p);
                penaltyshot(B, b_goal, b_shot, b_off, b_shots_total);
                break;
            default:
                break;
        }
        // wait 2.5 seconds before printing the next event
        usleep(2500000);
    }
    // half time print
    cout << "*******************************************************************************" << endl;
    cout << "\t\t\t\t\t\t\tHALF TIME RESULTS" << endl;
    cout << "\t\t\t\t\t" << A << "\t\t\t\t\t" << B << endl;
    cout << "Goals" << "\t\t\t\t\t" << a_goal << "\t\t\t\t\t\t" << b_goal << endl;
    cout << "Shots" << "\t\t\t\t\t" << a_shots_total << "\t\t\t\t\t\t" << b_shots_total << endl;
    cout << "Shots on Goal" << "\t\t\t" << a_shot << "\t\t\t\t\t\t" << b_shot << endl;
    cout << "Shots Blocked" << "\t\t\t" << a_block << "\t\t\t\t\t\t" << b_block << endl;
    cout << "Shots off Goal" << "\t\t\t" << a_off << "\t\t\t\t\t\t" << b_off << endl;
    cout << "Yellow Card" << "\t\t\t\t" << a_yellow << "\t\t\t\t\t\t" << b_yellow << endl;
    cout << "Red Card" << "\t\t\t\t" << a_red << "\t\t\t\t\t\t" << a_red << endl;
    cout << "Free Kicks" << "\t\t\t\t" << a_fk << "\t\t\t\t\t\t" << b_fk << endl;
    cout << "Penalty Kicks" << "\t\t\t" << a_p << "\t\t\t\t\t\t" << b_p << endl;
    cout << "*******************************************************************************" << endl;
    // wait 2.5 seconds before starting the second half
    usleep(2500000);
    // for loop to iterate through each event scenario for the total number of events
    for (int i = 0; i < secondhalf; i++) {
        // generate the event number, so the correct print will show for the corresponding event
        event = rand() % 6 + 1;
        // switch function to choose printout based on event number
        switch (event) {
            case 1:
                shot(A, a_goal, a_shot, a_block, a_off, a_shots_total);
                break;
            case 2:
                shot(B, b_goal, b_shot, b_block, b_off, b_shots_total);
                break;
            case 3:
                freekickcard(B, b_yellow, b_red, a_fk);
                shot(A, a_goal, a_shot, a_block, a_off, a_shots_total);
                break;
            case 4:
                freekickcard(A, a_yellow, a_red, b_fk);
                shot(B, b_goal, b_shot, b_block, b_off, b_shots_total);
                break;
            case 5:
                penaltycard(B, b_yellow, b_red, a_p);
                penaltyshot(A, a_goal, a_shot, a_off, a_shots_total);
                break;
            case 6:
                penaltycard(A, a_yellow, a_red, b_p);
                penaltyshot(B, b_goal, b_shot, b_off, b_shots_total);
                break;
            default:
                break;
        }
        // wait 2.5 seconds before printing out the next event
        usleep(2500000);
    }
    // full time results print out
    cout << "*******************************************************************************" << endl;
    cout << "\t\t\t\t\t\t\tFULL TIME RESULTS" << endl;
    cout << "\t\t\t\t\t" << A << "\t\t\t\t\t" << B << endl;
    cout << "Goals" << "\t\t\t\t\t" << a_goal << "\t\t\t\t\t\t" << b_goal << endl;
    cout << "Shots" << "\t\t\t\t\t" << a_shots_total << "\t\t\t\t\t\t" << b_shots_total << endl;
    cout << "Shots on Goal" << "\t\t\t" << a_shot << "\t\t\t\t\t\t" << b_shot << endl;
    cout << "Shots Blocked" << "\t\t\t" << a_block << "\t\t\t\t\t\t" << b_block << endl;
    cout << "Shots off Goal" << "\t\t\t" << a_off << "\t\t\t\t\t\t" << b_off << endl;
    cout << "Yellow Card" << "\t\t\t\t" << a_yellow << "\t\t\t\t\t\t" << b_yellow << endl;
    cout << "Red Card" << "\t\t\t\t" << a_red << "\t\t\t\t\t\t" << a_red << endl;
    cout << "Free Kicks" << "\t\t\t\t" << b_fk << "\t\t\t\t\t\t" << a_fk << endl;
    cout << "Penalty Kicks" << "\t\t\t" << b_p << "\t\t\t\t\t\t" << a_p << endl;
    cout << "*******************************************************************************" << endl;
    return 0;
}

// function that generates a number that determines the outcome of a shot
// counts the number of goals, shots on goal, blocks,
// and shots off goal, then prints the corresponding commentary
void shot(string team, int& goal, int& shot, int& block, int& off, int& shots_total) {
    int outcome;
    outcome = rand() % 4;
    shots_total++;
    switch(outcome){
        case 0:
            cout << '\t' << team << " has scored a goal! Brilliant finish! " << endl;
            goal++;
            shot++;
            break;
        case 1:
            cout << '\t' << team << " has got a shot on goal! An absolute wall, that keeper!" << endl;
            shot++;
            break;
        case 2:
            cout << '\t' << team << " has gotten a shot off goal! Just shy of the net, excellent attempt!" << endl;
            off++;
            break;
        case 3:
            cout << '\t' << team << "'s shot was blocked! A rocket of a ball deflected!" << endl;
            block++;
            break;
        default:
            break;
    }
}

// function that generates the discipline decision on a free kick
// counts the number of yellow and red cards that occur on free kicks
// prints out the corresponding commentary
void freekickcard(string team, int& yellowcard, int& redcard, int& freekick) {
    int outcome;
    freekick++;
    outcome = rand() % 3;
    cout << '\t' << team << " has committed a foul and the opposing team has a free kick! ";
    switch(outcome){
        case 0:
            cout << team << " has received a verbal warning from the referee." << endl;
            break;
        case 1:
            cout << team << " has received a yellow card." << endl;
            yellowcard++;
            break;
        case 2:
            cout << team << " has received a red card! " << team << " is now down a player!" << endl;
            redcard++;
            break;
        default:
            break;
    }
}

// function that generates the discipline decision on a penalty kick
// counts the number of yellow and red cards that occur on penalty kicks
// prints out the corresponding commentary
void penaltycard(string team, int& yellowcard, int& redcard, int& penalty) {
    int outcome;
    penalty++;
    outcome = rand() % 3;
    cout << '\t' << team << " has committed a foul and the opposing team has a penalty kick! ";
    switch(outcome){
        case 0:
            cout << team << " has received a verbal warning from the referee." << endl;
            break;
        case 1:
            cout << team << " has received a yellow card." << endl;
            yellowcard++;
            break;
        case 2:
            cout << team << " has received a red card! " << team << " is now down a player!" << endl;
            redcard++;
            break;
        default:
            break;
    }
}

// function that generates the shot outcome of a penalty kick
// counts the number of goals, shots on goal, and shots off goal
// prints out the corresponding commentary
void penaltyshot(string team, int& goal, int& shot, int& off, int& shots_total) {
    int outcome;
    outcome = rand() % 3;
    shots_total++;
    switch(outcome){
        case 0:
            cout << '\t' << team << " has scored a goal off the penalty! Brilliant finish!" << endl;
            goal++;
            shot++;
            break;
        case 1:
            cout << '\t' << team << " has got a shot on goal! An absolute wall, that keeper!" << endl;
            shot++;
            break;
        case 2:
            cout << '\t' << team << " has gotten a shot off goal! Just shy of the net, excellent attempt!" << endl;
            off++;
            break;
        default:
            break;
    }
}
