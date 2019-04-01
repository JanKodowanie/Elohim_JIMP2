#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_
#define MAXLINES 100
#define MAXCOL 100
#include "board_storage.h"
#include "game_config.h"
#include "error_handler.h"

void read_file(char*, board, char);
void write_to_file(char*, board);


#endif // _FILE_MANAGER_
