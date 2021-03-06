#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

int size_of_string(char * string, const int max_size);
int find_definition(FILE *fp, const char * find_string);
int toggle_definition(const char *def_file_name, const char * definition);


//set_to = 1. Turn the definition on
//set_to = 0. Turn the definition off
int set_definition(const char *def_file_name, const char * definition, int set_to){
	int defined = 1;

	//Open file
	FILE *fp = fopen(def_file_name, "r+");
	if(fp == NULL){
		fprintf(stderr, "Could not open the file with definitions.\n");
		return -1;
	}
	
	//Find the definition
	if(find_definition(fp, definition) != 0){
		fprintf(stderr, "Couldn't find a definition, the definitions file might be broken!\n");
		return -1;
	}
	
	//Check if it is already defined.
	if(fgetc(fp) == '/'){
		defined = 0;
	}
	
	fclose(fp);
	
	if(defined == set_to){
		return 0;
	}else{
		if(toggle_definition(def_file_name, definition) == 0){
			return 0;
		}else{
			return -1;
		}
	}
}





//Returns 0 on success. Error handling sucks though.
int toggle_definition(const char *def_file_name, const char * definition){ 
	char *buffer_text;
	int length_file;
	int defined = 1;
	int start_of_line = -1;
	
	//Open file
	FILE *fp = fopen(def_file_name, "r+");
	if(fp == NULL){
		fprintf(stderr, "Could not open the file with definitions.\n");
		return 1;
	}
	
	//Find the definition
	if(find_definition(fp, definition) != 0){
		fprintf(stderr, "Couldn't find a definition, the definitions file might be broken!\n");
		return -1;
	}
	
	//Check if it is already defined.
	if(fgetc(fp) == '/'){
		defined = 0;
	}
	
	//Start of the line
	fseek(fp, -1, SEEK_CUR);
	start_of_line = (int) ftell(fp);
	
	//Check the size of the file.
	fseek (fp, 0, SEEK_END);
	length_file = ftell (fp);
	fseek (fp, 0, SEEK_SET);
	
	//Set the length_file to the length AFTER our little edit.
	if(defined == 1){
		length_file = length_file+2;
	}else{
		length_file = length_file-2;
	}
	
	buffer_text = malloc (length_file);
	if(!buffer_text){
		fprintf(stderr, "Could not create a buffer for the text\n");
		return -1;
	}
	
	const char slash = '/';
	
	//Write the file to a buffer and add/remove the slashes.
	rewind(fp);
	if(defined == 0){ //Remove slashes
		fread(buffer_text, 1, start_of_line, fp);
		fseek(fp, 2, SEEK_CUR);
		fread(buffer_text+start_of_line, 1, length_file-(start_of_line), fp);
	}else{ //Add slashes
		fread(buffer_text, 1, start_of_line, fp);	
		memcpy(buffer_text + start_of_line, &slash, sizeof(slash));
		memcpy(buffer_text + start_of_line + 1, &slash, sizeof(slash));
		fread(buffer_text+start_of_line+2, 1, length_file-(start_of_line-2), fp);
	}

	//Write it to our defines file.
	fclose(fp);
	fp = fopen(def_file_name, "w");
	if(fp == NULL){
		fprintf(stderr, "Could not open the file with definitions.\n");
		return 1;
	}
	fwrite(buffer_text, 1, length_file, fp);
	
	fclose(fp);
	
	free(buffer_text);
	
	return 0;
}


//Helper function for toggle_definition(...). Returns the size of a char * till the first \0.
int size_of_string(char * string, const int max_size){
	int pos = 0;
	while(pos < max_size){
		if(string[pos] == '\0'){
			return pos;
		}
		pos++;
	}
	return -1;
}

//Helper function for toggle_definition(...). Find the place of find_string. Returns 0 on success.
//fp will be at the start of the line of this definition.
int find_definition(FILE *fp, const char * find_string){
	int length;
	char def_1[BUFFER_SIZE], def_2[BUFFER_SIZE];
	while(fscanf(fp, "%s %s", def_1, def_2) > 0){
		if(strcmp(def_2, find_string) == 0){
			length = size_of_string(def_1, BUFFER_SIZE) + size_of_string(def_2, BUFFER_SIZE) + 1;
			fseek(fp, -length, SEEK_CUR);
			return 0;
		}
	}
	return -1;
}
