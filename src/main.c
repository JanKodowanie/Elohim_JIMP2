#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board_storage.h"
#include "game_config.h"
#include "args_analyzer.h"
#include "error_handler.h"
#include "txtFile_mngr.h"
#include "grid_randomizer.h"
#include "game_of_life.h"

int main(int argc, char **argv)
{

    config cfg = malloc(sizeof(*cfg));
    board cells = malloc(sizeof(*cells));

    int err_indicator = analyze_args(argc, argv, cfg);
    if(err_indicator!=0)
    {
        free_heap(cfg, cells);
        return EXIT_FAILURE;
    }

    if(cfg->random[0]==0||cfg->random[1]==0)
    {
        err_indicator = read_file(cfg->input, cells, cfg->defchar);
        if(err_indicator!=0)
        {
            free_heap(cfg, cells);
            return EXIT_FAILURE;
        }
    }
    else
    {
        cells->rows = cfg->random[0];
        cells->columns = cfg->random[1];

        fill_random(cells, cfg->defchar);

    }

    transform_cells(cells, cfg);
    printf("Cell transformation executed successfully!\n");


    if(cfg->backup == 1)
        write_to_file(cfg->output, cells);
    else if (cells->rows < 20 && cells->columns < 20)
    {
        printf("%i-th generation:\n", cfg->ngen);
        for (int i=0; i<cells->rows; i++)
        {
            for (int j=0; j<cells->columns; j++)
                printf("%c ", cells->matrix[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("Matrix too big to write to stdout. \n");
    }
    if (cfg->output != NULL)
        printf("Output files created in directory %s\n", cfg->output);

    free_heap(cfg, cells);

    return EXIT_SUCCESS;

}
