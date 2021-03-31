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

// Player 1 = false / Player 2 = true
bool    playerTurn = false;

// Symbols used by players
char    p1Symbol = 'X';
char    p2Symbol = 'O';

// Define "empty" board.
char    board[ROWS][COLS] = {
    {'*', '*', '*'},
    {'*', '*', '*'},
    {'*', '*', '*'}
};

// Function prototypes.
void initialMsg(void);
void displayBoard(void);
void getUserInput(void);
void updateBoard(int, int);
void resetBoard(void);
bool checkIfWon(char);

int main()
{
    char    repeat = 'n';
    bool    didWin = false;
    string  winner = "";

    // Display initial message.
    initialMsg();    

    // main loop.
    do
    {
        // Reset board. Its purpose its handy when loop repeats.
        resetBoard();

        // Display "empty" board.
        displayBoard();

        // Set turn to player one.
        playerTurn = false;


        for (int turn = 0; turn < 9; turn++)
        {
            // Get user input, validate it, and update board.
            getUserInput();

            // Clear screen and display updated board.
            system("cls");
            displayBoard();
            
            // Check if user won.
            if (playerTurn)
            {
                didWin = checkIfWon(p2Symbol);

                if (didWin)
                {
                    winner = "player 2";
                    break;
                }
            }                
            else
            {
                didWin = checkIfWon(p1Symbol);

                if (didWin)
                {
                    winner = "player 1";
                    break;
                }
            }
                
            // Switch turn to next player.
            playerTurn = !playerTurn;

            
        }

        // If there's a winner display message or tie game message.
        if (didWin)
        {
            cout << "\nCONGRATULATIONS!! " << winner << ". You did it!" << endl << endl;
        }
        else
        {
            cout << "\nGame draw!!" << endl << endl;
        }

        // Prompt user to play again.
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

void resetBoard(void)
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = '*';
}

void getUserInput(void)
{
    int     x = 0,
            y = 0;

    cout << "\nPlease, enter your selection (row \"space\" column): ";
    cin >> x;
    cin >> y;
    cin.ignore(100, '\n');

    // Validate input is in range.
    while (x < 1 || x > 3 || y < 1 || y > 3)
    {
        cout << "\nSelection out of range.\n\n";
        cout << "Please, enter your selection (row and column): ";
        cin >> x;
        cin >> y;
        cin.ignore(100, '\n');
    }

    // Check that input has not been played previously.
    while (board[x - 1][y - 1] != '*')
    {
        cout << "\nCell already selected.\n\n";
        cout << "Please, enter your selection (row and column): ";
        cin >> x;
        cin >> y;
        cin.ignore(100, '\n');
        cout << endl;
    }

    // Update board with player selection.
    updateBoard(x, y);

}

void updateBoard(int row, int col)
{
    if (playerTurn)
        board[row - 1][col - 1] = p2Symbol;
    else
        board[row - 1][col - 1] = p1Symbol;

}

bool checkIfWon(char playerSymbol)
{
    // Check rows.
    if (board[0][0] == playerSymbol && board[0][1] == playerSymbol && board[0][2] == playerSymbol)
        return true;

    if (board[1][0] == playerSymbol && board[1][1] == playerSymbol && board[1][2] == playerSymbol)
        return true;

    if (board[2][0] == playerSymbol && board[2][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;

    // Check columns.
    if (board[0][0] == playerSymbol && board[1][0] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    if (board[0][1] == playerSymbol && board[1][1] == playerSymbol && board[2][1] == playerSymbol)
        return true;

    if (board[0][2] == playerSymbol && board[1][2] == playerSymbol && board[2][2] == playerSymbol)
        return true;

    // Check diagonals.
    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;

    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    return false;
}
