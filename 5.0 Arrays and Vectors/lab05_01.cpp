// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        October 26, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #4
// Exercise:    Exercise #1
// File Name:   lab05_1.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Tic-Tac-Toe Edited

/*
 * TESTING
 * Ran program through every winning configuration with different winners
 */

// lirbaries included
#include <iostream>
#include <cstdlib>
#include <array>
#include <string>

using namespace std;

// variable declarations
int run_simulation(int& count1, int& count2, string& player1, string& player2);
// [INPUT]      - no input
// [PROCESSING] - initializes variables and calls all the functions
// [OUTPUT]     - lets you know who has won the game
void introduction(string& player1, string& player2);
// [INPUT]      - player 1 and player 2's names
// [PROCESSING] - none
// [OUTPUT]     - introduction to the game and shows game board
bool check_board(string game_board[4][4], string player1_symbol, string player2_symbol, int& decider);
// [INPUT]      - takes a bunch of arguments
// [PROCESSING] - for loop checking for different variations in winning patterns
// [OUTPUT]     - none
void entry(string& player, int& entry);
// [INPUT]      - user enters the number they'd like to x or o
// [PROCESSING] - none
// [OUTPUT]     - none
void change_board(string symbol, int entry, string game_board[4][4]);
// [INPUT]      - takes a bunch of arguments
// [PROCESSING] - switch statement to change the place holder to an x or o
// [OUTPUT]     - shows game board with changed place holder

// constant variables
const int ROWS = 4;
const int COLUMNS = 4;

// main function to run program
int main() {
    string continue_variable, player1, player2;
    int count1 = 0, count2 = 0;
    cout << "Would you like to start the game? Enter 'y' or 'Y' for yes; Enter any other key to end the program. ";
    cin >> continue_variable;
    // while the player wants, the program can restart
    while (continue_variable == "Y" || continue_variable == "y") {
        run_simulation(count1, count2, player1, player2);
        cout << ' ' << endl;
        cout << "/********* WINNER COUNT *********/" << endl;
        cout << player1 << ": " << count1 << endl;
        cout << player2 << ": " << count2 << endl;
        cout << "Would you like to restart? Enter 'y' or 'Y' for yes; Enter any other key to end the program. ";
        cin >> continue_variable;
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}

// function that calls all the functions
int run_simulation(int& count1, int& count2, string& player1, string& player2) {
    // initializing all the variables
    string player1_name, player2_name;
    string player1_symbol = "X", player2_symbol = "O";
    string game_board[COLUMNS][ROWS] = {{"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"}};
    int entry_x = 0, entry_o = 0;
    int decider = 1, count = 0; // decider variable to check who wins

    // calling the introduction function
    introduction(player1_name, player2_name);

    // while loop until someone wins
    while (decider == 1 && count < 16) {
        entry(player1_name, entry_x);
        change_board(player1_symbol, entry_x, game_board);
        entry(player2_name, entry_o);
        change_board(player2_symbol, entry_o, game_board);
        check_board(game_board, player1_symbol, player2_symbol, decider);
        count++;
    }

    player1 = player1_name;
    player2 = player2_name;
    // if statements to check who has won
    if (decider == 3) {
        cout << player1_name << " has won!" << endl;
        count1++;
    }
    else if (decider == 2) {
        cout << "Both players tied!" << endl;
        count1++;
        count2++;
    }
    else if (decider == 0) {
        cout << player2_name << " has won!" << endl;
        count2++;
    }
    else if (decider == 1) {
        cout << "There is no winner." << endl;
    }

    return 0;
}

// void function that asks for player names and introduces them to the game
// players enter their names as input
// couts the game board & introductions
void introduction(string& player1, string& player2) {
    // initialize gameboard
    string game_board[COLUMNS][ROWS] = {{"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"}};

    // introduction
    cout << "Welcome to Tic-Tac-Toe. Please enter your names below." << endl;
    cout << "Player 1: ";
    cin >> player1;
    cout << "Player 2: ";
    cin >> player2;
    cout << ' ' << endl;
    cout << "This is the game board: " << endl;
    //display the game board in 4x4 configuration
    for (int index = 0; index < COLUMNS; index++) {
        for (int index1 = 0; index1 < ROWS; index1++) {
            cout << game_board[index][index1] << '\t';
        }
        cout << endl;
    }
    cout << ' ' << endl;
    cout << player1 << " will go first, and the turns will alternate. You MUST select a number from 1 - 16." << endl;
}

// void function that asks for player's move
// player inputs their desired move
// no output
void entry(string& player, int& entry) {
    // do while loop that restricts entry to [1-16]
    do {
        cout << player << ": ";
        cin >> entry;
    } while (entry > 16 || entry < 1);
}

// boolean function that checks the game board for winning patterns
// no user input
// no output
bool check_board(string game_board[4][4], string player1_symbol, string player2_symbol, int& decider) {
    // for loop to check winning patterns
    for (int i = 0; i < 4; i++) {
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][2] == game_board[i][3] && game_board[i][3] == player1_symbol) {
            decider += 2;
        }
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][2] == game_board[i][3] && game_board[i][3] == player2_symbol) {
            decider--;
        }
        if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i] && game_board[2][i] == game_board[3][i] && game_board[3][i] == player1_symbol) {
            decider += 2;
        }
        if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i] && game_board[2][i] == game_board[3][i] && game_board[3][i] == player2_symbol) {
            decider--;
        }
        if (game_board[i][i] == game_board[i+1][i+1] && game_board[i+1][i+1] == game_board[i+2][i+2] && game_board[i+2][i+2] == game_board[i+3][i+3] && game_board[i][i] == player1_symbol) {
            decider += 2;
        }
        if (game_board[i][i] == game_board[i+1][i+1] && game_board[i+1][i+1] == game_board[i+2][i+2] && game_board[i+2][i+2] == game_board[i+3][i+3] && game_board[i][i] == player2_symbol) {
            decider--;
        }
        if (game_board[i][3] == game_board[i+1][2] && game_board[i+1][2] == game_board[i+2][1] && game_board[i+2][1] == game_board[i+3][0] && game_board[i][i] == player1_symbol) {
            decider += 2;
        }
        if (game_board[i][3] == game_board[i+1][2] && game_board[i+1][2] == game_board[i+2][1] && game_board[i+2][1] == game_board[i+3][0] && game_board[i][i] == player2_symbol) {
            decider--;
        }
    }
    return true;
};

// void function that changes the board according to the players entry
// no user input
// outputs the game board with the new entry
void change_board(string symbol, int entry, string game_board[4][4]) {
    switch (entry) {
        case 1:
            game_board[0][0] = symbol;
            break;
        case 2:
            game_board[0][1] = symbol;
            break;
        case 3:
            game_board[0][2] = symbol;
            break;
        case 4:
            game_board[0][3] = symbol;
            break;
        case 5:
            game_board[1][0] = symbol;
            break;
        case 6:
            game_board[1][1] = symbol;
            break;
        case 7:
            game_board[1][2] = symbol;
            break;
        case 8:
            game_board[1][3] = symbol;
            break;
        case 9:
            game_board[2][0] = symbol;
            break;
        case 10:
            game_board[2][1] = symbol;
            break;
        case 11:
            game_board[2][2] = symbol;
            break;
        case 12:
            game_board[2][3] = symbol;
            break;
        case 13:
            game_board[3][0] = symbol;
            break;
        case 14:
            game_board[3][1] = symbol;
            break;
        case 15:
            game_board[3][2] = symbol;
            break;
        case 16:
            game_board[3][3] = symbol;
            break;
        default:
            break;
    }
    // prints array in 4x4 configuration
    for (int index = 0; index < 4; index++) {
        for (int index1 = 0; index1 < 4; index1++) {
            cout << game_board[index][index1] << '\t';
        }
        cout << endl;
    }
}
