#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board_storage.h"
#include "grid_randomizer.h"
int main(int argc, char **argv){

    if(argc=4 && atoi(argv[1])>0 && atoi(argv[2])>0 && strlen(argv[3])==1 ){
    board test = malloc(sizeof(*test));
    test->rows = atoi(argv[1]);
    test->columns = atoi(argv[2]);
    char defchar = argv[3][0];
    fill_random(test, defchar);

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
    return EXIT_SUCCESS;
    }
    else{
    printf("Launch with 3 arguments - rows, columns, defchar\n");
    return EXIT_FAILURE;
    }


}

