#include <stdio.h>

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int pos, i, j;
    int player = 1;
    int moves = 0;
    char mark;
    int win = 0;

    while(1) {
        printf("\n");
        printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);

        if(player == 1)
            mark = 'X';
        else
            mark = 'O';

        printf("Player %d (%c), enter position (1-9): ", player, mark);
        scanf("%d", &pos);

        if(pos < 1 || pos > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][col] = mark;
        moves++;

        // check rows
        for(i = 0; i < 3; i++) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
                win = 1;
        }

        // check columns
        for(i = 0; i < 3; i++) {
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
                win = 1;
        }

        // check diagonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
            win = 1;
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
            win = 1;

        if(win == 1) {
            printf("\n");
            printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
            printf("Player %d (%c) wins!\n", player, mark);
            break;
        }

        if(moves == 9) {
            printf("It's a draw!\n");
            break;
        }

        if(player == 1)
            player = 2;
        else
            player = 1;
    }

    return 0;
}
