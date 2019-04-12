/*Struktura przechowuje macierz prostokatna wypelniona 0 i 1 - zerowa generacje
a takze parametry tej macierzy */
#ifndef _BOARD_STORAGE_
#define _BOARD_STORAGE_


typedef struct {

    int rows;
    int columns;
    char** matrix;

} *board;

#endif // _BOARD_STORAGE_

