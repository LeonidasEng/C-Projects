/***********************************************************************************************************************************\
|*                                                Noughts & Crosses Game (2 Player)                                                *|
|*                                                      Rules of Tic Tac Toe                                                       *|
|*                                                                                                                                 *|
|*                           Rule 1 - The game is played on a grid that's 3 squares by 3 squares.                                  *|
|*                           Rule 2 - Players take turns putting their marks (x/O) in empty squares.                               *|
|*                           Rule 3 - The first player to get 3 of her marks in a row is the winner.                               *|
|*                           Rule 4 - If no player gets 3 marks in a row, the game ends in a tie.                                  *|
|*                                                                                                                                 *|
\***********************************************************************************************************************************/

#include <stdio.h>

char board[3][3]; // 3x3 board

// function to display the board
void display_board() {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if(j!=2) printf("|"); // column separator
        }
        printf("\n");
        if(i!=2) printf("---|---|---\n"); // row separator
    }
    printf("\n");
}

// function to check if a player has won the game
int check_win(char player) {
    for(int i=0; i<3; i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) return 1; // row check
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) return 1; // column check
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return 1; // diagonal check
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return 1; // diagonal check
    return 0;
}

// function to check if the game is a tie
int check_tie() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j]==' ') return 0;
        }
    }
    return 1;
}

int main() {
    // initialize the board
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }

    int row, col, player = 1;
    char mark;
    while(1) {
        // display the board
        display_board();

        // get the input from the current player
        printf("Player %d, enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter column (1-3): ", player);
        scanf("%d", &col);

        // convert row and column to 0-based indexing
        row--;
        col--;

        // check if the input is valid
        if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=' ') {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // mark the current player's move on the board
        if(player==1) mark = 'X';
        else mark = 'O';
        board[row][col] = mark;

        // check if the current player has won
        if(check_win(mark)) {
            display_board();
            printf("Player %d has won the game!\n", player);
            break;
        }

        // check if the game is a tie
        if(check_tie()) {
            display_board();
            printf("The game is a tie!\n");
            break;
        }

        // switch to the other player
        player = 3 - player;
    }

    return 0;
}
