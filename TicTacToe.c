#include <stdio.h>

char board[3][3];
int moves = 0;

void resetBoard() {
    int i, j, k = 1;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            board[i][j] = '0' + k++;
    moves = 0;
}

void printBoard() {
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        if(i < 2) printf("\n---+---+---\n");
        else printf("\n");
    }
    printf("\n");
}

int checkWin() {
    int i;
    // Check rows and columns
    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int validMove(int pos) {
    int row = (pos-1)/3;
    int col = (pos-1)%3;
    if(pos < 1 || pos > 9) return 0;
    if(board[row][col] == 'X' || board[row][col] == 'O') return 0;
    return 1;
}

void makeMove(int pos, char mark) {
    int row = (pos-1)/3;
    int col = (pos-1)%3;
    board[row][col] = mark;
    moves++;
}

int main() {
    int pos, player = 1;
    char mark;
    resetBoard();
    while(1) {
        printBoard();
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter position (1-9): ", player, mark);
        scanf("%d", &pos);
        if(!validMove(pos)) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        makeMove(pos, mark);
        if(checkWin()) {
            printBoard();
            printf("Player %d (%c) wins!\n", player, mark);
            break;
        }
        if(moves == 9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 1 ? 2 : 1);
    }
    return 0;
}
