#include <stdio.h>
#include <stdlib.h>
#include "board_storage.h"
#include "txtFile_mngr.h"


int main(int argc, char **argv){

    if(argc!=4){
        printf("Podaj 3 argumenty: input, output, defchar\n");
        return EXIT_FAILURE;
    }

    char* input = argv[1];
    char* output = argv[2];
    char  defchar = argv[3][0];

    board test = malloc(sizeof(*test));

    read_file(input, test, defchar);



    for(int i=0; i<test->rows; i++){

        for(int j=0; j<test->columns; j++){

            printf("%c", test->matrix[i][j]);

        }
    printf("\n");

    }
    write_to_file(output, test);

    for(int i=0; i<test->rows; i++)
        free(test->matrix[i]);

    free(test->matrix);
    free(test);




    return EXIT_SUCCESS;

}

