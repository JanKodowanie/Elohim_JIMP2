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

int main(int argc, char **argv){

    config cfg = analyze_args(argc, argv);
    board cells = malloc(sizeof(board));

    if(cfg->random[0]==0||cfg->random[1]==0){
        read_file(cfg->input, cells, cfg->defchar);
    }
    else{
        cells->rows = cfg->random[0];
        cells->columns = cfg->random[1];

        grid_randomizer(cells, cfg->defchar);

    }

    transform_cells(cells, cfg);

    if(cfg->backup == 1)
        write_to_file(cfg->input, cells);

    free(cfg);
    free(cells);

    return EXIT_SUCCESS;





}


