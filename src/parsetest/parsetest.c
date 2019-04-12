#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "args_analyzer.h"


int main (int argc, char **argv) {
    //char* argv[12] = malloc (12*sizeof(char*));
    /*strcpy(argv[0], "program");
    strcpy(argv[1], "--help");
    strcpy(argv[2], "--defchar");
    strcpy(argv[3], "#");
    strcpy(argv[4], "--random");
    strcpy(argv[5], "5");
    strcpy(argv[6], "10");
    strcpy(argv[7], "--input");
    strcpy(argv[8], "../input/plik.txt");
    strcpy(argv[9], "--ngen");
    strcpy(argv[10], "5");
    strcpy(argv[11], "--backup");
    strcpy(argv[12], "--png");
    */
    config settings = malloc(sizeof(*settings));
    //settings = [0, '1', [0,0], NULL, NULL, 0, 0, 0 ];
    settings = analyze_args(argc, argv, settings);
    //memcpy(settings, analyze_args(12, argv, settings), sizeof (settings));
    printf ("defchar: %c, random: %i %i, input: %s, output: %s, ngen: %i, backup: %i, png: %i \n",
             settings->defchar, settings->random[0], settings->random[1], settings->input, settings->output, settings->ngen, settings->backup, settings->ispngactive);
	free(settings);
    //print_error(1);
    //print_help();
    return 0;
}

