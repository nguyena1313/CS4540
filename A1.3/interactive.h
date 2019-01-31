#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

int find_index1(struct zipTownsStruct struct_ptr, int num_elements, char * towname);
int find_index2(struct zipTownsStruct struct_ptr, int num_elements, int value);
extern void doInteractive(zipTowns arrs, int length);

#endif // last line of file
