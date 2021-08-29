#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_LINES 5000
#define MAX_LEN_LINE 400

#define OUTPUT_FILE "output.txt"

struct line {
	char* symbols;
	int length;
};

struct Text {
	FILE* file;
	struct line* lines; 
	int lines_count;
	const char* file_name;
	char* buffer;
	size_t size;
};

//=================== D O X Y ====================
int text_init(struct Text* text, const char* name);

