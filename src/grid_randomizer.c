#include <stdlib.h>
#include <time.h>
#include "grid_randomizer.h"


void grid_randomizer(board cells, char defchar){

    cells->matrix = malloc(cells->rows*sizeof(char*));

    for(int i=0; i< cells->rows; i++){

        cells->matrix[i] = malloc(cells->columns*sizeof(char));
    }

    char t[2];
    t[0] = '0';
    t[1] = defchar;
    int t_index;

    srand(time(NULL));

    for(int i=0; i< cells->rows; i++){

        for(int j=0; j< cells->columns; j++)
        {
            t_index = rand()%2;
            cells->matrix[i][j] = t[t_index];
        }

    }



}




