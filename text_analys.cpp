#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <assert.h>
#include <malloc.h>
#include "text_analys.h"

// fseek, ftell
// всё в buffer<-fread
// strchr \n cnt++
// calloc

//======================================================================
int text_init(struct Text* text, const char* name) {
    assert(text != NULL);
    assert(name != NULL);

    int val = 0;

    text->file = fopen(name, "rb");
    assert(text->file != nullptr);

    val =  fseek(text->file, 0L, SEEK_END);
    if (val != 0) {
        printf("Failed to find end of file.\n");
        return -1;
    }

    text->size = ftell(text->file);
    fseek(text->file, 0L, SEEK_SET);

    text->buffer = (char*)calloc(text->size, sizeof(char));

    val = fread(text->buffer, sizeof(char), text->size, text->file);
    assert(val == (text->size/sizeof(char)));

    // printf("%s\n", text->buffer);
    
    // 1) count("\n") - line_counts
    // 2) count symbols in line by (while not "\n" data+=buff[i])

    text->lines = (line*)calloc(text->lines_count, sizeof(line));
    // text->lines[count_line]->symbols = (char*)calloc(n, sizeof(char));

    return 0;
}


