#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "help.h"

void print_help() {
    system("clear");

    printf("\n");
    printf(" _____ _       _     _           \n");
    printf("|  ___| |     | |   (_)          \n");
    printf("| |__ | | ___ | |__  _ _ __ ___  \n");
    printf("|  __|| |/ _ \\| '_ \\| | '_ ` _ \\ \n");
    printf("| |___| | (_) | | | | | | | | | |\n");
    printf("\\____/|_|\\___/|_| |_|_|_| |_| |_|\n");
    printf("\n");
    printf("HOW TO USE A GAME OF LIFE SIMULATOR\n");
    printf("by Michał Balas, Jan Dobrowolski, 2019\n");
    printf("\n");
    printf("\n");
    printf("FLAGS: \n\n");
    printf("--ngen (int) - number of generations to process. It's the ");
    printf("most crucial flag for program's correct working. The number should be in range of 0 to 100 (included). ");
    printf("If the ngen value would not be specified or will be done wrongly, the program will keep asking until a correct value is entered.");
    printf("\n\n");
    printf("--defchar (char) - a character used as a symbol of a living cell either while transforming, reading or printing a cell matrix. ");
    printf("\n\n");
    printf("--backup - a flag specifies if a .txt file with the last created cell matrix should be written or not. ");
    printf("No additional arguments here. If output dir has been/will be specified, backup.txt file will be saved there. Otherwise a folder output/ in .exe dir will be created or overwritten.");
    printf("\n\n");
    printf("--input (path to file) - determines a text file as a source of 0th generation of cells to be used in a simulation. ");
    printf("The file should consist of rows and columns (each having equal length) filled with '0's and defchars. NOTE: defchar is set to 1 in default. ");
    printf("To read a file containing other symbol use defchar flag. This flag must not be used with --random.");
    printf("\n\n");
    printf("--random (int) (int) - creates a cell matrix with dimensions set as the two arguments (rows x columns). Condition: both rows and cols <= 100. ");
    printf("This option cannot be used along with input, as the program would get two different sources of 0th gen.");
    printf("\n\n");
    printf("--output (path) - this flag specifies an output directory for png and backup files. If the given dir doesn't exist, one will be created.");
    printf("\n\n");
    printf("--png - this flag determines if a png file of each generation should be created in the output dir.");
    printf("\n\n");
    printf("--help - shows help. How did you even get here without knowing that?");
    printf("\n\n");
    printf("Now you've learned how to use a Game of Life simulator. Now run Elohim.exe once again and feel godlike.");
    printf("\n\n");

    exit(EXIT_SUCCESS);
}
