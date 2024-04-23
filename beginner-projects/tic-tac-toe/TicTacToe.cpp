//
// Created by dtsivkovski on 4/23/24.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe() {
    //
    grid = new char*[3];
    for (int i = 0; i < 3; ++i) {
        grid[i] = new char[3];
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
    gameCounter = 0;
    // set seed for random
    srand(time(nullptr));
}

TicTacToe::~TicTacToe() {
    // delete 2d array
    for (int i = 0; i < 3; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void TicTacToe::playGame() {
    if (gameCounter == 0) {
        cout << "Welcome to Tic Tac Toe!" << endl;
    }
    gameCounter++;
    nextTurn(); // perform turn
    if (isWinCondition()) {
        return; // end game if win condition is true
    }
    playGame();
}

bool TicTacToe::isPlayerTurn() {
    return (gameCounter % 2 == 1);
}

void TicTacToe::printBoard() {
    cout << "Board" << endl;
    cout << "-------------" << endl;
    cout << "| " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " |" << endl;
    cout << "-------------" << endl;
}

void TicTacToe::nextTurn(){
    cout << endl;
    printBoard();

    if (isPlayerTurn()) {

        // gets user input until user selects a valid place
        while (true) {
            string userInput = "";
            int rowval = -1;
            // continue until correct number is pressed
            while (rowval > 3 || rowval < 0) {
                // give the options
                cout << "Select where to place your circle:" << endl
                    << "1. Top row" << endl
                    << "2. Middle row" << endl
                    << "3. Bottom row" << endl;
                // get cin from user and convert to int
                cin >> userInput;
                rowval = stoi(userInput);
            }

            int colval = -1;
            // continue until correct number is pressed
            while (colval > 3 || colval < 0) {
                // give the options
                cout << "Select where to place your circle:" << endl
                    << "1. Left column" << endl
                    << "2. Middle column" << endl
                    << "3. Right column" << endl;
                // get cin from user and convert to int
                cin >> userInput;
                colval = stoi(userInput);
            }

            if (tryPlacement(rowval - 1, colval - 1, 'O')) break;

            // if not a valid placement
            cout << "Not a valid placement. please try again." << endl;

        }
    }
    else {

        // generate random placement for bot
        int randrow;
        int randcol;
        do {
            randrow = rand() % 3;
            randcol = rand() % 3;
        } while (!tryPlacement(randrow, randcol, 'X'));

    }

}

bool TicTacToe::tryPlacement(int row, int col, char c) {
    if (grid[row][col] != ' ') return false;
    else {
        grid[row][col] = c;
        return true;
    }
}

void TicTacToe::printWin(char player) {
    cout << endl;
    printBoard();
    if (player == 'X') {
        cout << "The computer player has won!" << endl;
    }
    else {
        cout << "You have won! Congratulations!" << endl;
    }
}

bool TicTacToe::isWinCondition() {
    // check across win conditions
    for (int i = 0; i < 3; ++i) {
        char firstChar = grid[i][0];
        if (firstChar == ' ') continue;
        else {
            if (firstChar == grid[i][1] && firstChar == grid[i][2]) {
                printWin(firstChar);
                return true;
            }
        }
    }
    // check vertical win conditions
    for (int i = 0; i < 3; ++i) {
        char firstChar = grid[0][i];
        if (firstChar == ' ') continue;
        else {
            if (firstChar == grid[1][i] && firstChar == grid[2][i]) return true;
        }
    }
    // check diagonal win conditions
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != ' ') {
        printWin(grid[0][0]);
        return true;
    }
    if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != ' ') {
        printWin(grid[0][2]);
        return true;
    }

    return false;
}