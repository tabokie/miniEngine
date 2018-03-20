#include "api.h"
#include "stem_algorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void stem_file(struct SN_env * z, FILE * f_in, FILE * f_out) {
    #define INC 10
        int lim = INC;
        symbol * b = (symbol *) malloc(lim * sizeof(symbol));

        while(1) {
            int ch = getc(f_in);
            if (ch == EOF) {
                free(b); return;
            }
            {
                int i = 0;
                while(1) {
                    if (ch == ' ' || ch == EOF || ch == '\n' || ch == '$') break;
                    
                    if (i == lim) {  /* make b bigger */
                        symbol * q = (symbol *) malloc((lim + INC) * sizeof(symbol));
                        memmove(q, b, lim * sizeof(symbol));
                        free(b); b = q;
                        lim = lim + INC;
                    }
                    b[i] = ch; i++;
                    ch = getc(f_in);
                }

                SN_set_current(z, i, b);
                stem(z);
                {
                    int j;
                    for (j = 0; j < z->l; j++) fprintf(f_out, "%c", z->p[j]);
                    if(ch == '\n')fprintf(f_out, "\n");
                    else if (ch == '$'){ // control chr
                        while(1){
                            if (ch == '\n' || ch == EOF){
                                fprintf(f_out, "\n");
                                break;
                            }
                            fprintf(f_out, "%c", ch);
                            ch = getc(f_in);
                        }
                    }
                    else fprintf(f_out, " ");
                }
            }
        }
    }

// cursor at $
inline int get_title(FILE * f_data){
    int ch;
    int found_title = 0;
    while(1){
        ch = getc(f_data);
        printf("%c",ch);
        if(ch == EOF)return 0;
        if(ch != '$')found_title = 1;
        if(found_title && ch == '$'){
            printf("\n");
            getc(f_data);// two $ as end
            return 1;
        }
    }
    return 0;
}


void write(FILE * f_data, FILE * f_out, FILE * f_manifest){

    int id = 0;
    int offset = 0;
    int p_offset = 0;
    int in_sentence = 0;
    int in_interval = 0;
    int ch = 0;
    while(ch != '$'){
        ch = getc(f_data);
    }
    while(1){
        if(feof(f_data))break;
        if(!get_title(f_data))break;
        id++;
        fprintf(f_manifest, "{\n    \"id\" : %d,\n    \"offset\" : %d,\n    ",id,p_offset);
        fprintf(f_manifest, "\"sentences\" : [0,");
        offset = 0;
        while(1){
            ch = getc(f_data);
            // ctrl
            if(ch == '$' || ch == EOF)break;
            // another sentence
            if(ch == '\n' && in_sentence){
                offset += 2;
                fprintf(f_out, "\n");
                fprintf(f_manifest, "%d,",offset);
                in_sentence = 0;
                in_interval = 0;
            }
            // another word
            else if(ch == ' ' && in_sentence && !in_interval){
                offset ++;
                fprintf(f_out, " ");
                in_interval = 1;
            }
            // read a word
            else if(ch != ' ' && ch != '\n'){
                offset++;
                fprintf(f_out, "%c", ch);
                in_sentence = 1;
                in_interval = 0;
            }
            
        }
        fprintf(f_manifest, "]\n},\n" );
        p_offset += offset;
    }

}


int main(void){

	struct SN_env * z = create_env();
    FILE * f_in;
    FILE * f_stemmed;
    FILE * f_token;
    FILE * f_manifest;
    if( (f_in = fopen("../data/raw_token", "r")) == NULL){
    	printf("Error open file !\n");
    	exit(0);
    }

    if( (f_stemmed = fopen("../data/stemmed", "w+")) == NULL){
    	printf("Error open file !\n");
    	exit(0);
    }

    if( (f_token = fopen("../data/token", "w")) == NULL){
        printf("Error open file !\n");
        exit(0);
    }

    if( (f_manifest = fopen("../data/token_manifest", "w")) == NULL){
        printf("Error open file !\n");
        exit(0);
    }

    stem_file(z, f_in, f_stemmed);
    close_env(z);

    rewind(f_stemmed);
    write(f_stemmed, f_token, f_manifest);

    if(fclose(f_in) || fclose(f_stemmed) || fclose(f_token) || fclose(f_manifest)){
    	printf("Error close file !\n");
    	exit(0);
    }

	return 0;
}