#include "args_analyzer.h"

config analyze_args(int argc, char** argv, config settings){
    int n=1, flagerror=0;
    while (n < argc) {
        if (strcmp(argv[n], "--help") == 0) {
            print_help();
        }
        else if (strcmp(argv[n], "--defchar") == 0) {
            if (strlen(argv[n+1]) != 1)
                print_error(1);  //w defchar więcej niż jeden znak
            else {
                n++;
                settings->defchar = argv[n][0];
            }
        }
        else if (strcmp(argv[n], "--random") == 0) {
            if (flagerror == 0) {
                flagerror++;
                int r = atoi(argv[n + 1]);
                int c = atoi(argv[n + 2]);
                if ((r > 0 && r <= 100) && (c > 0 && c <= 100)) {
                    settings->random[0] = r;
                    settings->random[1] = c;
                    n += 2;
                } else
                    print_error(2); //nieprawidłowy rozmiar kolumn/wierszy
            } else
                print_error(3); //podanie input i random jednocześnie
        }
        else if (strcmp(argv[n], "--input") == 0) {
            if (flagerror == 0) {
                strcpy(settings->input, argv[n + 1]);
                n++;
            } else
                print_error(2); //nieprawidłowy rozmiar kolumn/wierszy
        }
        else if (strcmp(argv[n], "--ngen") == 0) {
            n++;
            int  tmp = atoi (argv[n]);
            if (tmp > 0 && tmp<100 )
                settings->ngen = tmp;
            else
                print_error(4);     //liczba generacji poza zakresem
        }
        else if (strcmp(argv[n], "--output") == 0) {
            n++;
            strcpy(settings->output, argv[n]);
        }
        else if (strcmp(argv[n], "--backup") == 0) {
            settings->backup = 1;
        }
        else if (strcmp(argv[n], "--png") == 0) {
            settings -> ispngactive = 1;
        }
        else {
            print_error(5); //błędny argument
        }
        n++;
    }
    return settings;
}