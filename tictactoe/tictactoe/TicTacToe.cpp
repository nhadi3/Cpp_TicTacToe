#include "TicTacToe.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

TicTacToeState CheckTicTacToeBoard(string board) {
	if (IsInvalidInput(board)) {
		return InvalidInput;
	}

	//Converts board string to a char array of the board.
	string boardgiven = board;
	char board_array[kBoardLength];
	for (int i = 0; i < kBoardLength; i++) {
		board_array[i] = tolower(boardgiven.at(i));
	}

	if (IsUnreachableState(board_array)) {
		return UnreachableState;
	} else if (XIsWinner(board_array)) {
		return Xwins;
	} else if (OIsWinner(board_array)) {
		return Owins;
	}
	
	return NoWinner;
}

bool IsUnreachableState(char board_array[]) {
	int xcount = CountNumOfCharactersInCharArray(board_array, 'x');
	int ocount = CountNumOfCharactersInCharArray(board_array, 'o');

	if (xcount < ocount) {
		return true;
	} else if (XIsWinner(board_array) && (xcount == ocount)) {
		return true;
	} else if (OIsWinner(board_array) && (xcount > ocount)) {
		return true;
	} else if (XIsWinner(board_array) && OIsWinner(board_array)) {
		return true;
	}

	return false;
}

bool IsInvalidInput(string board) {
	if (board.length() != 9) {
		return true;
	}
	return false;
}

bool XIsWinner(char board_array[]) {
	//Checks for Column wins for X.
	for (int i = 0; i < kBoardDimension; i++) {
		if ((board_array[i] == 'x') && (board_array[i] == board_array[i + kBoardDimension]) && 
			(board_array[i + kBoardDimension] == board_array[i + kBottomLeftSquare])) {
			return true;
		}
	}

	//Checks for Row wins for X.
	for (int i = 0; i < kBoardLength; i+=kBoardDimension) {
		if ((board_array[i] == 'x') && (board_array[i] == board_array[i + kTopMiddleSquare]) &&
			(board_array[i + kTopMiddleSquare] == board_array[i + kTopRightSquare])) {
			return true;
		}
	}

	//Checks for Diagonal wins for X.
	if ((board_array[kMiddleSquare] == 'x') && 
		(((board_array[kStartingSquare] == board_array[kMiddleSquare]) && 
		(board_array[kMiddleSquare] == board_array[kLastSquare])) ||
		((board_array[kTopRightSquare] == board_array[kMiddleSquare]) && 
			(board_array[kMiddleSquare] == board_array[kBottomLeftSquare])))) {
		return true;
	}

	return false;
}

bool OIsWinner(char board_array[]) {
	//Checks for Column wins for O.
	for (int i = 0; i < kBoardDimension; i++) {
		if ((board_array[i] == 'o') && (board_array[i] == board_array[i + kBoardDimension]) &&
			(board_array[i + kBoardDimension] == board_array[i + kBottomLeftSquare])) {
			return true;
		}
	}

	//Checks for Row wins for O.
	for (int i = 0; i < kBoardLength; i += kBoardDimension) {
		if ((board_array[i] == 'o') && (board_array[i] == board_array[i + kTopMiddleSquare]) &&
			(board_array[i + kTopMiddleSquare] == board_array[i + kTopRightSquare])) {
			return true;
		}
	}

	//Checks for Diagonal wins for O.
	if ((board_array[kMiddleSquare] == 'o') &&
		(((board_array[kStartingSquare] == board_array[kMiddleSquare]) && 
		(board_array[kMiddleSquare] == board_array[kLastSquare])) ||
		((board_array[kTopRightSquare] == board_array[kMiddleSquare]) && 
			(board_array[kMiddleSquare] == board_array[kBottomLeftSquare])))) {
		return true;
	}

	return false;
}

int CountNumOfCharactersInCharArray(char board_array[], char c) {
	int count = 0;
	for (int i = 0; i < kBoardLength; i++) {
		if (board_array[i] == c) {
			count++;
		}
	}
	return count;
}