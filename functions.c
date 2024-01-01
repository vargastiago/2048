#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void insert_value(int gameBoard[][MAX]) {
    for (;;) {
        int i = rand() % MAX;
        int j = rand() % MAX;

        if (gameBoard[i][j] == 0) {
            gameBoard[i][j] = generate_value();
            break;
        }
    }
}

int generate_value() {
    if (rand() % 5 == 0) {
        return 4;
    }

    return 2;
}

void iniciateBoard(int gameBoard[][MAX]) {
    for (int i = 0; i < 2; i++) {
        insert_value(gameBoard);
    }
}

void printBoard(int gameBoard[][MAX]) {
    system("clear");

    for (int i = 0; i < MAX; i++) {
        printf("%s", "\n|-------------------|\n|");

        for (int j = 0; j < MAX; j++) {
            if (gameBoard[i][j] == 0) {
                printf("%s", "    |");
            } else {
                printf("%4d|", gameBoard[i][j]);
            }
        }
    }

    printf("%s", "\n|-------------------|\n");
    printf("%s", "\n1 (left) | 2 (up) | 3 (down) | 4 (right) | 0 (quit): ");
}

void moveUp(int gameBoard[][MAX]) {
    for (int column = 0; column < MAX; column++) {
        int exchangePosition = 0;

        for (int currentPosition = 1; currentPosition < MAX; currentPosition++) {
            if (gameBoard[currentPosition][column] == 0) {
                continue;
            }

            if (gameBoard[exchangePosition][column] == gameBoard[currentPosition][column]) {
                gameBoard[exchangePosition][column] *= 2;
                gameBoard[currentPosition][column] = 0;
                exchangePosition++;
            } else if (gameBoard[exchangePosition][column] == 0) {
                gameBoard[exchangePosition][column] = gameBoard[currentPosition][column];
                gameBoard[currentPosition][column] = 0;
            } else {
                exchangePosition++;

                if (exchangePosition != currentPosition) {
                    gameBoard[exchangePosition][column] = gameBoard[currentPosition][column];
                    gameBoard[currentPosition][column] = 0;
                }
            }
        }
    }
}

void moveDown(int gameBoard[][MAX]) {
    for (int column = 0; column < MAX; column++) {
        int exchangePosition = MAX - 1;

        for (int currentPosition = MAX - 2; currentPosition >= 0; currentPosition--) {
            if (gameBoard[currentPosition][column] == 0) {
                continue;
            }

            if (gameBoard[exchangePosition][column] == gameBoard[currentPosition][column]) {
                gameBoard[exchangePosition][column] *= 2;
                gameBoard[currentPosition][column] = 0;
                exchangePosition--;
            } else if (gameBoard[exchangePosition][column] == 0) {
                gameBoard[exchangePosition][column] = gameBoard[currentPosition][column];
                gameBoard[currentPosition][column] = 0;
            } else {
                exchangePosition--;

                if (exchangePosition != currentPosition) {
                    gameBoard[exchangePosition][column] = gameBoard[currentPosition][column];
                    gameBoard[currentPosition][column] = 0;
                }
            }
        }
    }
}

void moveRight(int gameBoard[][MAX]) {
    for (int row = 0; row < MAX; row++) {
        int exchangePosition = MAX - 1;

        for (int currentPosition = MAX - 2; currentPosition >= 0; currentPosition--) {
            if (gameBoard[row][currentPosition] == 0) {
                continue;
            }

            if (gameBoard[row][exchangePosition] == gameBoard[row][currentPosition]) {
                gameBoard[row][exchangePosition] *= 2;
                gameBoard[row][currentPosition] = 0;
                exchangePosition--;
            } else if (gameBoard[row][exchangePosition] == 0) {
                gameBoard[row][exchangePosition] = gameBoard[row][currentPosition];
                gameBoard[row][currentPosition] = 0;
            } else {
                exchangePosition--;

                if (exchangePosition != currentPosition) {
                    gameBoard[row][exchangePosition] = gameBoard[row][currentPosition];
                    gameBoard[row][currentPosition] = 0;
                }
            }
        }
    }
}

void moveLeft(int gameBoard[][MAX]) {
    for (int row = 0; row < MAX; row++) {
        int exchangePosition = 0;

        for (int currentPosition = 1; currentPosition < MAX; currentPosition++) {
            if (gameBoard[row][currentPosition] == 0) {
                continue;
            }

            if (gameBoard[row][exchangePosition] == gameBoard[row][currentPosition]) {
                gameBoard[row][exchangePosition] *= 2;
                gameBoard[row][currentPosition] = 0;
                exchangePosition++;
            } else if (gameBoard[row][exchangePosition] == 0) {
                gameBoard[row][exchangePosition] = gameBoard[row][currentPosition];
                gameBoard[row][currentPosition] = 0;
            } else {
                exchangePosition++;

                if (exchangePosition != currentPosition) {
                    gameBoard[row][exchangePosition] = gameBoard[row][currentPosition];
                    gameBoard[row][currentPosition] = 0;
                }
            }
        }
    }
}
