#include <stdio.h>
#include <stdlib.h>

#include "error_handler.h"


void print_error(int errcode) { //poprawka 2 - usuniecie config
    printf("Error no. %2i, ", errcode);
    switch (errcode) {
        case 1: {
            printf("defchar: more than one char was given. \n");
            printf("Program will terminate.\n");
        }; break;
        case 2: {
            printf("random/input: wrong matrix dimensions! Max dim: 100x100 .\n");
            printf("Program will terminate.\n");
        }; break;
        case 3: {
            printf("random/input: both flags were specified at once.\n");
            printf("Program will terminate.\n");
        }; break;
        case 4: {
            printf("ngen: generation number not in the range of (0; 100>.\n"); //poprawka 1
        }; break;
        case 5: {
            printf("stdin: unrecognized flags.\n");
            printf("Program will terminate.\n");
        }; break;
        case 6 : {
            printf("stdin: more than one flag of each type was entered.\n");
            printf("Program will terminate.\n");
        }; break;
        case 7: {
            printf ("input: no input file specified. Program will terminate.\n");
            printf("Program will terminate.\n");
        }; break;
        case 8: {
            printf ("input: there are symbols in the input which are not accepted. \n");
            printf("Program will terminate.\n");
        }; break;
        case 9: {
            printf ("input: no such file or directory. \n");
            printf("Program will terminate.\n");
        }; break;
        case 10: {
            printf ("defchar: '0' symbol was given. Setting defchar to '1'.\n");
        }; break;
        case 11: {
            printf ("ngen: no generation number entered\n");                                            //poprawka 3
        }; break;
        case 12: {
            printf ("input: matrix has uneven columns. \n");
            printf("Program will terminate.\n");
        }; break;
        case 13: {
            printf ("input: matrix is empty. \n");
            printf("Program will terminate.\n");
        }; break;
        default: {
            printf("a.out: program encountered an error.\n");
            printf("Program will terminate.\n");
        }
    }
    if (errcode != 4 && errcode != 10 && errcode != 11) {   //poprawka 4
        exit(errcode);
    }
    return;
}
