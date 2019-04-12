#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txtFile_mngr.h"

void write_to_file(char* output, board cells){

    char *path = malloc((strlen(output)+ 12)* sizeof(char)) ;
    strcpy (path, output);
    strcat (path, "/backup.txt");
    FILE *out = fopen(path, "w");
    char **tmp = cells->matrix;

    for(int i=0; i<cells->rows; i++){

         for(int j=0; j<cells->columns; j++){

             fprintf(out,"%c", tmp[i][j] );
         }

         fprintf(out, "\n");
    }
    free(path);
    fclose(out);

}


int read_file(char* filename, board cells, char defchar)
{

    FILE *in = fopen(filename, "r");

    if(in==NULL)
    {
        print_error(9);
        return 1;
    }


    int row_len[100];
    int rows=0;
    int columns=0;
    int c;
    int sym_error=0;
    int dim_error=0;



    while((c=fgetc(in))!=EOF)
    {

        if(rows>100||columns>100)
        {
            dim_error++;
            break;
        }
        if(c!='0'&&c!=' '&&c!=defchar&&c!='\n'&&c!='\0'&&c!='\t')
        {
            sym_error++;
            break;
        }
        if(c=='0'||c==defchar)
            columns++;

        if(c=='\n'&&columns!=0)
        {
            row_len[rows]=columns;
            columns=0;
            rows++;
        }



    }

    if(sym_error!=0)
    {
        print_error(8);
        return 1;
    }
    if(dim_error!=0)
    {
        print_error(2);
        return 1;
    }

    if(rows!=0)
    {
        columns = row_len[0];
        for(int i=1; i<rows; i++)
        {
            if(row_len[i]!=columns)
            {
                print_error(12);
                return 1;

            }
        }

        rewind(in);

        char **tmp = malloc(rows*sizeof(char*));
        for(int i=0; i<rows;)
        {
            tmp[i] = malloc(columns*sizeof(char));
            for(int j=0; j<columns;)
            {
                c=fgetc(in);
                if(c=='0'||c==defchar)
                {
                    tmp[i][j]=c;
                    j++;
                }

            }
            i++;

        }

        cells->matrix = tmp;
        cells->rows = rows;
        cells->columns = columns;

        printf("Input read successfully\n");
        fclose(in);
    }

    else
    {

        print_error(13);
        fclose(in);
        return 1;

    }

    return 0;


}



























