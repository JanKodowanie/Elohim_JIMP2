#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "args_analyzer.h"


int main (int argc, char **argv) {
 
    config settings = malloc(sizeof(*settings));

    settings = analyze_args(argc, argv, settings);

    printf ("defchar: %c, random: %i %i, input: %s, output: %s, ngen: %i, backup: %i, png: %i \n",
             settings->defchar, settings->random[0], settings->random[1], settings->input, settings->output, settings->ngen, settings->backup, settings->ispngactive);
	free(settings);

    return 0;
}

