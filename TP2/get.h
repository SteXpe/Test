#ifndef _GET_H_
#define _GET_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clear();
int get_int(char* label);
float get_float(char* label);
char* get_word(char* label);

#endif