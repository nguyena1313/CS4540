#define _CRT_SECURE_NO_WARNINGS // you can remove this line
#include <stdlib.h>   // For _MAX_PATH definition
#include <stdlib.h>
#include <string.h>

#include "interactive.h"
#include "readfile.h"
#include "structs.h"


void getArrs(zipTowns * arrs, int size) {  // mallocs arrays of size elements
	arrs->zips = (int *) malloc(sizeof(int) * size);
	arrs->towns = (struct cityStruct **) malloc(sizeof(struct cityStruct *) *size);
	arrs->cities = (struct cityStruct *) malloc(sizeof(struct cityStruct) * size);

	// two more lines
	// zips[0] is an int
	// towns[0] is a (citie *)
	// city[0] is a citie
}

extern int getArgsInfoOpenFile(int argc, char * argv[], FILE * * infile, int * size); // 0 ok, !0 error

int main(int argc, char * argv[]) {
	zipTowns arrs; // all the arrays in one struct
	int length = 0;		// current count of items in arrays

	FILE * infile = NULL;

	int ret=0, size;

	if (getArgsInfoOpenFile(argc, argv, &infile, &size)) {
		printf("error in command line arguments\n");
		ret = -1;
	}

	else {
		getArrs(&arrs, size);
		readFile(arrs, infile, &length);
		printf("Length is %d \n", length);
		fclose(infile);
		doInteractive(arrs, length);
	} // end else no error in command line
	printf("press any key: ");
	getc(stdin);

	return ret;
}

int getArgsInfoOpenFile(int argc, char * argv[], FILE ** infile, int * size) // 0 ok else !0 error
{
	int retval = 0;
	// test for correct arguments number 3: exename, filename, size
	// attempt to open file

if(argc !=3){
	retval =1;
}

*infile = fopen(argv[1], "r");

char* filname = argv[1];
printf("File name: %s \n", filname);
if(infile == NULL){
	retval = 1;
}

else{
	*size = atoi(argv[2]);
	printf("%d \n", *size);
}
	// return file and size in parameters or error
	return retval;
}
