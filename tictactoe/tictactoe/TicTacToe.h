#ifndef TICTACTOE_H
#define TICTACTOE_H

#pragma once
#include <string>

const int kBoardLength = 9;
const int kBoardDimension = 3;
const int kStartingSquare = 0;
const int kMiddleSquareLocation = 4;
const int kLastSquare = 8;
const int kLengthofTwoRows = 6;

enum TicTacToeState { UnreachableState, Xwins, Owins, NoWinner, InvalidInput };

TicTacToeState CheckTicTacToeBoard(std::string board);

#endif
