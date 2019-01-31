#define _CRT_SECURE_NO_WARNINGS // you can remove this line
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readfile.h"
#include "structs.h"

void insertZip(int zip, int index, zipTowns arrs, int length){
	int j = length-1;
	while(j>=0 && arrs.cities[arrs.zips[j]].zip > zip){
		arrs.zips[j+1] = arrs.zips[j];
		j--;
	}
	arrs.zips[j+1] = index;
}

void insertCity(char * town, city* addr, zipTowns arrs, int length){
	int j =length - 1;
	while(j>=0 &&
		strcmp(arrs.towns[j]->town, town) > 0
	){
		arrs.towns[j+1] = arrs.towns[j];
		j--;
	}
	arrs.towns[j + 1] = addr;

}

extern void readFile(zipTowns arrs, FILE * infile, int * length){

	char townname[100];

	int zip = 0;
	int i = 0;
	while(fscanf(infile, "%d %s\n", &zip, townname) == 2)
	{
		int len = strlen(townname);
		arrs.cities[i].zip = zip;
		arrs.cities[i].town = malloc(sizeof(char) * (len + 1));
		strcpy(arrs.cities[i].town, townname);
		insertZip(zip, i, arrs, i);
		insertCity(townname, &(arrs.cities[i]), arrs, i);
		i++;
	}


	*length = i;
}
