#ifndef READFILE_H
#define READFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

void insertZip(int zip, int index, zipTowns arrs,int length);
void insertCity(char * town, city * addr, zipTowns arrs, int length);
extern void readFile(zipTowns arrs, FILE * infile, int * length);


#endif // last line of file
