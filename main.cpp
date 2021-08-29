#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "text_analys.h"

int main(int argc, const char* argv[]) {
	const char file_name[] = { "hamlet.txt" };
	struct Text hamlet = { 0 };
	
	text_init(&hamlet, file_name);

	return 0;
}