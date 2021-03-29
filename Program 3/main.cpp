/*
* Jesus Villarroel
* COSC2436
* Spring 2021
*/

/*
Tic-Tac-Toe Game

Write a modular program that allows two players to play a game of tic-tac-toe. Use a two-dimensional
char array with three rows and three columns as the game board. Each element of the array should be
initialized with an asterisk (*). The program should display the initial board configuration and then
start a loop that does the following:

    Have player 1 select a board location for an X by entering a row and column number. Then redisplay
    the board with an X replacing the * in the chosen location.

    If there is no winner yet and the board is not yet full, have player 2 select a board location for
    an O by entering a row and column number. Then redisplay the board with an O replacing the * in
    the chosen location.

The loop should continue until a player has won or a tie has occurred, then display a message indicating
who won, or reporting that a tie occurred.

    Player 1 wins when there are three Xs in a row, a column, or a diagonal on the game board.
    Player 2 wins when there are three Os in a row, a column, or a diagonal on the game board.
    A tie occurs when all of the locations on the board are full, but there is no winner.

Input Validation: Only allow legal moves to be entered. The row and column must be 1, 2, or 3. The selected
board location must currently be empty (i.e., still have an asterisk in it).
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const   int     ROWS = 3;
const   int     COLS = 3;

char    board[ROWS][COLS] = {
    {'*', '*', '*'},
    {'*', '*', '*'},
    {'*', '*', '*'}
};

void initialMsg(void);
void displayBoard(void);
void getUserInput(void);
void updateBoard(int, int);

int main()
{
    char    repeat = 'n';

    // Display initial message.
    initialMsg();

    displayBoard();

    do
    {
        for (int turn = 0; turn < 9; turn++)
        {
            getUserInput();
        }


        cout << "\nWould you like to play again? (y/n): ";
        cin >> repeat;
        cin.ignore(100, '\n');
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y');


	return 0;
}

void initialMsg(void)
{
    cout << "// ************************************ //" << endl;
    cout << "//           TIC TAC TOE GAME           //" << endl;
    cout << "// ************************************ //" << endl;

    cout << endl;
    cout << "Instructions: " << endl;
    cout << "1. Players must enter X(row) and Y(column) coordinate of her/his selection.\n"
        << "2. Player one is represented with the \"X\" and player two with \"O\".\n\n";
}

void displayBoard(void)
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void getUserInput(void)
{
    int     x = 0,
            y = 0;

    cout << "Please, enter your selection (row and column): ";
    cin >> x;
    cin >> y;
    cin.ignore(100, '\n');

    while ((x < 1 || x > 3) || ((y < 1 || y > 3)))
    {
        cout << "\nSelection out of range.\n\n";
        cout << "Please, enter your selection (row and column): ";
        cin >> x, y;
        cin.ignore(100, '\n');
    }

}

void updateBoard(int row, int col)
{
}
