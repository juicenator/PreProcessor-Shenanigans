#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"
#include "toggle.h"

int main(){	
	//Open the file
	FILE *fp;
	fp = fopen("./program/defines.h", "r+");
	if(fp == NULL){
		fprintf(stderr, "Could not open defines.h, shutting down");
		exit(-1);
	}
	
	toggle_definition(fp, "ONE");
	
	exit(0); //Exit 0 stops the "compile loop"
	exit(1); //Exit 1 recompiles and runs.
}
