#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int main(void) {
    int gameBoard[MAX][MAX] = {0};

    srand(time(NULL));

    iniciateBoard(gameBoard);
    printBoard(gameBoard);

    int option;
    scanf("%d", &option);

    while (option != 0) {
        switch (option) {
        case 1:
            moveLeft(gameBoard);
            break;

        case 2:
            moveUp(gameBoard);
            break;

        case 3:
            moveDown(gameBoard);
            break;

        case 4:
            moveRight(gameBoard);
            break;
        }

        insert_value(gameBoard);
        printBoard(gameBoard);
        scanf("%d", &option);
    }
}
