//Struktura przechowuj�ca konfiguracj� programu


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

