//
// Created by daniel on 4/23/24.
//
#include "TicTacToe.h"

int main(int argc, char** argv) {
    TicTacToe *t = new TicTacToe();
    t->playGame();
    delete t;

    return 0;
}
