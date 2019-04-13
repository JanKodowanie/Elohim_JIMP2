#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "board_storage.h"
#include "txtFile_mngr.h"


int main(int argc, char **argv){

    if(argc!=3){
        printf("Launch with 2 arguments: input, defchar\n");
        return EXIT_FAILURE;
    }

    char* input = argv[1];
    char  defchar = argv[2][0];

    char* output = "output";
    mkdir(output, 0777);

    board test = malloc(sizeof(*test));

    int n = read_file(input, test, defchar);

    if(n==0){

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
    }
    else{
        printf("Errors encountered!\n");
        free(test);
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;

}
