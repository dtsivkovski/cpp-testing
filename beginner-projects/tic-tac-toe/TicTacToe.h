//
// Created by dtsivkovski on 4/23/24.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <iostream>
using namespace std;


class TicTacToe {

    public:
        TicTacToe();
        ~TicTacToe();
        void playGame();

    private:
        char** grid;
        bool isPlayerTurn();
        void printBoard();
        void nextTurn();
        bool tryPlacement(int row, int col, char c);
        bool isWinCondition();
        void printWin(char player);
        int gameCounter;

};



#endif //TICTACTOE_H
