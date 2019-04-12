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
    board cells = malloc(sizeof(*cells));

    if(cfg->random[0]==0||cfg->random[1]==0){
        read_file(cfg->input, cells, cfg);
	free(cfg->input);
    }
    else{
        cells->rows = cfg->random[0];
        cells->columns = cfg->random[1];

        fill_random(cells, cfg->defchar);

    }

    transform_cells(cells, cfg);

    if(cfg->backup == 1)
        write_to_file(cfg->output, cells);
    else {
	if (cells->rows < 20 && cells->columns < 20) {
		printf("%i-th generation:\n", cfg->ngen);
    		for (int i=0; i<cells->rows; i++) {
			for (int j=0; j<cells->columns; j++)
				printf("%c ", cells->matrix[i][j]);
			printf("\n");
		}
	}
    }
    if (cfg->output != NULL) {
	   printf("Output files created in directory %s\n", cfg->output);
	   free(cfg->output);
    }

    free(cfg);

   for(int i=0; i<cells->rows; i++){
       free(cells->matrix[i]);
   }
   free(cells->matrix);
   free(cells);


    return EXIT_SUCCESS;





}


