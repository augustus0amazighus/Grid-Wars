//A thrilling, strategic battle of wits on a 3x3 battlefield!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);
void computerMove(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int choice;
    int winner = 0;

    printf("Welcome to Ultimate Tic-Tac-Toe!\n");
    printf("Choose game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    initializeBoard(board);

    while (!winner && !isBoardFull(board)) {
        displayBoard(board);

        playerMove(board, 'X'); // حركة اللاعب 1
        winner = checkWin(board);
        if (winner || isBoardFull(board)) break; // التحقق من الفوز أو التعادل
        displayBoard(board);

        if (choice == 1) {
            playerMove(board, 'O'); // حركة اللاعب 2
        } else {
            computerMove(board); // حركة الكمبيوتر
        }
        winner = checkWin(board);
    }

    displayBoard(board);

    if (winner == 1) {
        printf("Player X wins!\n");
    } else if (winner == 2) {
        printf("Player O wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' '; // ملء اللوحة بمسافات فارغة
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  %c  |  %c  |  %c  \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("-----|-----|-----\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (board[i][0] == 'X') ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (board[0][i] == 'X') ? 1 : 2;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return (board[0][0] == 'X') ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return (board[0][2] == 'X') ? 1 : 2;

    return 0;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        printf("Player %c, enter your move (row and column: 1-3 1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; // تحويل الإدخال إلى فهرس يبدأ من الصفر
        col--;
    } while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ');

    board[row][col] = player;
}

void computerMove(char board[SIZE][SIZE]) {
    int row, col;
    srand(time(0)); // تعيين البذرة العشوائية
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] != ' '); // التأكد من أن المربع فارغ

    printf("Computer chooses: Row %d, Column %d\n", row + 1, col + 1);
    board[row][col] = 'O';
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') // التحقق من وجود مربعات فارغة
                return 0;
        }
    }
    return 1;
}



