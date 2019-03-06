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

enum TicTacToeState { UnreachableState, Xwins, Owins, NoWinner, InvalidInput };

//Returns the result of a game of tictactoe, taking in a string representation of the board.
TicTacToeState CheckTicTacToeBoard(string board);

//Checks if the board is in an Unreachable State, taking in a char array of the board as a parameter.
bool IsUnreachableState(char board_array[]);

//Checks if the board is an Invalid Input, taking in a char array of the board as a parameter.
bool IsInvalidInput(string board);

//Checks if x wins the game, taking in a char array of the board as a parameter.
bool XIsWinner(char board_array[]);

//Checks if o wins the game, taking in a char array of the board as a parameter.
bool OIsWinner(char board_array[]);

//Counts the number of times a character is repeated in a given character array, taking in a char array of the board and a char as a parameter.
int CountNumOfCharactersInCharArray(char board_array[], char c);

#endif
