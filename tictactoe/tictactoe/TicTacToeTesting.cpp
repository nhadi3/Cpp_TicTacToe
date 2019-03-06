
#define CATCH_CONFIG_MAIN
#include "TicTacToe.h"
#include "catch.hpp"

//Tests for when there is no winner.
TEST_CASE("SpecialCharacters_NoWinner_Board") {
	REQUIRE(CheckTicTacToeBoard("@#*$&}|:~") == NoWinner);
}

TEST_CASE("Simple_NoWinner_Board") {
	REQUIRE(CheckTicTacToeBoard("O...X.X..") == NoWinner);
}

TEST_CASE("Complete_NoWinner_Board") {
	REQUIRE(CheckTicTacToeBoard("XXOOXXXOO") == NoWinner);
}

//Tests for when X is the winner.
TEST_CASE("RowOne_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXXO.OO.") == Xwins);
}

TEST_CASE("RowTwo_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard(".OOXXXX.O") == Xwins);
}

TEST_CASE("RowThree_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("O.OOX.XXX") == Xwins);
}

TEST_CASE("ColumnOne_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XXOXO.XO.") == Xwins);
}

TEST_CASE("ColumnTwo_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard(".XO.X.OX.") == Xwins);
}

TEST_CASE("ColumnThree_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("O.XXOX.OX") == Xwins);
}

TEST_CASE("DiagonalStartingFromLeft_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XO.XXOO.X") == Xwins);
}

TEST_CASE("DiagonalStartingFromRight_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard("OOXOXXX..") == Xwins);
}

TEST_CASE("Two_XWinner_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXXOOXOO") == Xwins);
}

TEST_CASE("LowerAndUpperCase_XWin_Board") {
	REQUIRE(CheckTicTacToeBoard(".xO.X.oX.") == Xwins);
}

//Tests for when O is the winner.
TEST_CASE("RowOne_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("OOO.X.XX.") == Owins);
}

TEST_CASE("RowTwo_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("X..OOOXX.") == Owins);
}

TEST_CASE("RowThree_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("X..XX.OOO") == Owins);
}

TEST_CASE("ColumnOne_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("O.XOXXO..") == Owins);
}

TEST_CASE("ColumnTwo_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XO..OX.OX") == Owins);
}

TEST_CASE("ColumnThree_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XOOXXO.XO") == Owins);
}

TEST_CASE("DiagonalStartingFromLeft_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("OXXOOXX.O") == Owins);
}

TEST_CASE("DiagonalStartingFromRight_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("XXOXOOOX.") == Owins);
}

TEST_CASE("LowerAndUpperCase_OWin_Board") {
	REQUIRE(CheckTicTacToeBoard("xO..oX.oX") == Owins);
}

//Tests for Invalid Input cases.
TEST_CASE("ReallyLittleInput_InvalidInput_Board") {
	REQUIRE(CheckTicTacToeBoard("X") == InvalidInput);
}

TEST_CASE("ReallyLongInput_InvalidInput_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXO.O..XXXOOOO.....X.X.O.X.O....X...OOX..") == InvalidInput);
}

TEST_CASE("OneLessInput_InvalidInput_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXO.O..") == InvalidInput);
}

TEST_CASE("OneMoreInput_InvalidInput_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXO.O....") == InvalidInput);
}

TEST_CASE("Empty_InvalidInput_Board") {
	REQUIRE(CheckTicTacToeBoard("") == InvalidInput);
}

//Tests for Unreachable State cases.
TEST_CASE("AllX_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXXXXXXX") == UnreachableState);
}

TEST_CASE("AllO_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("OOOOOOOOO") == UnreachableState);
}

TEST_CASE("TwoMoreXThenO_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("X..X.....") == UnreachableState);
}

TEST_CASE("MoreO_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("OXX.O...O") == UnreachableState);
}

TEST_CASE("TwoWinners_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXOOO...") == UnreachableState);
}

TEST_CASE("MoreXWhenOWin_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("..OXXOXXO") == UnreachableState);
}

TEST_CASE("SameAmountOfXWhenXWin_UnreachableState_Board") {
	REQUIRE(CheckTicTacToeBoard("XXXO.O.O.") == UnreachableState);
}