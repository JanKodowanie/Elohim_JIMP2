#include <stdio.h>
#include <stdlib.h>
#include "board_storage.h"
#include "grid_randomizer.h"
int main(int argc, char **argv){

    if(argc=4){
    board test = malloc(sizeof(*test));
    test->rows = atoi(argv[1]);
    test->columns = atoi(argv[2]);
    char defchar = argv[3][0];
    grid_randomizer(test, defchar);

    for(int i=0; i<test->rows; i++){

        for(int j=0; j<test->columns; j++){

            printf("%c", test->matrix[i][j]);

        }
    printf("\n");

    }
    for(int i=0; i<test->rows; i++)
            free(test->matrix[i]);
    free(test->matrix);
    free(test);
    return 0;
    }
    else{
    printf("Podaj 3 argumenty - row, col, znak\n");
    return 1;
    }


}

