#include "TicTacToe.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

TicTacToeState CheckTicTacToeBoard(string board) {
	if (IsInvalidInput(board)) {
		return InvalidInput;
	}

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
	int xcount = CountNumOfCharactersInString(board_array, 'x');
	int ocount = CountNumOfCharactersInString(board_array, 'o');

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
	for (int i = 0; i < kBoardDimension; i++) {
		if ((board_array[i] == 'x') && (board_array[i] == board_array[i + kBoardDimension]) && 
			(board_array[i + kBoardDimension] == board_array[i + kLengthofTwoRows])) {
			return true;
		}
	}
	for (int i = 0; i < kBoardLength; i+=kBoardDimension) {
		if ((board_array[i] == 'x') && (board_array[i] == board_array[i + kTopMiddleSquare]) &&
			(board_array[i + kTopMiddleSquare] == board_array[i + kTopRightSquare])) {
			return true;
		}
	}
	if ((board_array[kMiddleSquare] == 'x') && 
		(((board_array[kStartingSquare] == board_array[kMiddleSquare]) && (board_array[kMiddleSquare] == board_array[kLastSquare])) ||
		((board_array[kTopRightSquare] == board_array[kMiddleSquare]) && (board_array[kMiddleSquare] == board_array[kBottomLeftSquare])))) {
		return true;
	}
	return false;
}

bool OIsWinner(char board_array[]) {
	for (int i = 0; i < kBoardDimension; i++) {
		if ((board_array[i] == 'o') && (board_array[i] == board_array[i + kBoardDimension]) &&
			(board_array[i + kBoardDimension] == board_array[i + kLengthofTwoRows])) {
			return true;
		}
	}
	for (int i = 0; i < kBoardLength; i += kBoardDimension) {
		if ((board_array[i] == 'o') && (board_array[i] == board_array[i + kTopMiddleSquare]) &&
			(board_array[i + kTopMiddleSquare] == board_array[i + kTopRightSquare])) {
			return true;
		}
	}
	if ((board_array[kMiddleSquare] == 'o') &&
		(((board_array[kStartingSquare] == board_array[kMiddleSquare]) && (board_array[kMiddleSquare] == board_array[kLastSquare])) ||
		((board_array[kTopRightSquare] == board_array[kMiddleSquare]) && (board_array[kMiddleSquare] == board_array[kBottomLeftSquare])))) {
		return true;
	}
	return false;
}

int CountNumOfCharactersInString(char board_array[], char c) {
	int count = 0;
	for (int i = 0; i < kBoardLength; i++) {
		if (board_array[i] == c) {
			count++;
		}
	}
	return count;
}