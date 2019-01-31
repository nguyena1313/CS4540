#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cityStruct {
	unsigned int zip;
	char * town; } city;
typedef struct zipTownsStruct {
	int * zips;		// indexs to main array cities sorted by zip
	city * * towns;	// pointers to main array cities sorted by town name
	city * cities;	// main array of cities in order from file not sorted
} zipTowns;

#endif //!STRUCTS_H
