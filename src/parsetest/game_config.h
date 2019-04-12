#ifndef _GAME_CONFIG_
#define _GAME_CONFIG_

//Struktura przechowujaca konfiguracje programu
typedef struct {

    int help;
    char defchar;
    int random[2];
    char* input;
    char* output;
    int backup;
    int ispngactive;
    int ngen;

} *config;




#endif // _GAME_CONFIG_

