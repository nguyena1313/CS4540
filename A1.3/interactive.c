
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interactive.h"
#include "structs.h"

int find_index2(struct zipTownsStruct struct_ptr, int num_elements, int value)
{
	//binary search
		int found = -1;
		int top = 0;
		int btm = num_elements - 1;
		int mid;
		int h = 0;
		while (found == -1 && top <= btm) {
			mid = (btm + top) / 2;
			int ind = struct_ptr.zips[mid];
			//printf("the index is: %\nd", ind);
			struct cityStruct cit = struct_ptr.cities[ind];
			int zipp = cit.zip;
			//printf("Zip: %d\n", zipp);
			//townval = cit.town;
			//printf("City: %s\n", cit.town);

			if (zipp == value) {
				found = mid;
				printf("Found \n");
				printf("Zip: %d\n", zipp);
				printf("City: %s\n", cit.town);
				//return(ind);
			}

			else if (value < zipp) {
				btm = mid - 1;
			}
			else top = mid + 1;
		}

		if (found == -1) {
			printf("Zip not found.");
		}

	//printf("Zip not found.");
	return (found);

}

int find_index1(struct zipTownsStruct struct_ptr, int num_elements, char* name)
{
	//binary search
		int found = -1;
		int top = 0;
		int btm = num_elements - 1;
		int mid;
		int h = 0;
		while (found == -1 && top <= btm) {
			mid = (btm + top) / 2;
			char* town = struct_ptr.towns[mid]->town;
			//printf("the index is: %\nd", ind);
			int zip = struct_ptr.towns[mid]->zip;
			//int zipp = cit.zip;
			//printf("Zip: %d\n", zip);
			//townval = cit.town;
		//printf("City: %s\n", town);

			if (strcmp(town, name) ==0 ) {
				found = mid;
				printf("Found \n");
				printf("City: %s\n", town);
				printf("Zip: %d\n", zip);
				//return(ind);
			}

			else if (strcmp(name, town) <0 ) {
				btm = mid - 1;
			}
			else top = mid + 1;
		}

		if (found == -1) {
			printf("City not found.");
		}

	//printf("Zip not found.");
	return (found);

}
void doInteractive(zipTowns arrs, int length) {



	printf("Please pick an option. \n");
	printf("1. Search for zip code\n");
	printf("2. Search for town name\n");
	printf("3. Exit(0)\n");
	int option;
	int zipval = 0;
	char inp[20];
	char * townval = "";
	scanf("%d", &option);

	printf("This is your option: %d\n", option);

	switch (option) {

	case 1:
		printf("Enter a zip code: \n" );
		scanf("%d", &zipval);
		find_index2(arrs, length, zipval);
		break;
	case 2:
		printf("Enter a town name: \n");
		scanf("%s", inp, 20);
		printf("input is is: %s \n", inp);
	  find_index1(arrs, length, inp);

		break;

	case 3:
		printf("Program closing.");
		break;
	default:
		printf("not a valid option");
	}

	getchar();


}
