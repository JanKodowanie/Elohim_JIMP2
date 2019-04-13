#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/stat.h>
#include <sys/types.h>
#include "args_analyzer.h"
#include "error_handler.h"
//#include "help.h"

struct stat st = {0};

void print_help() {
	printf("Help \n");
}

config analyze_args(int argc, char** argv)
{

    config settings = malloc(sizeof(*settings));
    settings->defchar='1';
    settings->random[0] = 0;
    settings->random[1] = 0;
    settings->backup = 0;
    settings->ispngactive = 0;
    settings->input = NULL;
    settings->output = NULL;

    int flagcounter[8] = {0,0,0,0,0,0,0,0};
    int n=1, flagerror=0;
    while (n < argc)
    {
        if (strcmp(argv[n], "--help") == 0) {
            flagcounter[0]++;
            free(settings);
            print_help();
        }
        else if (strcmp(argv[n], "--defchar") == 0)
        {
            flagcounter[1]++;
            if (strlen(argv[n+1]) != 1) {
                free(settings);
                print_error(1);
            }
            else {
                if (argv[n+1][0] != '0') {
                    n++;
                    settings->defchar = argv[n][0];
                }
                else {
                    print_error(10);       //defchar: podanym znakiem jest 0
                }
            }
        }
        else if (strcmp(argv[n], "--random") == 0)
        {
            flagcounter[2]++;
            if (flagerror == 0) {
                flagerror++;
                int r = atoi(argv[n + 1]);
                int c = atoi(argv[n + 2]);
                if ((r > 0 && r <= 100) && (c > 0 && c <= 100)) {
                    settings->random[0] = r;
                    settings->random[1] = c;
                    n += 2;
                }
                else {
                    free(settings);
                    print_error(2);
                }
            }
            else {
                free(settings);
                print_error(3);
            }
        }
        else if (strcmp(argv[n], "--input") == 0) {
            flagcounter[3]++;
            if (flagerror == 0) {
                flagerror++;
                settings->input = malloc((strlen(argv[n+1])+1) * sizeof(char));
                strcpy(settings->input, argv[n + 1]);
                n++;
            }
            else {
                free(settings->input);
                free(settings);
                print_error(3);
            }
        }
        else if (strcmp(argv[n], "--ngen") == 0) {
            flagcounter[4]++;
            n++;
            char* tmp = argv[n];
            if (atoi(tmp) > 0 && atoi(tmp) <= 100 )
                settings->ngen = atoi(tmp);
            else {
                print_error(4);
                printf("Please input a number from range: (0, 100> or press\n");
                printf("CTRL+C, to exit.\n");
                while( !(atoi(tmp) > 0 && atoi(tmp) <= 100) ) {
                    scanf("%s", tmp);
                }
                settings->ngen = atoi(tmp);
            }
        }
        else if (strcmp(argv[n], "--output") == 0) {
            flagcounter[5]++;
            n++;
            settings->output = malloc((strlen(argv[n])+1) * sizeof(char));
            strcpy(settings->output, argv[n]);
            if (stat(settings->output, &st) == -1) {
                mkdir(settings->output, 0777);
            }
        }
        else if (strcmp(argv[n], "--backup") == 0) {
            flagcounter[6]++;
            settings->backup = 1;
        }
        else if (strcmp(argv[n], "--png") == 0) {
            flagcounter[7]++;
            settings -> ispngactive = 1;
        }
        else {
            free(settings);
            print_error(5);
        }
        n++;
    }
    for (int i=0; i<8; i++) {
        if (flagcounter[i] > 1) {
	    free(settings);
        print_error(6);
        }
    }
    if ( flagcounter[5] == 0 && (flagcounter[6] == 1 || flagcounter[7] == 1) ) {
        settings->output = malloc(7 * sizeof(char));
        strcpy(settings->output, "output");
        if (stat(settings->output, &st) == -1)
            mkdir(settings->output, 0777);
    }
    if (flagcounter[4] == 0) {
        print_error(11);
        char* tmp1 = malloc(sizeof(*tmp1));
        printf("Please input a number from range: (0, 100> or press\n");
        printf("CTRL+C, to exit.\n");
        while( !(atoi(tmp1) > 0 && atoi(tmp1) <= 100) ) {
            scanf("%s", tmp1);
        }
        settings->ngen = atoi(tmp1);
        free(tmp1);
    }

    return settings;
}

