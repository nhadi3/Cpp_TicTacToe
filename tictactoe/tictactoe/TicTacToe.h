#ifndef TICTACTOE_H
#define TICTACTOE_H

#pragma once
#include <string>

using std::string;

const int kBoardLength = 9;
const int kBoardDimension = 3;
const int kStartingSquare = 0;
const int kTopMiddleSquare = 1;
const int kTopRightSquare = 2;
const int kMiddleSquare = 4;
const int kBottomLeftSquare = 6;
const int kLastSquare = 8;
const int kLengthofTwoRows = 6;

enum TicTacToeState { UnreachableState, Xwins, Owins, NoWinner, InvalidInput };

TicTacToeState CheckTicTacToeBoard(string board);

bool IsUnreachableState(char board_array[]);

bool IsInvalidInput(string board);

bool XIsWinner(char board_array[]);

bool OIsWinner(char board_array[]);

int CountNumOfCharactersInString(char board_array[], char c);

#endif
